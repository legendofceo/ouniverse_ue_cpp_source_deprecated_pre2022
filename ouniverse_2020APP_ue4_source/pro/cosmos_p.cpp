// Fill out your copyright notice in the Description page of Project Settings.

#include "cosmos_p.h"

#include "Kismet/GameplayStatics.h"

#include "../sys/gameinstance_ue.h"
#include "../sys/viewport_ue.h"
#include "../sys/hud_ue.h"

#include "../sys/file_manager.h"
#include "../sys/ico_manager.h"
#include "../sys/translation_manager.h"
#include "../sys/user_manager.h"


//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));

namespace Global
{
	ACosmos_P* ProtocolCosmos;
}

ACosmos_P::ACosmos_P() : AProtocol_P()
{
	bPreDataLoaded = false;
}

ACosmos_P* ACosmos_P::GetCosmos()
{
	return Global::ProtocolCosmos;
}

ACosmos_P* ACosmos_P::Get()
{
	return Global::ProtocolCosmos;
}


void ACosmos_P::BigBang(TEnumAsByte<EBootCMD> InBootCommand, 
						TSoftClassPtr<UIcoManager> IcoManagerClass,
						UObject* WorldCTX, bool bSkipIntros, FString AutoUserID, FString AutoLoadout)
{
	UWorld* World = this->GetWorld();
	Global::ProtocolCosmos = this;
	Cosmos = this;

	PlatformName = UGameplayStatics::GetPlatformName();

	if (!GEngine)
	{
		//Log.Write("No GEngine - Boot Abandoned.", ELogStatus::Critical);
		return;
	}

	UGameInstanceUE* Singleton = Cast<UGameInstanceUE>(World->GetGameInstance());

	if (!Singleton)
	{
		//Log.Write("GameInstance was not set to UGameInstanceUE - Boot Abandoned.", ELogStatus::Critical);
		return;
	}

	
	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	Viewport = Cast<UViewportUE>(World->GetGameInstance()->GetGameViewportClient());
	Viewport->SetForceDisableSplitscreen(true);
	Hud = AHudUE::Get(this);


	FileManager = AFileManager::Create(this);
	//LocalizationManager = ULocalizationManager::Create(LocalizationManagerClass, this);
	//LocalizationManager->SetLocalization("default");
	TranslationManager = UTranslationManager::Create();
	UserManager = AUserManager::Create(this);
	IcoManager = UIcoManager::Create(IcoManagerClass, this);


	//Attach(Control);

	Attach(Hud);

	Attach(FileManager);
	Attach(UserManager);
	
	//Log.Write("Boot Complete.", ELogStatus::Expected);

	/**

	
	M->Scope_ = PreScope;

	M->Ui_ = AUi::Create(this);
	M->Exec_ = AExec::Create(this);

	M->DataManager_ = ADataManager::Create(this);
	M->AreaManager_ = AAreaManager::Create(this);
	M->Data_ = AData::Create();
	M->Party_ = AParty::Create();
	M->Music_ = AMusic::Create();
	M->WeatherManager_ = AWeatherManager::Create();

	M->Attach(this);
	M->Attach(M->Mode());
	M->Attach(M->Hud());

	M->Attach(M->Ui());
	M->Attach(M->Scope());
	M->Attach(M->AreaManager());
	M->Attach(M->DataManager());
	M->Attach(M->LogManager());
	M->Attach(M->Exec());
	M->Attach(M->Data());
	M->Attach(M->Party());
	M->Attach(M->Music());
	M->Attach(M->WeatherManager());
	//Start First Scene
	M->Data()->NewGame();
	//FCosmAddress("splash_screens", "begin").Go();

	FAreaAddress StartArea = FAreaAddress(FDataAddress(153, 12312));
	StartArea.SetCatalyst("LETSGO");
	M->AreaManager()->TravelToArea(StartArea);
	/**
		M->Director_ = UDirector::Create(&UReg::Get()->ActMap_);

		M->Localization_ = ULocalization::Create();

	*/
	
}

void ACosmos_P::LoadPreData()
{

	UTranslationManager::Get()->LoadBaseDictionary("English");

	//Global::ProtocolCosmos->DeepMemory->Load();

	if (!Global::ProtocolCosmos->UserManager->bUsersLoaded)
	{
		Global::ProtocolCosmos->UserManager->LoadUsers();
	}

	//Global::ProtocolCosmos->UserManager->AutoUser(Global::ProtocolCosmos->DeepMemory->LastUserUID);

	Global::ProtocolCosmos->bPreDataLoaded = true;
}


void ACosmos_P::PreDataStatus(bool& DataLoaded, bool& HasActiveUser, bool& HasAnyUser)
{

	HasActiveUser = Global::ProtocolCosmos->Cosmos->UserManager->HasActiveUser();
	HasAnyUser = Global::ProtocolCosmos->Cosmos->UserManager->HasAnyUser();
}