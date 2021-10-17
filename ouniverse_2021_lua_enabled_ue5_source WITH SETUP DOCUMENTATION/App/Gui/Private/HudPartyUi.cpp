// Fill out your copyright notice in the Description page of Project Settings.


#include "HudPartyUi.h"
#include "Log.h"
#include "Defaults.h"
#include "HudPartyMemberUi.h"


const FName UHudPartyUi::SYS = "PartyHudUi";

/**
void UHudPartyUi::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	LOG.S(SYS).W("OnInitialized() Registering for delegates");

	MemberUis.Add(Major);
	MemberUis.Add(Minor1);
	MemberUis.Add(Minor2);
	MemberUis.Add(Minor3);

	if (MemberUis.Num() > UDefaults::PartyMaxSize)
	{
		LOG.S(SYS).T(TCRIT).W("MemberUi Count does not match the FParty::PartyMaxSize").DebugM();
	}

	UCompanyHandle::Get()->OnActivePartySet.AddDynamic(this, &UHudPartyUi::UpdateOnNewParty);
}

void UHudPartyUi::NativeConstruct()
{
	Super::NativeConstruct();
}

void UHudPartyUi::UpdateOnNewParty(UPartyHandle* InActiveParty)
{
	LOG.S(SYS).W("UpdateOnNewParty()");

	ActivePartyHandle = InActiveParty;
	UOnwardPro* OnwardPro = UOnwardPro::Get();
	OnwardPro->OnPlayerIndexChanged.AddDynamic(this, &UHudPartyUi::OnPlayerIndexChanged);
	Build();
}

void UHudPartyUi::OnPlayerIndexChanged(uint8 SetStyle)
{
	Build();
	PartyHandlePlayerSetStyle Style = PartyHandlePlayerSetStyle(SetStyle);
}

void UHudPartyUi::Build()
{
	TArray<UPartyMemberHandle*> Sequence;
	ActivePartyHandle->GetSequenceStartingFromPlayerIndex(Sequence);

	int SequenceNum = Sequence.Num();

	for (int i = 0; i < MemberUis.Num(); i++)
	{
		if (i < SequenceNum)
		{
			MemberUis[i]->UpdateOnPartyMemberHandle(Sequence[i]);
		}
		else
		{
			MemberUis[i]->Clear();
		}
	}
}
*/