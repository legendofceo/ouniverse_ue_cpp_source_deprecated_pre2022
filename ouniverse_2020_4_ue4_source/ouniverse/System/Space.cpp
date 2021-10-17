//Copyright 2015-2019, All Rights Reserved.

#include "Space.h"
#include "Scope.h"


namespace Global
{
	USpace* Space;
}

USpace::USpace() {};

USpace* USpace::Create()
{
	USpace* Neu = NewObject<USpace>();
	Global::Space = Neu;
	return Neu;
}

USpace* USpace::Get()
{
	return Global::Space;
}