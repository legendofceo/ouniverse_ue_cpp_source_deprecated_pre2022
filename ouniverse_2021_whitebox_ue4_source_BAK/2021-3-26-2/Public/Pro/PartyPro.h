// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pro.h"
#include "PartyPro.generated.h"

class UParty;
class UStoryPro;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPartyProDelegate);

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UPartyPro : public UPro
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	void Init(UStoryPro* InStoryPro);

	UFUNCTION()
	void InitLL();

	UFUNCTION()
	void InitSO();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Initialized = false;

	UPROPERTY(BlueprintAssignable)
	FPartyProDelegate OnInitComplete;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStoryPro* StoryPro;

};
