// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskAsyncLoadBatch.h"
#include "AppStream.h"
#include "Engine/AssetManager.h"

UTaskAsyncLoadBatch::UTaskAsyncLoadBatch()
{
	TaskKey = "AsyncLoadBatch";
}

void UTaskAsyncLoadBatch::Add(TSoftClassPtr<UObject> SCP)
{
	SoftClasses.Add(SCP);
}

void UTaskAsyncLoadBatch::Add(TSoftObjectPtr<UObject> SOP)
{
	SoftObjects.Add(SOP);
}


void UTaskAsyncLoadBatch::AddSoftClassBP(TSoftClassPtr<UObject> SCP, UTaskAsyncLoadBatch*& R)
{
	Add(SCP);
	R = this;
}

void UTaskAsyncLoadBatch::AddSoftObjectBP(TSoftObjectPtr<UObject> SOP, UTaskAsyncLoadBatch*& R)
{
	Add(SOP);
	R = this;
}

void UTaskAsyncLoadBatch::RunTaskOverride()
{
	TArray<FSoftObjectPath> ItemsToStream;


	for (TSoftClassPtr<UObject> SCP : SoftClasses)
	{
		ItemsToStream.AddUnique(SCP.ToSoftObjectPath());
	}

	for (TSoftObjectPtr<UObject> SOP : SoftObjects)
	{
		ItemsToStream.AddUnique(SOP.ToSoftObjectPath());
	}

	if (ItemsToStream.Num() == 0)
	{
		AsyncLoadComplete();
	}
	else
	{
		UAppStream::Get()->Stream(ItemsToStream, FStreamableDelegate::CreateUObject(this, &UTaskAsyncLoadBatch::AsyncLoadComplete));
	}

}


bool UTaskAsyncLoadBatch::HasNull()
{

	for (TSoftClassPtr<UObject> SCP : SoftClasses)
	{
		if (SCP.IsNull())
		{
			return true;
		}
	}

	for (TSoftObjectPtr<UObject> SOP : SoftObjects)
	{
		if (SOP.IsNull())
		{
			return true;
		}

	}

	return false;
}

void UTaskAsyncLoadBatch::HasNullBP(UTaskAsyncLoadBatch*& R, EValidNull& Execs)
{
	if (!HasNull())
	{
		Execs = EValidNull::Valid;
	}
	else
	{
		Execs = EValidNull::Null;
	}

	R = this;
}

void UTaskAsyncLoadBatch::AsyncLoadComplete()
{
	Complete();
}
