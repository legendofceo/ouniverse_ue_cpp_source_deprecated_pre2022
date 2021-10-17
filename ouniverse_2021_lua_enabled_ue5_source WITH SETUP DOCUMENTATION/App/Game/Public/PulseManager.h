// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Delegate.h"
#include <functional>
#include "PulseManager.generated.h"


UCLASS(Abstract)
class APP_API UPulseHandle : public UObject
{
	GENERATED_BODY()

public:

	virtual bool Pulse(float Delta);
};

UCLASS()
class APP_API UPulseHandleConstant : public UPulseHandle
{
	GENERATED_BODY()

public:

	static UPulseHandleConstant* CreatePulseHandleConstant(UObject* Owner, std::function<bool(float)>);

	UPROPERTY(VisibleAnywhere)
	UObject* Owner;

	virtual bool Pulse(float Delta) override;

	std::function<bool(float)> Func;
};


USTRUCT()
struct APP_API FPulseEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FName Context;

	UPROPERTY(VisibleAnywhere)
	UPulseHandle* Handle;

	FPulseEntry() {};
	FPulseEntry(FName InContext, UPulseHandle* InHandle)
	{
		Context = InContext;
		Handle = InHandle;
	}
};

UCLASS()
class APP_API UPulseManager : public USystem
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UPulseManager();

	void Init() override;

	static UPulseManager* Get();

	UPROPERTY(VisibleAnywhere)
	TArray<FPulseEntry> Pulses;

	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;

	UFUNCTION()
	bool Tick(float Delta);

	void AddPulseHandle(FName Context, UPulseHandle* PulseHandle);
	void RemovePulseHandle(UPulseHandle* PulseHandle);


};
