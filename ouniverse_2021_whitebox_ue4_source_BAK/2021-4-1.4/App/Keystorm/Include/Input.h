// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EInputBT.h"
#include "Input.generated.h"

/**
 * 
 */

class AAppController;

UENUM(BlueprintType)
enum EAXUI
{
	EMagnaUiUp UMETA(DisplayName = "Accept"),
	EMagnaUiDown   UMETA(DisplayName = "Cancel"),
};


UCLASS()
class APP_API UInputButton : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EInputBT> InputCode;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AAppController* PC;

	static UInputButton* Create(AAppController* PC, const FKey* Key, TEnumAsByte<EInputBT> InputCode);

	bool bPressed;

	UFUNCTION()
	void Pressed();

	UFUNCTION()
	void Released();

};

UENUM(BlueprintType)
enum class EHandledExecs : uint8
{
	Unhandled,
	Handled,
};

UENUM(BlueprintType)
enum class EPressedExecs : uint8
{
	Pressed,
	Released,
};

UCLASS()
class APP_API UInputButtonEvent : public UObject
{
	GENERATED_BODY()


private:

	uint8 InputCode;
	bool bPressed;
	bool bHandled;

public:

	void Fill(UInputButton* InputButton);

	uint8 GetInputCode();

	bool IsPressed();

	bool IsHandled();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Input Code"))
	void GetInputCodeBP(uint8& Code);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Is Pressed", ExpandEnumAsExecs = Execs))
	void IsPressedBP(EPressedExecs& Execs);


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Is Handled", ExpandEnumAsExecs = Execs))
	void IsHandledBP(EHandledExecs& Execs);

};

UCLASS()
class APP_API UAXUI : public UObject
{
	GENERATED_BODY()

	bool bHandled;
	TEnumAsByte<EAXUI> Axi;
};


UCLASS()
class APP_API UInput : public UObject
{
	GENERATED_BODY()
	
};
