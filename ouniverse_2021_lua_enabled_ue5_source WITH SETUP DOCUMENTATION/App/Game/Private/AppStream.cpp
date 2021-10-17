// Fill out your copyright notice in the Description page of Project Settings.


#include "AppStream.h"

const FName UAppStream::SYS = "AppStream";


namespace Global
{
	UAppStream* AppStream;
}

UAppStream::UAppStream()
{
	Global::AppStream = this;
}

UAppStream* UAppStream::Get()
{
	return Global::AppStream;
}

void UAppStream::Stream(FSoftObjectPath TargetToStream, FStreamableDelegate DelegateToCall)
{
	StreamableManager.RequestAsyncLoad(TargetToStream, DelegateToCall);
}

void UAppStream::Stream(TArray<FSoftObjectPath> TargetsToStream, FStreamableDelegate DelegateToCall)
{
	StreamableManager.RequestAsyncLoad(TargetsToStream, DelegateToCall);

}