// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "actra_b.h"
#include "LuaValue.h"
#include "LuaComponent.h"
#include "actra_human.generated.h"


class UBodyK;
class UDataK;
class UBodyshape;
class UInventoryK;
class UEquipmentK;


UCLASS(config = Game)
class UActraHumanLua : public ULuaComponent
{
	GENERATED_BODY()

public:

	UActraHumanLua();
};

UCLASS(config = Game)
class AActraHuman : public AActraB
{
	GENERATED_BODY()

public:
	AActraHuman();

	/** The main skeletal mesh associated with this Character (optional sub-object). */
	//UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//USlotComponent* MeshSkeletonAnim;

	UPROPERTY(Category = Body, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSoftClassPtr<UBodyshape> BodyType;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UDataK* Data;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBodyK* Body;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UInventoryK* Inventory;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UEquipmentK* Equipment;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	ULuaComponent* Lua;


	/** Name of the MeshComponent. Use this name if you want to prevent creation of the component (with ObjectInitializer.DoNotCreateDefaultSubobject). */
	static FName BodyNode;
	static FName InventoryNode;
	static FName EquipmentNode;
	static FName DataNode;
	static FName LuaNode;

	static FName MeshNameSkeletonAnim;
	static FName MeshNameSlotHead;
	static FName SlotTorsoName;
	static FName SlotLegsName;
	static FName SlotHandsName;
	static FName SlotFeetName;
	static FName OutfitComponentName;
	
	//~ Begin APawn Interface.
	virtual void PostInitializeComponents() override;


	UFUNCTION(BlueprintCallable)
	bool Permit();

	UFUNCTION()
	FLuaValue LUA_GetName();

	UFUNCTION()
	void OX(bool bOn);



};