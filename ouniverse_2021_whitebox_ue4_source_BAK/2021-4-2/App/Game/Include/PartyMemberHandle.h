// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Task.h"
#include "PartyMemberHandle.generated.h"

/**
 * 
 */

struct FPartyMember;
class UCompanion;
class ACompanionActor;
class UPartyMemberHandle;


UCLASS()
class APP_API UPartyMemberHandle_Task_CompanionA : public UTask
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMemberHandle* PartyMemberHandle;

	void Setup(UPartyMemberHandle* InPartyMemberHandle);

	virtual void Go() override;
};

UCLASS()
class APP_API UPartyMemberHandle : public UObject
{
	GENERATED_BODY()


public:

	FPartyMember* PartyMember;

	void Init(FPartyMember* InPartyMember);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACompanionActor* CompanionA;

	UPartyMemberHandle_Task_CompanionA* BeCompanionA();

	bool HasCompanion();

	UCompanion* GetCompanion();
};