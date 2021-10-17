// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "ActraExNew.generated.h"



USTRUCT(Blueprintable, BlueprintType)
struct APP_API FItemTest
{
	GENERATED_BODY()

public:

	FItemTest() {};

	UPROPERTY(EditAnywhere)
	FName ID;

	UPROPERTY(EditAnywhere)
	int Quantity;

	UPROPERTY(VisibleAnywhere)
	bool bEquipped;

	UPROPERTY(VisibleAnywhere)
	int EquipSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bBound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bNoloot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, int> Style;

};


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FInventoryNew
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<FItemTest> Items;


};



UCLASS(Abstract,Blueprintable,BlueprintType)
class APP_API UBodyDynamic : public UObject
{
	GENERATED_BODY()

public:

};

UCLASS(Abstract, Blueprintable, BlueprintType)
class APP_API UBodyDynamicHuman : public UBodyDynamic
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	USkeletalMesh* BodySkeleton;
	

};

UCLASS(Blueprintable, ClassGroup = (Actra), meta = (BlueprintSpawnableComponent))
class APP_API UBodyDynamicDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:

};

UCLASS(Blueprintable, ClassGroup = (Actra), meta = (BlueprintSpawnableComponent))
class APP_API UBodyDynamicDataHumanComponent : public UBodyDynamicDataComponent
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere)
	FName BodyID;

	UPROPERTY(EditAnywhere)
	FColor SkinTone;

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	FInventoryNew* InventoryData;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UInventoryComponentReal : public UInventoryComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FInventoryNew InventoryData;
};

UCLASS(BlueprintType, Blueprintable)
class APP_API AActra : public ACharacter
{
	GENERATED_BODY()

	static const FName SYS;

public:

	AActra();

	UPROPERTY(EditAnywhere)
	FName MemID;

};



UCLASS(BlueprintType, Blueprintable)
class APP_API AActraDynamic : public AActra
{
	GENERATED_BODY()

	static const FName SYS;

public:

	AActraDynamic() {};

};