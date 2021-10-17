// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HudPartyMemberUi.generated.h"

class UPartyMemberHandle;
class UActra;

UCLASS(Abstract)
class APP_API UHudPartyMemberUi : public UUserWidget
{
	GENERATED_BODY()

	static const FName SYS;

public:
	
	/**
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UPartyMemberHandle* PartyMemberHandle = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UActra* PartyMember = nullptr;

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

	void UpdateOnPartyMemberHandle(UPartyMemberHandle* NewPartyMemberHandle);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@UpdateName"))
	void UpdateNameBP(const FText& Name);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@UpdateHealth"))
	void UpdateHealthBP(int HealthPercent);

	void Clear();
	*/
};


UCLASS(Abstract)
class APP_API UHudPartyMemberMajorUi : public UHudPartyMemberUi
{
	GENERATED_BODY()

		static const FName SYS;

public:


};

UCLASS(Abstract)
class APP_API UHudPartyMemberMinorUi : public UHudPartyMemberUi
{
	GENERATED_BODY()

		static const FName SYS;

public:


};