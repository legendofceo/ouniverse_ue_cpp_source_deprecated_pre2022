// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyPro.h"
#include "Blue.h"


namespace Pro
{
	UPartyPro* Party = NULL;
}

UPartyPro::UPartyPro() : UProtocol(){}

UPartyPro* UPartyPro::Get()
{
	return Pro::Party;
}


void UPartyPro::Init()
{
	Pro::Party = this;

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	InitComplete();
}