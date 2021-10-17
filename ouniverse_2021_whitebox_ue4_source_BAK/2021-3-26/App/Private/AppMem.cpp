// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMem.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"
#include "AppMemInitializer.h"
#include "Mem/PlaythroughMem.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Story.h"
#include "Playthrough.h"
#include "StoryKeys.h"
#include "Party.h"
#include "Companion.h"
#include "CompanionKeys.h"

namespace Global
{
	AAppMem* AppMem;
}

AAppMem::AAppMem()
{
	bReplicates = true;
	bAlwaysRelevant = true;
}

AAppMem::~AAppMem()
{

}

void AAppMem::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAppMem, Mem);
}

AAppMem* AAppMem::GetAppMem()
{
	return Global::AppMem;
}

void AAppMem::GetAppMemBP(AAppMem*& AppMem)
{
	AppMem = AAppMem::GetAppMem();
}

void AAppMem::GetPlaythroughBP(UPlaythrough*& Playthrough)
{
	Playthrough = Global::AppMem->Playthrough;
}


FMemState* AAppMem::GetMemPtr()
{
	return &Mem;
}

void AAppMem::BeginPlay()
{
	Super::BeginPlay();

	Global::AppMem = this;
	if (AppMemInitializerClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "AppMemInitializerClass is not set in AppMem");
		return;
	}
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AAppMem::BeginPlayFD, 0.01f, false);
}

void AAppMem::BeginPlayFD()
{
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(AppMemInitializerClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AAppMem::GetInitializerLL));

}

void AAppMem::GetInitializerLL()
{
	ADI = NewObject<UAppMemInitializer>(this, AppMemInitializerClass.Get());

	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	TArray<FSoftObjectPath> ClassesToStream;

	ClassesToStream.AddUnique(ADI->PlaythroughClass.ToSoftObjectPath());
	ClassesToStream.AddUnique(ADI->PartyClass.ToSoftObjectPath());

	ClassesToStream.AddUnique(ADI->StoryPrimaryClass.ToSoftObjectPath());
	ClassesToStream.AddUnique(ADI->CompanionFioneClass.ToSoftObjectPath());
	ClassesToStream.AddUnique(ADI->CompanionMishaClass.ToSoftObjectPath());
	Streamable.RequestAsyncLoad(ClassesToStream, FStreamableDelegate::CreateUObject(this, &AAppMem::InitializeLL));
}


void AAppMem::InitializeLL()
{
	if (!ADI->PlaythroughClass.IsValid()) { FailInit(); return; }
	if (!ADI->PartyClass.IsValid()) { FailInit(); return; }

	Playthrough = NewObject<UPlaythrough>(this, ADI->PlaythroughClass.Get());
	UStory* Story;
	if (!InitStory(UStoryKeys::Primary, ADI->StoryPrimaryClass, Story)) { return; }

	UCompanion* Companion;
	if (!InitCompanion(UCompanionKeys::Fione, ADI->CompanionFioneClass, Story, Companion)) { return; }
	if (!InitCompanion(UCompanionKeys::Misha, ADI->CompanionMishaClass, Story, Companion)) { return; }

	ConcludeMemOverwrite();
	OnInitComplete.Broadcast();
}

bool AAppMem::InitStory(int Key, TSoftClassPtr<UStory> StoryClass, UStory*& Story)
{
	if (!StoryClass.IsValid())
	{
		FailInit();
		return false;
	}

	Mem.Playthrough.AddStoryMem(Key);
	Story = NewObject<UStory>(this, StoryClass.Get());
	Story->SetKey(Key);
	Story->Party = NewObject<UParty>(this, ADI->PartyClass.Get());
	Story->Party->Init();
	Story->Init();
	Playthrough->AddStory(Story);
	return true;
}

bool AAppMem::InitCompanion(int Key, TSoftClassPtr<UCompanion> CompanionClass, UStory* Story, UCompanion*& Companion)
{
	if (!CompanionClass.IsValid())
	{
		FailInit();
		return false;
	}

	Companion = NewObject<UCompanion>(this, CompanionClass.Get());
	Companion->SetKey(Key);
	AddCompanion(Companion);
	Story->AddCompanion(Companion);
	Companion->SetStory(Story);
	Mem.Playthrough.AddCompanionMem(Key);
	return true;
}

void AAppMem::ConcludeMemOverwrite()
{
	Playthrough->SetMem(&Mem.Playthrough);

	for (const TPair<int, UStory* >& Pair : Playthrough->Stories)
	{
		Pair.Value->SetMem(Mem.Playthrough.GetStoryMem(Pair.Key));
	}

	for (const TPair<int, UCompanion* >& Pair : Companions)
	{
		Pair.Value->SetMem(Mem.Playthrough.GetCompanionMem(Pair.Key));
	}
}

void AAppMem::FailInit()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Init Failed");
}






TSoftObjectPtr<UWorld> AAppMem::GetMap(FName Key)
{
	if (Maps.Contains(Key))
	{
		return Maps.FindRef(Key);
	}
	else
	{
		AAppMem::FailFlagLookup(Key, EMemFlagTypes::EMemFlagTypesMap);
		return NULL;
	}
}

void AAppMem::AddCompanion(UCompanion* Companion)
{
	Companions.Add(Companion->Key, Companion);
}

UCompanion* AAppMem::GetCompanion(int CompanionKey)
{
	return Companions.FindRef(CompanionKey);
}

void AAppMem::GetCompanionBP(int Key, UCompanion*& Companion)
{
	Companion = AAppMem::GetAppMem()->GetCompanion(Key);
}




void AAppMem::GetBoolBP(FName Key, EYesNo& Execs)
{
	Execs = EYesNo::No;

	AAppMem* AppMem = AAppMem::GetAppMem();

	bool* bool_ptr = AppMem->Mem.Bools.Find(Key);

	
	if (bool_ptr == nullptr)
	{
		AAppMem::FailFlagLookup(Key, EMemFlagTypes::EMemFlagTypesBool);
	}
	else
	{
		if (*bool_ptr == true)
		{
			Execs = EYesNo::Yes;
		}
	}
}

void AAppMem::SetBoolBP(FName Key, bool Value)
{
	AAppMem* AppMem = AAppMem::GetAppMem();
	bool* bool_ptr = AppMem->Mem.Bools.Find(Key);

	if (bool_ptr == nullptr)
	{
		AAppMem::FailFlagLookup(Key, EMemFlagTypes::EMemFlagTypesBool);
	}
	else
	{
		*bool_ptr = Value;
	}
}

void AAppMem::SetBoolTrueBP(FName Key)
{
	AAppMem::SetBoolBP(Key, true);
}

void AAppMem::SetBoolFalseBP(FName Key)
{
	AAppMem::SetBoolBP(Key, false);
}

void AAppMem::FailFlagLookup(FName Key, TEnumAsByte<EMemFlagTypes> FlagType)
{
	FString Type;
	switch (FlagType) {
	case EMemFlagTypes::EMemFlagTypesBool:
		Type = "Bool";
		break;
	case EMemFlagTypes::EMemFlagTypesByte:
		Type = "Byte";
		break;
	case EMemFlagTypes::EMemFlagTypesInt:
		Type = "Int";
		break;
	case EMemFlagTypes::EMemFlagTypesFloat:
		Type = "Float";
		break;
	case EMemFlagTypes::EMemFlagTypesString:
		Type = "String";
		break;
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Flag Lookup Failed ("+Type+"): "+Key.ToString());
}
