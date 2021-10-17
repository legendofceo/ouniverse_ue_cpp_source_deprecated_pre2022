// Fill out your copyright notice in the Description page of Project Settings.


#include "HudPartyMemberUi.h"
#include "Log.h"

const FName UHudPartyMemberUi::SYS = "PartyMemberHudUi";

/**
void UHudPartyMemberUi::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UHudPartyMemberUi::NativeConstruct()
{
	Super::NativeConstruct();
}

void UHudPartyMemberUi::UpdateOnPartyMemberHandle(UPartyMemberHandle* NewPartyMemberHandle)
{
	LOG.S(SYS).W("UpdateOnNewPartyMemberHandle()");
	PartyMemberHandle = NewPartyMemberHandle;

	SetVisibility(ESlateVisibility::Visible);
	PartyMember = PartyMemberHandle->GetActra();
	UpdateNameBP(PartyMember->GetDisplayName());
	UpdateHealthBP(PartyMember->GetHealthPercent());
}

void UHudPartyMemberUi::Clear()
{
	PartyMemberHandle = nullptr;
	SetVisibility(ESlateVisibility::Collapsed);
}

*/