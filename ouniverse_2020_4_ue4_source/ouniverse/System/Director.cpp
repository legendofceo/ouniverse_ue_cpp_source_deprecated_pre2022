//Copyright 2015-2019, All Rights Reserved.

#include "Director.h"
#include "Act.h"
#include "Scope.h"

namespace GlobalSingleton
{
	UDirector* gDirector;
}

UDirector::UDirector() {};

UDirector* UDirector::Create(TMap<FName, TSoftClassPtr<UAct>>* InActReg)
{
	UDirector* Neu = NewObject<UDirector>();
	Neu->Init(InActReg);
	GlobalSingleton::gDirector = Neu;
	return Neu;
}

void UDirector::Init(TMap<FName, TSoftClassPtr<UAct>>* InActReg)
{
	ActReg_ = InActReg;
}

UDirector* UDirector::Get()
{
	return GlobalSingleton::gDirector;
}

void UDirector::SetAct(FName ActID)
{
	if (IsValid(Act_))
	{
		Act_->Dismount();
	}

	if (ActReg_->Contains(ActID))
	{
		TSubclassOf<UAct> NewAct = ActReg_->Find(ActID)->LoadSynchronous();
		Act_ = NewObject<UAct>(ScopeC::WorldContext(), *NewAct);
		Act_->Mount();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Act not found in ActMap: "+ActID.ToString()));
	}
}