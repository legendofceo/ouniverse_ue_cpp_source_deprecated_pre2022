// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "body_k.generated.h"

class UBodyshape;
class UEquipSlot;
class USkeletalMeshComponent;

UCLASS()
class UBodyK : public UActorComponent
{
	GENERATED_BODY()

public:

	UBodyK();

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftClassPtr<UBodyshape> ShapeType;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBodyshape* Shape;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FColor SkinTone;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> MatHeadDiffuse;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> MatBustDiffuse;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> MatLegsDiffuse;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> MatFeetDiffuse;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> MatHandsDiffuse;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Sweat;
	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Wet;

	UFUNCTION()
	void OX(bool bOn);

	static FName ShapeNode;

};




UCLASS(Blueprintable, BlueprintType, config = Game)
class UBodyshape : public UActorComponent
{
	GENERATED_BODY()

public:

	UBodyshape();

	//UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//USkeletalMeshComponent* 

	//UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//UBodyHuman_Region* Head;
	//UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//UBodyHuman_Region* Torso;
	//UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//UBodyHuman_Region* Legs;
	//UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//UBodyHuman_Region* Hands;
	//UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//UBodyHuman_Region* Feet;

	UFUNCTION()
	void OX();

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Skeleton_Full;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Skeleton_Body;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Nude_Bust;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Nude_Legs;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Nude_Hands;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Nude_Feet;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Head;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Bust;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Legs;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Undershirt;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Intimates;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Hands;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Stockings;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Feet;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Harness;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Cape;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Hat;

	UPROPERTY(Category = Body, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipSlot* Hair;

	static FName EqSlotHeadNode;
	static FName EqSlotBustNode;
	static FName EqSlotLegsNode;
	static FName EqSlotUndershirtNode;
	static FName EqSlotIntimatesNode;
	static FName EqSlotHandsNode;
	static FName EqSlotStockingsNode;
	static FName EqSlotFeetNode;
	static FName EqSlotHarnessNode;
	static FName EqSlotCapeNode;
	static FName EqSlotHatNode;
	static FName EqSlotHairNode;



};