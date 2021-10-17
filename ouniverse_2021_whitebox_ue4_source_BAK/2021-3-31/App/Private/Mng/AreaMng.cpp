// Fill out your copyright notice in the Description page of Project Settings.


#include "Mng/AreaMng.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Area.h"

namespace Manager
{
	AAreaMng* Area = NULL;
}

AAreaMng::AAreaMng() : AManagerActor() {}

AAreaMng* AAreaMng::Get()
{
	return Manager::Area;
}

void AAreaMng::GetAreaMngBP(AAreaMng*& AreaMng)
{
	AreaMng = Manager::Area;
}

void AAreaMng::BeginPlay()
{
	Manager::Area = this;

	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);

}

void AAreaMng::ChangeArea(FAreaAddress NextArea)
{
	PendingAreaAddress = NextArea;

	if (Area != NULL)
	{
		Area->OnUnloaded.AddDynamic(this, &AAreaMng::AreaUnloaded);
		Area->Unload();
	}
	else
	{
		AreaUnloaded();
	}
}

void AAreaMng::AreaUnloaded()
{
	if (PendingAreaAddress.IsValid())
	{
		//Doing this incase asynch load finished in same thread:
		FSoftObjectPath SoftObjectPath = PendingAreaAddress.Area.ToSoftObjectPath();
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(PendingAreaAddress.Area.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AAreaMng::LoadNextArea));
	}
}

void AAreaMng::LoadNextArea()
{
	AreaAddress = PendingAreaAddress;
	PendingAreaAddress.Invalidate();
	Area = NewObject<UArea>(this, AreaAddress.Area.Get());
	Area->Load(AreaAddress.Address);
}
