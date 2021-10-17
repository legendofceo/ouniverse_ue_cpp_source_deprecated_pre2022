// Fill out your copyright notice in the Description page of Project Settings.


#include "AppNexus.h"
#include "AppInstance.h"

void AAppNexus::BeginPlay()
{
	Super::BeginPlay();
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");
	App = UApp::Get();
	bInit = true;
	OnInitComplete.Broadcast(this);

}