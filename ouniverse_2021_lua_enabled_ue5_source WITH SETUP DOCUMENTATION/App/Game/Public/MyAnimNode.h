// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "MyAnimNode.generated.h"
/**
 *
 */

USTRUCT(BlueprintType)
struct APP_API FBoneList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FName> Bones;

	FBoneList()
	{
		Bones.Add("breast_r");
		Bones.Add("breast_l");
	}
};


USTRUCT(BlueprintInternalUseOnly)
struct APP_API FMyAnimNode : public FAnimNode_Base
{
	GENERATED_BODY()


public:


	UPROPERTY(BlueprintReadWrite, transient, Category = Mirror, meta = (PinShownByDefault))
	TWeakObjectPtr<USkeletalMeshComponent> SourceMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mirror, meta = (PinShownByDefault))
	FBoneList BoneList;

	USkeletalMeshComponent* ThisSkeleton;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	//FPoseLink InputPose;


public:
	FMyAnimNode();

	// FAnimNode_Base interface
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
	virtual bool HasPreUpdate() const override { return true; }
	virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	// End of FAnimNode_Base interface


	// this is source mesh references, so that we could compare and see if it has changed
	TWeakObjectPtr<USkeletalMeshComponent>	CurrentlyUsedSourceMeshComponent;
	TWeakObjectPtr<USkeletalMesh>			CurrentlyUsedSourceMesh;
	TWeakObjectPtr<USkeletalMesh>			CurrentlyUsedMesh;

	// target mesh 
	TWeakObjectPtr<USkeletalMesh>			CurrentlyUsedTargetMesh;
	// cache of target space bases to source space bases
	TMap<int32, int32> BoneMapToSource;

	// Cached transforms, copied on the game thread
	TArray<FTransform> SourceMeshTransformArray;

	// reinitialize mesh component 
	void ReinitializeMeshComponent(USkeletalMeshComponent* NewSkeletalMeshComponent, USkeletalMeshComponent* TargetMeshComponent);
	void RefreshMeshComponent(USkeletalMeshComponent* TargetMeshComponent);

};