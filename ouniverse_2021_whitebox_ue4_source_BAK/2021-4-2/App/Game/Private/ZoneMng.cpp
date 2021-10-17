// Fill out your copyright notice in the Description page of Project Settings.


#include "ZoneMng.h"
#include "Zone.h"
#include "Kismet/GameplayStatics.h"

namespace Manager
{
	AZoneMng* Zone = NULL;
}

AZoneMng::AZoneMng() : ANexus() {}

AZoneMng* AZoneMng::Get()
{
	return Manager::Zone;
}

void AZoneMng::GetZoneMngBP(AZoneMng*& ZoneMng)
{
	ZoneMng = Manager::Zone;
}

void AZoneMng::BeginPlay()
{
	Manager::Zone = this;
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	bInit = true;
	OnInitComplete.Broadcast(this);

}