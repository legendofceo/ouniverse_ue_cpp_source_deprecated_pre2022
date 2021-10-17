// Fill out your copyright notice in the Description page of Project Settings.


#include "SoftServe.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void USoftServe::Add(TSoftClassPtr<UObject> SCP)
{
	SoftClasses.Add(SCP);
}

void USoftServe::Add(TSoftObjectPtr<UObject> SOP)
{
	SoftObjects.Add(SOP);
}


void USoftServe::AddScpBP(TSoftObjectPtr<UObject> SCP)
{
	Add(SCP);
}

void USoftServe::AddSopBP(TSoftObjectPtr<UObject> SOP)
{
	Add(SOP);
}

void USoftServe::Stream()
{

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();


	for (TSoftClassPtr<UObject> SCP : SoftClasses)
	{
		ItemsToStream.AddUnique(SCP.ToSoftObjectPath());
	}

	for (TSoftObjectPtr<UObject> SOP : SoftObjects)
	{
		if (SOP == NULL)
		{
			ItemsToStream.AddUnique(SOP.ToSoftObjectPath());
		}

	}

	if (ItemsToStream.Num() == 0)
	{
		Complete();
	}
	else
	{
		Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &USoftServe::Complete));
	}
}

bool USoftServe::HasNull()
{

	for (TSoftClassPtr<UObject> SCP : SoftClasses)
	{
		if (SCP == NULL)
		{
			return true;
		}
	}

	for (TSoftObjectPtr<UObject> SOP : SoftObjects)
	{
		if (SOP == NULL)
		{
			return true;
		}

	}

	return false;
}

void USoftServe::Complete()
{
	OnComplete.Broadcast(this);
}