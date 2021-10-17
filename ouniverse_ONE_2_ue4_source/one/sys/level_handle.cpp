// Fill out your copyright notice in the Description page of Project Settings.

#include "level_handle.h"
#include "../sys/level_streamed.h"





ULevelHandle::ULevelHandle()
{
	StreamedDynamic = nullptr;
	StreamedLevel = nullptr;
	bLoaded = false;
}

void ULevelHandle::InputCommand()
{

}

//ULevelHandle* ULevelHandle::CreateLevelHandle(TSubClassOf<ULevelHandle> Class, TSoftObjectPtr<UWorld> InSoftLevel, FName InID, AProtocol_P* InOwningProtocol, UObject* WorldCTX)
ULevelHandle* ULevelHandle::CreateLevelHandle(TSubclassOf<ULevelHandle> InClass, TSoftObjectPtr<UWorld> InSoftLevel, FName InID, AProtocol_P* InOwningProtocol, UObject* WorldCTX)
{
	ULevelHandle* N = NewObject<ULevelHandle>(WorldCTX, InClass.Get());
	N->ID = InID;
	N->SoftLevel = InSoftLevel;
	N->OwningProtocol = InOwningProtocol;
	return N;
}

void ULevelHandle::Stream()
{
	bool bFound;
	StreamedDynamic = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(OwningProtocol, SoftLevel, FVector(0.0f), FRotator(0.0f), bFound);
	StreamedDynamic->OnLevelLoaded.AddDynamic(this, &ULevelHandle::LevelStreamedComplete);
}

void ULevelHandle::Unstream()
{
	StreamedDynamic->SetShouldBeLoaded(false);
	StreamedDynamic->OnLevelUnloaded.AddDynamic(this, &ULevelHandle::LevelUnstreamedComplete);
	OnLevelUnstreamed.Broadcast(ID);
}

void ULevelHandle::LevelStreamedComplete()
{
	StreamedLevel = Cast<ALevelStreamed>(StreamedDynamic->GetLevelScriptActor());
	if (StreamedLevel == nullptr)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Massive Error: A streamed level was not correctly set to inherit from ALevelStreamed!"));
	}
	else
	{
		StreamedLevel->Protocol = OwningProtocol;
		StreamedLevel->Proxy = this;
		StreamedLevel->ID = ID;
		OnLevelStreamed.Broadcast(ID);
	}
}

void ULevelHandle::LevelUnstreamedComplete()
{

}