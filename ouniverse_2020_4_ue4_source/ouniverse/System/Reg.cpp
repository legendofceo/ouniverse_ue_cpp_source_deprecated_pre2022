// Fill out your copyright notice in the Description page of Project Settings.

#include "Reg.h"
#include "Scope.h"

namespace GlobalSingleton
{
	UReg* gReg;
}


void UReg::Initialize()
{
	TSubclassOf<UReg> Reg = TSoftClassPtr<UReg>(FSoftClassPath("/Game/dat/reg.reg_C")).LoadSynchronous();
	GlobalSingleton::gReg = NewObject<UReg>(ScopeC::WorldContext(),*Reg);
}

UReg* UReg::Get()
{
	return GlobalSingleton::gReg;
}