// Fill out your copyright notice in the Description page of Project Settings.


#include "ActraExHuman.h"
#include "Log.h"
#include "Viz.h"
#include "Chassis.h"
#include "BodyMemHuman.h"
#include "ActraMemHuman.h"
#include "BehaviorHuman.h"

AActraExHuman::AActraExHuman()
{

}

void AActraExHuman::BeginInit()
{
	Init_Steps(0);
}

void AActraExHuman::Init_Steps(int Step)
{

	FDelBasic Callback;
	Callback.BindUObject(this, &AActraExHuman::Init_Steps, Step+1);
	BehaviorHuman = NewObject<UBehaviorHuman>(this, UBehaviorHuman::StaticClass());
	BehaviorHuman->Init(this);

	switch (Step) {
	case 0:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("0!"));
		ActraMemHuman = Cast<UActraMemHuman>(ActraMem);
		ActraMemHuman->BodyMemHuman->StreamChassis(Callback);
		break;
	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("1!"));
		Chassis = ActraMemHuman->BodyMemHuman->GetChassis();
		Chassis->Init(this);
		Chassis->SetSkeletalMeshComponent(GetMesh());
		ActraMemHuman->VizRack->Stream(Callback);
		break;
	case 2:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("2!"));
		ActraMemHuman->VizRack->GetAllEx(VizExs);
		
		for (UVizEx* VizEx : VizExs)
		{
			VizEx->Init(this);
		}

		//BodyExHuman = NewObject<UBodyExHuman>(this, UBodyExHuman::StaticClass());
		//BodyExHuman->Init(ActraMemHuman->BodyMemHuman, Callback);
		InitComplete();
		break;
	case 3:
		
		break;
	}

}

void AActraExHuman::Connect()
{
	BehaviorHuman->Connect();
}