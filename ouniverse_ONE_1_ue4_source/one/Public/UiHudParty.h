// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UiHudParty.generated.h"

/**
 * 
 */

class UUiHudPartyMember;
class UUiHudPartyMemberStyle;
class UPartyMember;
class APC;




UCLASS()
class ONE_API UUiHudParty : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUiHudPartyMember* PartyMember0;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUiHudPartyMember* PartyMember1;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUiHudPartyMember* PartyMember2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUiHudPartyMember> UiHudPartyMemberClass;

};


UCLASS()
class ONE_API UUiHudPartyMember : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void ConnectToPartyMember(int InPartyMemberIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int PartyMemberIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMember* PartyMember;

	UFUNCTION(BlueprintImplementableEvent)
	UUiHudPartyMemberStyle* CreateStyle();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiHudPartyMemberStyle* Style;

	UFUNCTION()
	void OnSlotChanged();

};


UCLASS()
class ONE_API UUiHudPartyMemberStyle : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void Connect(AActra* PartyMember);
	UFUNCTION()
	void Empty();
	UFUNCTION()
	void Player(int PlayerIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void DoHealthChanged(int Health);
	UFUNCTION(BlueprintImplementableEvent)
	void DoManaChanged(int Health);
	UFUNCTION(BlueprintImplementableEvent)
	void DoStaminaChanged(int Health);
	UFUNCTION(BlueprintImplementableEvent)
	void DoNameChanged(int Health);
	UFUNCTION(BlueprintImplementableEvent)
	void DoPortraitChanged(int Health);

};