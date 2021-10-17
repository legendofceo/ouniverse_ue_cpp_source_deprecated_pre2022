// Fill out your copyright notice in the Description page of Project Settings.


#include "MythRemote.h"
#include "Log.h"
#include "AppController.h"
#include "MythPro.h"
#include "OnwardRemote.h"

const FName UMythRemote::SYS = "MythRemote";

UMythRemote::UMythRemote() : URemote()
{

}

void UMythRemote::Init(AAppController* AP)
{
	URemote::Init(AP);
	MythPro = AAppMode::Get()->MythPro;
	OnwardRemote = AP->OnwardRemote;
	OnwardRemote->Init(AP, MythPro);
}

void UMythRemote::BeginPlay()
{
	Super::BeginPlay();
}

void UMythRemote::Engage()
{
	
}