// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyHandle.h"
#include "Task/Tasks.h"
#include "Task/CompanionLoadTask.h"

void UPartyHandle::Load(FParty* InParty)
{
	Party = InParty;

	PartyMemberPtrs.Add(&Party->PartyMember1);
	PartyMemberPtrs.Add(&Party->PartyMember2);
	PartyMemberPtrs.Add(&Party->PartyMember3);
	PartyMemberPtrs.Add(&Party->PartyMember4);

	int L = PartyMemberPtrs.Len();
	
	LoadPartyTask = NewObject<UTasks>(this, UTasks::StaticClass());

	for (int i = 0; i < L; i++)
	{
		FPartyMember* Member = PartyMemberPtrs[i];
		if (Member->Companion != NULL)
		{
			UCompanionLoadTask* LoadCompanion = NewObject<UCompanionLoadTask>(this, UCompanionLoadTask::StaticClass());
			LoadCompanion->Setup(Member->Companion);
			LoadPartyTask->Add(LoadCompanion);
		}
	}

	LoadPartyTask->OnComplete.AddDynamic(this, &UPartyHandle::LoadComplete);
	LoadPartyTask->Go();
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