// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCodes.h"
#include "InputDevices.h"
#include "Execs.h"
#include "InputRaw.generated.h"

class AAppController;


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
class APP_API UVirtualInput : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppController* PC;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	InputDevice Device;

	bool IsGamepad();
	InputDevice GetDevice();
	bool IsHandled();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Handled", ExpandEnumAsExecs = Execs))
	void IsHandledBP(EHandledExecs& Execs);

protected:

	bool bHandled;

};

UCLASS(BlueprintType)
class APP_API UBT : public UVirtualInput
{
	GENERATED_BODY()

public:
	static UBT* Create(AAppController* PC, const FKey* Key, InputCodeBT InputCode, InputDevice InDevice);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	InputCodeBT InputCode;

	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;

	UFUNCTION()
	void Pressed();

	UFUNCTION()
	void Released();




public:

	UFUNCTION()
	bool Held(float Delta);

	float GetTimeHeld();
	float GetDelta();
	uint8 GetInputByte();
	InputCodeBT GetInputCode();
	bool IsPressed();
	bool IsHeld();

	/** Click is used to differentiate between press and release of a key being the trigger point
	* if we want to change this functionality we can do it in click to effect the game globally
	* click also only considers the first click and not held calls by filtering out IsHeld
	*/
	bool IsClick();

	/**Is the stroke type which is standardized to send the input (Up vs Down)
	* Can easily globally change what is the standardized press accepted state.
	*/
	bool IsSender();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetByte"))
	void GetInputByteBP(uint8& Code);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetCode"))
	void GetInputCodeBP(InputCodeBT& Code);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetHeldTime"))
	void GetTimeHeldBP(float& Time);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#IsPressed", ExpandEnumAsExecs = Execs))
	void IsPressedBP(EPressedExecs& Execs);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#IsClick", ExpandEnumAsExecs = Execs))
	void IsClickBP(EYesNo& Execs);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#IsHeld", ExpandEnumAsExecs = Execs))
	void IsHeldBP(EYesNo& Execs);

protected:

	uint8 CommandByte;

private:

	float TimeHeld;
	bool bHeld;
	bool bPressed;

	void Send();
};





UCLASS(BlueprintType)
class APP_API UAX : public UVirtualInput
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	InputCodeAX InputCode;

	static UAX* Create(AAppController* PC, const FKey* Key, InputCodeAX InputCode, InputDevice InDevice);

	UFUNCTION()
	void Update(float InPower);

	uint8 GetCode();

	float GetPower();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetPower"))
	void GetPowerBP(float& Pow);




public:

	UPROPERTY(VisibleAnywhere)
	bool bFaux;

	UPROPERTY(VisibleAnywhere)
	bool bZero;

	UPROPERTY(VisibleAnywhere)
	float Power;

private:

	bool bPositivePressed;
	bool bNegativePressed;

private:

	void Send();
};
