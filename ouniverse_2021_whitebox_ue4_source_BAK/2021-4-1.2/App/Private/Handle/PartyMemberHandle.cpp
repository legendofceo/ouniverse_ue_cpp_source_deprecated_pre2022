// Fill out your copyright notice in the Description page of Project Settings.


#include "Handle/PartyMemberHandle.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "CompanionActor.h"
#include "Mem/Companion.h"

void UPartyMemberHandle_Task_CompanionA::Setup(UPartyMemberHandle* InPartyMemberHandle)
{
	PartyMemberHandle = InPartyMemberHandle;
}


void UPartyMemberHandle_Task_CompanionA::Go()
{

	if (Companion->EmbodyActraClass.IsValid())
	{

		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoFail = true;
		PartyMemberHandle->CompanionA = GetWorld()->SpawnActor<ACompanionActor>(PartyMemberHandle->Companion->EmbodyActraClass.Get(), Location, Rotation, SpawnInfo);
		PartyMemberHandle->CompanionA->OnEmbodyComplete.AddDynamic(this, &UPartyMemberHandle_Task_CompanionA::Complete);
		PartyMemberHandle->CompanionA->BeginEmbody(Companion);
	}
	else if (Companion->EmbodyActraClass.IsNull())
	{
		//AAppMode::GetAppMode(this)->CompanionMng->Log.Write(LCRIT, VNONE, 0, 0, "A Companion Actor Class was NULL: MKey: " + FString::FromInt(Companion->Key) + " (UCompanionLoadTask::LoadLoop)");
	}
	else
	{

		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(Companion->EmbodyActraClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UPartyMemberHandle_Task_CompanionA::Go));
	}
}


void UPartyMemberHandle::Init(FPartyMember* InPartyMember)
{
	PartyMember = InPartyMember;
}

UPartyMemberHandle_Task_CompanionA* UPartyMemberHandle::BeCompanionA()
{
	UPartyMemberHandle_Task_CompanionA* Task = NewObject<UPartyMemberHandle_Task_CompanionA>(this, UPartyMemberHandle_Task_CompanionA::StaticClass());
	Task->Setup(this);
	return Task;
}