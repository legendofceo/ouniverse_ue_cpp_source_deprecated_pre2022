// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAnimNode.h"
#include "Animation/AnimInstanceProxy.h"




FMyAnimNode::FMyAnimNode()
{
}




void FMyAnimNode::RefreshMeshComponent(USkeletalMeshComponent* TargetMeshComponent)
{
	auto ResetMeshComponent = [this](USkeletalMeshComponent* InMeshComponent, USkeletalMeshComponent* InTargetMeshComponent)
	{
		USkeletalMeshComponent* CurrentMeshComponent = CurrentlyUsedSourceMeshComponent.Get();
		// if current mesh exists, but not same as input mesh
		if (CurrentMeshComponent)
		{
			// if component has been changed, reinitialize
			if (CurrentMeshComponent != InMeshComponent)
			{
				ReinitializeMeshComponent(InMeshComponent, InTargetMeshComponent);
			}
			// if component is still same but mesh has been changed, we have to reinitialize
			else if (CurrentMeshComponent->SkeletalMesh != CurrentlyUsedSourceMesh.Get())
			{
				ReinitializeMeshComponent(InMeshComponent, InTargetMeshComponent);
			}
			else if (InTargetMeshComponent)
			{
				// see if target mesh has changed
				if (InTargetMeshComponent->SkeletalMesh != CurrentlyUsedTargetMesh.Get())
				{
					ReinitializeMeshComponent(InMeshComponent, InTargetMeshComponent);
				}
			}
		}
		// if not valid, but input mesh is
		else if (!CurrentMeshComponent && InMeshComponent)
		{
			ReinitializeMeshComponent(InMeshComponent, InTargetMeshComponent);
		}
	};

	if (SourceMeshComponent.IsValid())
	{
		ResetMeshComponent(SourceMeshComponent.Get(), TargetMeshComponent);
	}
	/**
	else if (bUseAttachedParent)
	{
		if (TargetMeshComponent)
		{
			USkeletalMeshComponent* ParentComponent = Cast<USkeletalMeshComponent>(TargetMeshComponent->GetAttachParent());
			if (ParentComponent)
			{
				ResetMeshComponent(ParentComponent, TargetMeshComponent);
			}
			else
			{
				CurrentlyUsedSourceMeshComponent.Reset();
			}
		}
		else
		{
			CurrentlyUsedSourceMeshComponent.Reset();
		}
	}
	*/
	else
	{
		CurrentlyUsedSourceMeshComponent.Reset();
	}
}



void FMyAnimNode::PreUpdate(const UAnimInstance* InAnimInstance)
{
	QUICK_SCOPE_CYCLE_COUNTER(FAnimNode_CopyPoseFromMesh_PreUpdate);

	RefreshMeshComponent(InAnimInstance->GetSkelMeshComponent());

	USkeletalMeshComponent* CurrentMeshComponent = CurrentlyUsedSourceMeshComponent.IsValid() ? CurrentlyUsedSourceMeshComponent.Get() : nullptr;

	if (CurrentMeshComponent && CurrentMeshComponent->SkeletalMesh && CurrentMeshComponent->IsRegistered())
	{
		// If our source is running under master-pose, then get bone data from there
		if (USkeletalMeshComponent* MasterPoseComponent = Cast<USkeletalMeshComponent>(CurrentMeshComponent->MasterPoseComponent.Get()))
		{
			CurrentMeshComponent = MasterPoseComponent;
		}

		// re-check mesh component validity as it may have changed to master
		if (CurrentMeshComponent->SkeletalMesh && CurrentMeshComponent->IsRegistered())
		{
			const bool bUROInSync = CurrentMeshComponent->ShouldUseUpdateRateOptimizations() && CurrentMeshComponent->AnimUpdateRateParams != nullptr && CurrentMeshComponent->AnimUpdateRateParams == InAnimInstance->GetSkelMeshComponent()->AnimUpdateRateParams;
			const bool bUsingExternalInterpolation = CurrentMeshComponent->IsUsingExternalInterpolation();
			const TArray<FTransform>& CachedComponentSpaceTransforms = CurrentMeshComponent->GetCachedComponentSpaceTransforms();
			const bool bArraySizesMatch = CachedComponentSpaceTransforms.Num() == CurrentMeshComponent->GetComponentSpaceTransforms().Num();

			// Copy source array from the appropriate location
			SourceMeshTransformArray.Reset();
			SourceMeshTransformArray.Append((bUROInSync || bUsingExternalInterpolation) && bArraySizesMatch ? CachedComponentSpaceTransforms : CurrentMeshComponent->GetComponentSpaceTransforms());

			// Ref skeleton is need for parent index lookups later, so store it now
			CurrentlyUsedMesh = CurrentMeshComponent->SkeletalMesh;
		}
		else
		{
			CurrentlyUsedMesh.Reset();
		}
	}
}



void FMyAnimNode::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Initialize_AnyThread)
	FAnimNode_Base::Initialize_AnyThread(Context);

	// Initial update of the node, so we dont have a frame-delay on setup
	GetEvaluateGraphExposedInputs().Execute(Context);
}

void FMyAnimNode::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(CacheBones_AnyThread)
	///InputPose.CacheBones(Context);
}

void FMyAnimNode::Update_AnyThread(const FAnimationUpdateContext& Context)
{

	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Update_AnyThread)
	// This introduces a frame of latency in setting the pin-driven source component,
	// but we cannot do the work to extract transforms on a worker thread as it is not thread safe.

	GetEvaluateGraphExposedInputs().Execute(Context);
	//InputPose.Update(Context);
}


void FMyAnimNode::Evaluate_AnyThread(FPoseContext& Output)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Evaluate_AnyThread)
	FCompactPose& OutPose = Output.Pose;
	OutPose.ResetToRefPose();
	USkeletalMesh* CurrentMesh = CurrentlyUsedMesh.IsValid() ? CurrentlyUsedMesh.Get() : nullptr;
	if (SourceMeshTransformArray.Num() > 0 && CurrentMesh)
	{

		if (SourceMeshTransformArray.Num() > 0)
		{
			const FBoneContainer& RequiredBones = OutPose.GetBoneContainer();


			for (FCompactPoseBoneIndex PoseBoneIndex : OutPose.ForEachBoneIndex())
			{
				const int32 SkeletonBoneIndex = RequiredBones.GetSkeletonIndex(PoseBoneIndex);
				const int32 MeshBoneIndex = RequiredBones.GetSkeletonToPoseBoneIndexArray()[SkeletonBoneIndex];
				const int32* Value = BoneMapToSource.Find(MeshBoneIndex);
				if (Value && SourceMeshTransformArray.IsValidIndex(*Value))
				{
					const int32 SourceBoneIndex = *Value;
					const int32 ParentIndex = CurrentMesh->GetRefSkeleton().GetParentIndex(SourceBoneIndex);
					const FCompactPoseBoneIndex MyParentIndex = RequiredBones.GetParentBoneIndex(PoseBoneIndex);
					// only apply if I also have parent, otherwise, it should apply the space bases
					if (SourceMeshTransformArray.IsValidIndex(ParentIndex) && MyParentIndex != INDEX_NONE)
					{
						const FTransform& ParentTransform = SourceMeshTransformArray[ParentIndex];
						const FTransform& ChildTransform = SourceMeshTransformArray[SourceBoneIndex];
						OutPose[PoseBoneIndex] = ChildTransform.GetRelativeTransform(ParentTransform);
					}
					else
					{
						OutPose[PoseBoneIndex] = SourceMeshTransformArray[SourceBoneIndex];
					}
				}
			}
		}
	}

	// Evaluate the input
	//Output.AnimInstance->CurrentSkeleton;

	//InputPose.Evaluate(Output);
}

void FMyAnimNode::GatherDebugData(FNodeDebugData& DebugData)
{
	FString DebugLine = DebugData.GetNodeName(this);

	DebugData.AddDebugItem(DebugLine);

	//InputPose.GatherDebugData(DebugData);
}



void FMyAnimNode::ReinitializeMeshComponent(USkeletalMeshComponent* NewSourceMeshComponent, USkeletalMeshComponent* TargetMeshComponent)
{
	CurrentlyUsedSourceMeshComponent.Reset();
	// reset source mesh
	CurrentlyUsedSourceMesh.Reset();
	CurrentlyUsedTargetMesh.Reset();
	BoneMapToSource.Reset();


	if (TargetMeshComponent && NewSourceMeshComponent && NewSourceMeshComponent->SkeletalMesh && !NewSourceMeshComponent->IsPendingKill())
	{
		USkeletalMesh* SourceSkelMesh = NewSourceMeshComponent->SkeletalMesh;
		USkeletalMesh* TargetSkelMesh = TargetMeshComponent->SkeletalMesh;

		if (SourceSkelMesh && !SourceSkelMesh->IsPendingKill() && !SourceSkelMesh->HasAnyFlags(RF_NeedPostLoad) &&
			TargetSkelMesh && !TargetSkelMesh->IsPendingKill() && !TargetSkelMesh->HasAnyFlags(RF_NeedPostLoad))
		{
			CurrentlyUsedSourceMeshComponent = NewSourceMeshComponent;
			CurrentlyUsedSourceMesh = SourceSkelMesh;
			CurrentlyUsedTargetMesh = TargetSkelMesh;

			if (SourceSkelMesh == TargetSkelMesh)
			{
				for (int32 ComponentSpaceBoneId = 0; ComponentSpaceBoneId < SourceSkelMesh->GetRefSkeleton().GetNum(); ++ComponentSpaceBoneId)
				{
					BoneMapToSource.Add(ComponentSpaceBoneId, ComponentSpaceBoneId);
				}
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Skel Is Valid");

				for (int32 i = 0; i < TargetSkelMesh->GetRefSkeleton().GetNum(); ++i)
				{
					//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, SourceSkelMesh->RefSkeleton.GetBoneName(i).ToString());
					//BoneMapToSource.Add(ComponentSpaceBoneId, ComponentSpaceBoneId);

					int32 BoneIndex = SourceSkelMesh->GetRefSkeleton().FindBoneIndex(TargetSkelMesh->GetRefSkeleton().GetBoneName(i));

					if (BoneIndex != INDEX_NONE)
					{
						BoneMapToSource.Add(i, BoneIndex);
					}
				}

			}
		}
	}
}
