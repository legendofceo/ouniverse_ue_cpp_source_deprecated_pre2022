// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Components/SceneComponent.h"
#include "Body.generated.h"

class AActra;
struct FActraHumanRow;

class UEquipSlot;
class UWearableNudeBust;
class UWearableNudeLegs;
class UWearableNudeHands;
class UWearableNudeFeet;

UENUM()
enum ESex
{
	SexMale					UMETA(DisplayName = "Male"),
	SexFemale				UMETA(DisplayName = "Female"),
	SexAttackHelicopter		UMETA(DisplayName = "AttackHelicopter"),
};

UENUM()
enum EBodyType
{
	HumanFemale01		UMETA(DisplayName = "Female01"),
	HumanFemale02		UMETA(DisplayName = "Female02"),
	HumanMale01			UMETA(DisplayName = "Male01"),
};


USTRUCT()
struct ETREIAAPP_API FBodyHumanRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	FLinearColor SkinColor;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ESex> Sex;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EBodyType> BodyType;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<USkeletalMesh> MasterMesh;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UWearableNudeBust> NudeBust;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UWearableNudeLegs> NudeLegs;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UWearableNudeHands> NudeHands;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UWearableNudeFeet> NudeFeet;

	static bool Try(FBodyHumanRow*& Output, FName Key);
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETREIAAPP_API UBody : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBody();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(category = Actra, VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* MasterMesh;

	void Setup(AActra* InActra);

	UPROPERTY(category = Actra, VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EBodyType> BodyType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Actra;

	virtual void FromRow(FName Key) {};
	virtual void UpdatePoly() {};
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETREIAAPP_API UBodyHuman : public UBody
{
	GENERATED_BODY()

	UBodyHuman();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:




	UPROPERTY(category = Actra, VisibleAnywhere, BlueprintReadOnly)
	FLinearColor SkinColor;

	UPROPERTY(category = Actra, VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ESex> Sex;

	UPROPERTY(Category = "Actra|EquipSlots", VisibleAnywhere, BlueprintReadOnly)
	UEquipSlot* SlotNudeBust;

	UPROPERTY(Category = "Actra|EquipSlots", VisibleAnywhere, BlueprintReadOnly)
	UEquipSlot* SlotNudeLegs;

	UPROPERTY(Category = "Actra|EquipSlots", VisibleAnywhere, BlueprintReadOnly)
	UEquipSlot* SlotNudeHands;

	UPROPERTY(Category = "Actra|EquipSlots", VisibleAnywhere, BlueprintReadOnly)
	UEquipSlot* SlotNudeFeet;

	virtual void FromRow(FName Key) override;

	virtual void UpdatePoly() override;

};