// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputList.h"
#include "Input.generated.h"


class APC;

UENUM()
enum EModifier
{
	ModifierNone			UMETA(DisplayName = "None"),
	ModifierAny				UMETA(DisplayName = "Any"),
	ModifierMod				UMETA(DisplayName = "Mod"),
	ModifierAux				UMETA(DisplayName = "Aux"),
	ModifierDuo				UMETA(DisplayName = "Duo"),
};

USTRUCT(BlueprintType)
struct FControllerOutput
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> Open;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> Left;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> Right;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> Dual;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> Menu;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EModifier> Mod;


};

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UBindSpecial : public UActorComponent
{
	GENERATED_BODY()

public:

	void Setup(APC* InPC, TEnumAsByte<ECommandSpecialID> InID, FName InAction);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandSpecialID> ID;

	UFUNCTION()
	void Press();

	UFUNCTION()
	void Release();

};

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UBindMak : public UActorComponent
{
	GENERATED_BODY()

public:

	void Setup(APC* InPC, FName InAction);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandID> Clean;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;

	UFUNCTION()
	void Press();

	UFUNCTION()
	void Release();

};

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UBindPad: public UActorComponent
{
	GENERATED_BODY()

public:

	void Setup(APC* InPC, TEnumAsByte<EInputPad> InID, FName InKeyID);



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FControllerOutput Output;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EInputPad> ID;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FKey KeyID;

	UFUNCTION(Reliable, Client)
	void Press();

	UFUNCTION(Reliable, Client)
	void Release();

};

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UBindAxis : public UActorComponent
{
	GENERATED_BODY()

public:

	void Setup(APC* InPC, TEnumAsByte<EInputAxis> InID, FName InKeyID, TEnumAsByte<EControlType> InControlType);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandAxisID> Clean;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EInputAxis> ID;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EControlType> ControlType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bEnabled = false;

	void Enable(bool bOn);

	UFUNCTION()
	void Axis(float Power);


};


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UBindAxisFaux : public UActorComponent
{
	GENERATED_BODY()

public:

	void Setup(APC* InPC, TEnumAsByte<EInputAxis> InID, FName InDefaultKeyUp, FName InDefaultKeyDown);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName DefaultKeyUp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName DefaultKeyDown;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ECommandAxisID> Clean;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EInputAxis> ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FKey KeyUp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FKey KeyDown;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Time;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bEnabled = false;

	void Enable(bool bOn);

	void Trigger();

};