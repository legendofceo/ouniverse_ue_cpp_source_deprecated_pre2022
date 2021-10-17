// Fill out your copyright notice in the Description page of Project Settings.


#include "AppMode.h"
#include "AppStream.h"
#include "Log.h"
#include "AppInstance.h"
#include "PrimaryPro.h"
#include "Data.h"
#include "AppPro.h"


const FName AAppMode::SYS = "AppMode";

namespace Global
{
	AAppMode* AppMode = nullptr;
}

AAppMode::AAppMode()
{
	Global::AppMode = this;
}

AAppMode* AAppMode::Get()
{
	return Global::AppMode;
}

AAppMode* AAppMode::GetAppMode(const UObject* WorldContextObject)
{
	return Cast<AAppMode>(WorldContextObject->GetWorld()->GetAuthGameMode());
}

void AAppMode::BeginPlay()
{
	Global::AppMode = this;
	Super::BeginPlay();
}

void AAppMode::Boot()
{


	/**
	if (PrimaryProSoft.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("PrimaryProSoft is null").DebugM();
		return;
	}

	UAppStream::Get()->Stream(PrimaryProSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AAppMode::Boot_Stream));
	*/
}

void AAppMode::Boot_Stream()
{
	PrimaryPro = NewObject<UPrimaryPro>(this, PrimaryProSoft.Get());
	PrimaryPro->Engage();
}

void AAppMode::CreateData()
{
	if (!DataClass)
	{
		LOG.S(SYS).T(TCRIT).W("DataClass is null").DebugM();
		return;
	}

	Data = NewObject<UData>(this, DataClass.Get());
	OnCreateDataComplete.Broadcast();
}