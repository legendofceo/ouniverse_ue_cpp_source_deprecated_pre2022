// Fill out your copyright notice in the Description page of Project Settings.


#include "LogicStream.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Logic.h"

void ULogicStream::Stream(TSoftClassPtr<ULogic> LogicClass)
{
	if (LogicClass.IsValid())
	{
		StreamLL();
	}
	else
	{
		Class = LogicClass;
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(Class.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ULogicStream::StreamLL));
	}
}

void ULogicStream::StreamLL()
{
	Logic = NewObject<ULogic>(this, Class.Get());
	Logic->OnLogicComplete.AddDynamic(this, &ULogicStream::LogicComplete);
	Logic->DoLogic();
}

void ULogicStream::LogicComplete(ULogic* CompletedLogic)
{
	OnLogicComplete.Broadcast(CompletedLogic);
}