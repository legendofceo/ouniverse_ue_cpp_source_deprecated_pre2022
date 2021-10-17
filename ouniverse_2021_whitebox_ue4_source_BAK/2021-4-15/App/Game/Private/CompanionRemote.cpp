// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionRemote.h"
#include "Log.h"
#include "AppController.h"
#include "PartyMemberHandle.h"
#include "CompanionActor.h"

const FName UCompanionRemote::SYS = "COMPANIONREMOTE";

UCompanionRemote::UCompanionRemote()
{

}

void UCompanionRemote::Init(AAppController* AP)
{
	URemote::Init(AP);

}

void UCompanionRemote::Engage(UPartyMemberHandle* PartyMemberHandle)
{
	LOG.S(SYS).N(this).W("Companion Remote Engaged");
	AppPlayer->Possess(PartyMemberHandle->CompanionA);
	//AppPlayer->SetViewTarget(PartyMemberHandle->CompanionA);
	PartyMemberHandle->CompanionA->Engage(this);
}