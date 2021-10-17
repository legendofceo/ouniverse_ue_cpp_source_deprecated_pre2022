// Fill out your copyright notice in the Description page of Project Settings.

//O:\ouniverse\ouniverse\SourceMVS\include

#include "Boot.h"
#include "Kismet/GameplayStatics.h"

#include "Major.h"

#include "Engine/World.h"

#include "ProgramState.h"
#include "GameInstanceUE.h"
#include "ControlUE.h"
#include "HudUE.h"
#include "Scope.h"
#include "Cam.h"
#include "Party.h"
#include "Exec.h"
#include "Space.h"
#include "Ui.h"
#include "Reg.h"
#include "Localization.h"
#include "Director.h"

#include "ViewportUE.h"

#include "Data.h"
#include "../Data/InventoryData.h"
#include "../Data/BeastData.h"
#include "../Data/FlagData.h"
#include "../Data/HeroData.h"
#include "../Data/InventoryData.h"
#include "../Data/RecordData.h"
#include "../Data/SettingsData.h"

namespace GlobalVars
{
	EBootMethod BootMethod;
}

namespace GlobalSingleton
{
	BootC gBoot;
}

BootC* BootC::Get()
{
	return &GlobalSingleton::gBoot;
}

BootC* BootC::Create(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	GlobalSingleton::gBoot = *(new BootC(InBootMethod, WorldContextObject));
	return &GlobalSingleton::gBoot;
}

void UBoot::Boot(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	BootC::Create(InBootMethod, WorldContextObject);
}


BootC::BootC(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	BootMethod_ = InBootMethod;
	GlobalVars::BootMethod = InBootMethod;

	switch (InBootMethod) {
	case EBootMethod::Standard:
		Standard(WorldContextObject);
		break;
	}
}


void BootC::Standard(UObject* WorldContextObject)
{


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Standard Boot"));

	if (!GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("No GEngine"));
		return;
	}

	UObject* WorldContextObject_PRE = WorldContextObject;
	UWorld* Scope_PRE = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	UGameInstanceUE* Singleton = Cast<UGameInstanceUE>(Scope_PRE->GetGameInstance());

	if (!Singleton)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("GameInstance was not set to UGameInstanceUE."));
		return;
	}

	
	UMajor* M = UMajor::Create();
	
	Singleton->Major_ = M;
	
    M->Scope_ = new ScopeC(WorldContextObject_PRE, Scope_PRE);

	UReg::Initialize();

	M->Director_ = UDirector::Create(&UReg::Get()->ActMap_);

	M->Localization_ = ULocalization::Create();

	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(ScopeC::World()->GetGameInstance()->GetGameViewportClient());

	M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));

	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());

	M->Ui_ = UUi::Create();

	

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	ScopeC::World()->SpawnActor<ACam>(Location, Rotation);
	
	
	M->Exec_ = UExec::Create();
	M->Control_->Init(M->Exec());

	
	M->Space_ = USpace::Create();


	M->Data_ = UData::Create();
	M->Data_->NewGame();

	M->Party_ = PartyC::Create();


	
	

	M->Exec_->Start();

	//M->Party->SetActiveMember(0);
	//M->Party->SpawnParty();

	//M->Space()->LoadArea("TestLevel");
}