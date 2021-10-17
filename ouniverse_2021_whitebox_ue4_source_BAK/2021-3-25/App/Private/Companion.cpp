// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion.h"
#include "Mem/CompanionMem.h"
#include "CompanionActor.h"
#include "Party.h"
#include "Story.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void UCompanion::SetKey(int CompanionKey)
{
	Key = CompanionKey;
}

void UCompanion::SetMem(FCompanionMem* CompanionMem)
{
	Mem = CompanionMem;
}

void UCompanion::SetStory(UStory* InStory)
{
	Story = InStory;
}

UCompanion* UCompanion::Obtain()
{
	Mem->Obtained = true;
	return this;
}

void UCompanion::ObtainBP(UCompanion*& Companion)
{
	Companion = Obtain();
}


bool UCompanion::IsObtained()
{
	return Mem->Obtained;
}

void UCompanion::IsObtainedBP(EYesNo& Execs)
{
	if (Mem->Obtained)
	{
		Execs = EYesNo::Yes;
	}
	else
	{
		Execs = EYesNo::No;
	}
}

void UCompanion::JoinParty()
{
	Story->Party->AddPartyMember(this);
}

void UCompanion::JoinPartyBP(bool& Success, UCompanion*& CompanionR)
{
	JoinParty();
	CompanionR = this;
}

void UCompanion::EmbodyAsActra()
{
	if (EmbodyActraClass.IsNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Companion Actor Class was NULL: MKey: "+FString::FromInt(Key)+" (UCompanion::EmbodyActra)");
	}
	else if (EmbodyActraClass.IsValid())
	{
		EmbodyAsActraLL();
	}
	else
	{
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(EmbodyActraClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UCompanion::EmbodyAsActraLL));
	}
}

void UCompanion::EmbodyAsActraLL()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	EmbodyActra = GetWorld()->SpawnActor<ACompanionActor>(EmbodyActraClass.Get(), Location, Rotation, SpawnInfo);
	EmbodyActra->OnEmbodyComplete.AddDynamic(this, &UCompanion::EmbodyAsActraComplete);
	EmbodyActra->BeginEmbody(this);
	
}

void UCompanion::EmbodyAsActraComplete(ACompanionActor* Actra)
{
	EmbodyActra->OnEmbodyComplete.RemoveDynamic(this, &UCompanion::EmbodyAsActraComplete);
	OnActraEmbodyComplete.Broadcast(this, EmbodyActra);
}