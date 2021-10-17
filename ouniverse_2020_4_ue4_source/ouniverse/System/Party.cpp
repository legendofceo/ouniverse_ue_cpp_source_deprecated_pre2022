// Fill out your copyright notice in the Description page of Project Settings.



#include "Party.h"

namespace GlobalSingleton
{
	PartyC* gParty;
}

PartyC* PartyC::Get()
{
	return GlobalSingleton::gParty;
}

PartyC* PartyC::Create()
{
	PartyC* Obj = new PartyC();
	GlobalSingleton::gParty = Obj;
	return Obj;
}

PartyC::PartyC()
{
	ActiveMembers.Init(NULL, 6);
}
void PartyC::SetActiveMember(int MemberSlot, UHero* NewActiveMember)
{
	ActiveMembers[MemberSlot] = NewActiveMember;
}

void PartyC::SpawnParty()
{

}


void PartyC::DespawnParty()
{

}