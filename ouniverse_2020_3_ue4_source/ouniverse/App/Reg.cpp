// Fill out your copyright notice in the Description page of Project Settings.


#include "App/Reg.h"
#include "App/Scope.h"

namespace GlobalReg
{
	UReg* Object;
}

UReg* UReg::Create()
{
	TSubclassOf<UReg> Class_ = TSoftClassPtr<UReg>(FSoftClassPath("/Game/Class/App/RegBP.RegBP_C")).LoadSynchronous();
	GlobalReg::Object = NewObject<UReg>(ScopeC::World(), *Class_);
	return GlobalReg::Object;
}

UReg* UReg::Get()
{
	return GlobalReg::Object;
}