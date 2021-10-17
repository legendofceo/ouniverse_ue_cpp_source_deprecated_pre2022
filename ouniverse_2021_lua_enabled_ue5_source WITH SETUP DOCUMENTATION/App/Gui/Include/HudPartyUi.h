// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HudPartyUi.generated.h"

class UHudPartyMemberMajorUi;
class UHudPartyMemberMinorUi;
class UHudPartyMemberUi;
class UPartyHandle;

UCLASS(Abstract)
class APP_API UHudPartyUi : public UUserWidget
{
	GENERATED_BODY()

	static	const FName SYS;

public:

	/**
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UPartyHandle* ActivePartyHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UHudPartyMemberUi*> MemberUis;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHudPartyMemberMajorUi* Major;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHudPartyMemberMinorUi* Minor1;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHudPartyMemberMinorUi* Minor2;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UHudPartyMemberMinorUi* Minor3;

	UFUNCTION()
	void UpdateOnNewParty(UPartyHandle* InActiveParty);

	UFUNCTION()
	void OnPlayerIndexChanged(uint8 SetStyle);

	void Build();
	*/
};
