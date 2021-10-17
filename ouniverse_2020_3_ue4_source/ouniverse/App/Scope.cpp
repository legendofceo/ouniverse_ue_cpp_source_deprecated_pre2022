//Copyright 2015-2019, All Rights Reserved.

#include "App/Scope.h"


namespace GlobalScope
{
	UWorld* World;
	UObject* WorldContextObject;
}

void ScopeC::Initialize(UObject* InWorldContextObject, UWorld* InWorld)
{
		GlobalScope::WorldContextObject = InWorldContextObject;
		GlobalScope::World = InWorld;

}

UWorld* ScopeC::World()
{
	return GlobalScope::World;
}

UObject* ScopeC::WorldContext()
{
	return GlobalScope::WorldContextObject;
}