// Fill out your copyright notice in the Description page of Project Settings.


#include "ACM.h"
#include "APC.h"
#include "Actra.h"
#include "Camera/CameraComponent.h"



void UCamTweenPartyShift::Setup(APC* InPC, ACM* InACM, AActra* InNextMember, FTViewTarget OutVT, UCameraComponent* InTarget, float TotalTime)
{
	CM = InACM;
	PC = InPC;
	NextMember = InNextMember;

	Target = InTarget;
	StartPos = OutVT.POV.Location;
	StartRot = OutVT.POV.Rotation;
	StartFOV = OutVT.POV.FOV;

	TimeFactor = 1 / TotalTime;
}

void UCamTweenPartyShift::Tween(FTViewTarget& OutVT, float DeltaTime)
{

	if (!bComplete)
	{
		CurTime += DeltaTime;

		float TimeResult = CurTime * TimeFactor;
		float Alpha = CM->CurveCameraShift->GetFloatValue(TimeResult);

		if (Alpha >= 1.0)
		{
			bComplete = true;
			CM->Target = Target;
			CM->EndTween();
		}
		else
		{
			FTransform XForm = Target->GetComponentTransform();
			FVector Pos = XForm.GetTranslation();
			FRotator Rot = XForm.Rotator();
			OutVT.POV.Location = FMath::Lerp(StartPos, Pos, Alpha);
			OutVT.POV.Rotation = FMath::Lerp(StartRot, Rot, Alpha);
		}
	}
}

void ACM::ForceCameraTarget(UCameraComponent* InTarget)
{

	Target = InTarget;
	EndTween();

}

void ACM::RunTween(UCamTweenPartyShift* InActiveTween)
{
	bIsTweening = true;
	ActiveTween = InActiveTween;
}

void ACM::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{

	if (bIsTweening)
	{
		ActiveTween->Tween(OutVT,DeltaTime);
	}
	else if (IsValid(Target))
	{
		FTransform XForm = Target->GetComponentTransform();
		FVector Pos = XForm.GetTranslation();
		FRotator Rot = XForm.Rotator();

		OutVT.POV.Location = Pos;
		OutVT.POV.Rotation = Rot;
		OutVT.POV.FOV = 90;

	}
	else
	{
		OutVT.POV.Location = FVector(0, 0, 0);
		OutVT.POV.Rotation = FRotator(0, 0, 0);
		OutVT.POV.FOV = 90;
	}

	LastFrameVT = OutVT;
}


void ACM::EndTween()
{
	bIsTweening = false;
	ActiveTween = NULL;
}