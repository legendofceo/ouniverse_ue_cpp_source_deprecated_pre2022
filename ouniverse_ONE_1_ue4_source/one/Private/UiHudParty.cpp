// Fill out your copyright notice in the Description page of Project Settings.


#include "UiHudParty.h"
#include "APC.h"
#include "AGS.h"
#include "Party.h"
#include "Components/VerticalBox.h"

void UUiHudParty::NativeConstruct()
{
	Super::NativeConstruct();
	PC = APC::GetPC();
}


void UUiHudPartyMember::ConnectToPartyMember(int InPartyMemberIndex)
{
	AParty* Party = AGS::GetGS()->Party;
	//UPartyMember* PartyMember = Party->GetPartyMember(InPartyMemberIndex);
}

void UUiHudPartyMember::NativeConstruct()
{
	Super::NativeConstruct();
	AParty* Party = AGS::GetGS()->Party;
	PartyMember = Party->GetPartyMember(PartyMemberIndex);
	Style = CreateStyle();
	PartyMember->OnChanged.AddDynamic(Style, &UUiHudPartyMemberStyle::Connect);
	PartyMember->OnEmpty.AddDynamic(Style, &UUiHudPartyMemberStyle::Empty);
	PartyMember->OnPlayer.AddDynamic(Style, &UUiHudPartyMemberStyle::Player);

	if (!PartyMember->IsEmpty())
	{
		Style->Connect(PartyMember->Member);
	}
}

void UUiHudPartyMember::OnSlotChanged()
{

}

void UUiHudPartyMemberStyle::Connect(AActra* PartyMember)
{

}

void UUiHudPartyMemberStyle::Empty()
{

}


void UUiHudPartyMemberStyle::Player(int PlayerIndex)
{

}