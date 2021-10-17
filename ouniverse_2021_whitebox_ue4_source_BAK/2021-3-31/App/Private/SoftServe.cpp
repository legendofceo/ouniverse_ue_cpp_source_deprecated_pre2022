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

	Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &USoftServe::Complete));
}

bool USoftServe::NullCheck()
{

	for (TSoftClassPtr<UObject> SCP : SoftClasses)
	{
		if (SCP == NULL)
		{
			return false;
		}
	}

	for (TSoftObjectPtr<UObject> SOP : SoftObjects)
	{
		if (SOP == NULL)
		{
			return false;
		}

	}

	return true;
}

void USoftServe::Complete()
{
	OnComplete.Broadcast(this);
}