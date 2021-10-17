// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyMemberHandle.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "CompanionActor.h"
#include "Companion.h"

void UPartyMemberHandle_Task_CompanionA::Setup(UPartyMemberHandle* InPartyMemberHandle)
{
	PartyMemberHandle = InPartyMemberHandle;

}


void UPartyMemberHandle_Task_CompanionA::Go()
{
	UCompanion* Companion = PartyMemberHandle->GetCompanion();
	if (Companion->CompanionActorClass.IsValid())
	{
		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoFail = true;
		PartyMemberHandle->CompanionA = GetWorld()->SpawnActor<ACompanionActor>(Companion->CompanionActorClass.Get(), Location, Rotation, SpawnInfo);
		PartyMemberHandle->CompanionA->OnBecomeComplete.AddDynamic(this, &UPartyMemberHandle_Task_CompanionA::Complete);
		PartyMemberHandle->CompanionA->Become(Companion);
	}
	else if (Companion->CompanionActorClass.IsNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "A Companion CompainonActor class is NULL");
	}
	else
	{
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(Companion->CompanionActorClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UPartyMemberHandle_Task_CompanionA::Go));
	}
}


void UPartyMemberHandle::Init(FPartyMember* InPartyMember)
{
	PartyMember = InPartyMember;
}

bool UPartyMemberHandle::HasCompanion()
{
	if (PartyMember->IsEmpty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

UCompanion* UPartyMemberHandle::GetCompanion()
{
	return PartyMember->Companion;
}


UPartyMemberHandle_Task_CompanionA* UPartyMemberHandle::BeCompanionA()
{
	UPartyMemberHandle_Task_CompanionA* Task = NewObject<UPartyMemberHandle_Task_CompanionA>(this, UPartyMemberHandle_Task_CompanionA::StaticClass());
	Task->Setup(this);
	return Task;
}

