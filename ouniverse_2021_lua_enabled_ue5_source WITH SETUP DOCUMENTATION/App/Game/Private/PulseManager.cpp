// Fill out your copyright notice in the Description page of Project Settings.


#include "PulseManager.h"
#include "Log.h"

DECLARE_STATS_GROUP(TEXT("Pulse"), STATGROUP_Pulse, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("PulseTick (Single)"), STAT_PulseTick, STATGROUP_Pulse);


bool UPulseHandle::Pulse(float Delta)
{
	//Abstract so should never occur;
	return false;
};

UPulseHandleConstant* UPulseHandleConstant::CreatePulseHandleConstant(UObject* Owner, std::function<bool(float)> Func)
{
	UPulseHandleConstant* P = NewObject<UPulseHandleConstant>(Owner, UPulseHandleConstant::StaticClass());
	P->Func = Func;
	P->Owner = Owner;
	return P;
}

bool UPulseHandleConstant::Pulse(float Delta)
{
	if (!IsValid(Owner) || Owner->IsPendingKill())
	{
		return false;
	}

	if (!Func(Delta))
	{
		return false;
	}

	return true;
}


const FName UPulseManager::SYS = "PulseManager";

namespace Manager
{
	UPulseManager* Pulse = nullptr;
}

UPulseManager::UPulseManager()
{

}

UPulseManager* UPulseManager::Get()
{
	return Manager::Pulse;
}

void UPulseManager::Init()
{
	Manager::Pulse = this;
	LOG.S(SYS).W("Init()");

	TickDelegate = FTickerDelegate::CreateUObject(this, &UPulseManager::Tick);
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);

	InitComplete();
}


bool UPulseManager::Tick(float Delta)
{
	SCOPE_CYCLE_COUNTER(STAT_PulseTick);
	{
		int L = Pulses.Num();
		for (int i = L - 1; i >= 0; i--)
		{
			if (!Pulses[i].Handle->Pulse(Delta))
			{
				Pulses.RemoveAt(i);
			}
		}
	}
	return true;
}

void UPulseManager::AddPulseHandle(FName Context, UPulseHandle* PulseHandle)
{
	Pulses.Add(FPulseEntry(Context, PulseHandle));
}

void UPulseManager::RemovePulseHandle(UPulseHandle* PulseHandle)
{

	int L = Pulses.Num();
	for (int i=0;i<L;i++)
	{
		if (Pulses[i].Handle == PulseHandle)
		{
			Pulses.RemoveAt(i);
			break;
		}
	}

}