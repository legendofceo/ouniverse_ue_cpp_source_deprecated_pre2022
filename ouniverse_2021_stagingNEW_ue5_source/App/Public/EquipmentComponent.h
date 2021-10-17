// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EquipmentComponent.generated.h"






USTRUCT(Blueprintable, BlueprintType)
struct APP_API FEquipedObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	UObject* Object;

	UPROPERTY(VisibleAnywhere)
	bool bPending;

};

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FEquipSlot
{
	GENERATED_BODY()

public:

	FEquipedObject* EquipedObject;

	UPROPERTY(VisibleAnywhere)
	UObject* ObjectReference;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Actra), meta = (BlueprintSpawnableComponent))
class APP_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UEquipmentComponent();

protected:

public:

	void Init(int Max);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FEquipSlot> Slots;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TArray<FEquipedObject> EquipedObjects;

};