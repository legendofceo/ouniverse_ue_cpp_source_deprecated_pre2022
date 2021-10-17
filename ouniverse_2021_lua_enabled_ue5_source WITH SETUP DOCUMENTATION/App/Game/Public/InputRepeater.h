// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Execs.h"
#include "InputRepeater.generated.h"


UENUM(BlueprintType)
enum class InputRepeaterPassState : uint8
{
	Block UMETA(DisplayName = "Block"),
	Click UMETA(DisplayName = "Click"),
	First  UMETA(DisplayName = "First"),
	Repeat  UMETA(DisplayName = "Repeat"),
};

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FInputRepeater
{
	GENERATED_BODY()

public:

	FInputRepeater() {};

	bool bFirstPassed = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bNoPassOnClick = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FirstGate = 0.4f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RepeatGate = 0.1f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	InputRepeaterPassState PassState = InputRepeaterPassState(0);

	float LastGateTriggeredDelta;

	void Reset();
	bool Update(UBT* BT);
};

UCLASS()
class APP_API UInputRepeaterStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#InputRepeater Update", ExpandEnumAsExecs = Execs))
	static void Update(UPARAM(ref) FInputRepeater& RepeatGate, UBT* BT, EPassBlock& Execs, InputRepeaterPassState& PassState);

};