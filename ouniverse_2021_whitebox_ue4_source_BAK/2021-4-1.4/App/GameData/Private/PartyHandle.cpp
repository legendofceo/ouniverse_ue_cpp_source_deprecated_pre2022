// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyHandle.h"
#include "PartyMemberHandle.h"
#include "Companion.h"
#include "Party.h"
#include "Task.h"

void UPartyHandle::Init(FParty* InParty)
{
	Party = InParty;

	PartyMaxSize = Party->PartyMembers.Num();

	UPartyMemberHandle* PM = NULL;

	for (int i = 0; i < PartyMaxSize; i++)
	{
		PM = NewObject<UPartyMemberHandle>(this, UPartyMemberHandle::StaticClass());
		PM->Init(&Party->PartyMembers[i]);
		PartyMembers.Add(PM);
	}

}

void UPartyHandle::BufferActra()
{
	for (UPartyMemberHandle* PM : PartyMembers)
	{
		PM->BeCompanionA();
	}

	/**
	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());

	int L = PartyMemberPtrs.Len();

	for (UPartyMemberHandle* PM : PartyMembers)
	{
		SoftServe->Add(PM->Companion->EmbodyActraClass);
	}

	if (SoftServe->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Companion Actra SoftClass is not set");
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &UPartyHandle::BufferActraPostSS);
	SoftServe->Stream();
	*/
}


void UPartyHandle::LoadComplete(UTask* Task)
{
	OnLoadComplete.Broadcast();
}

/**
if (Companion->EmbodyActraClass.IsValid())
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	ACompanionActor* Actor = GetWorld()->SpawnActor<ACompanionActor>(Companion->EmbodyActraClass.Get(), Location, Rotation, SpawnInfo);
	Actor->OnEmbodyComplete.AddDynamic(this, &UCompanionLoadTask::Complete);
	Actor->BeginEmbody(Companion);
}
else if (Companion->EmbodyActraClass.IsNull())
{
	//AAppMode::GetAppMode(this)->CompanionMng->Log.Write(LCRIT, VNONE, 0, 0, "A Companion Actor Class was NULL: MKey: " + FString::FromInt(Companion->Key) + " (UCompanionLoadTask::LoadLoop)");
}
else
{
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(Companion->EmbodyActraClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UCompanionLoadTask::Go));
}
*/