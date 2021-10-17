// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "AppInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Logic.h"
#include "SoftServe.h"
#include "AppRemote.h"

namespace Global
{
	AAppMode* AppMode = NULL;
}

AAppMode::AAppMode()
{
	Global::AppMode = this;
}

AAppMode* AAppMode::Get()
{
	return Global::AppMode;
}

AAppMode* AAppMode::GetAppMode(const UObject* WorldContextObject)
{
	return Cast<AAppMode>(WorldContextObject->GetWorld()->GetAuthGameMode());
}

void AAppMode::BeginPlay()
{

	Log.SetID("AppMode");
	App = UApp::Get();
	Super::BeginPlay();
}

void AAppMode::Boot()
{	


	SS = NewObject<USoftServe>(this, USoftServe::StaticClass());

	if(SS->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Manager SoftClass is not correctly set in AppMode");
		Log.Write(AAUTH,LCRIT,VNONE,1,0, "A Manager SoftClass was not correctly set.");
		return;
	}

	SS->OnComplete.AddDynamic(this,&AAppMode::Boot_SS);
	SS->Stream();

}

void AAppMode::Boot_SS(USoftServe* SoftServe)
{
	Log.Write(AAUTH,LNORM,VNONE,1,0, "Boot Lazy Load Started. SoftClasses have been Async Loaded.");


	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;

	AppRemote = GetWorld()->SpawnActor<AAppRemote>(AAppRemote::StaticClass(), Location, Rotation, SpawnInfo);

	
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "BootCompleted()");
	//WorldRemote->EnterWorld();
	SS = NULL;
}


ULogic* AAppMode::DoLogic(TSubclassOf<ULogic> Logic)
{
	ULogic* RunLogic = NewObject<ULogic>(this, Logic);
	RunLogic->DoLogic();
	return RunLogic;
}