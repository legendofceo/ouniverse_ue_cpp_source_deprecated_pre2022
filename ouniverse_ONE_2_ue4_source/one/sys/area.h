// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/DataTable.h"
#include "UObject/SoftObjectPtr.h"
#include "base.h"
#include "log.h"
#include "LuaComponent.h"
#include "area.generated.h"

class ULevelStreamingDynamic;
class ACell;

class Form_F;

UCLASS()
class UAreaLua : public ULuaComponent
{
	GENERATED_BODY()

public:

	UAreaLua();
};

UCLASS(Blueprintable, BlueprintType, config = Game)
class ONE_API AArea : public ABase
{

	GENERATED_BODY()

public:

	AArea();
	
	void Constructor();

	static AArea* CreateFromData(AActor* WorldActor, Form_F* InData);

	static FName LuaNode;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	ULuaComponent* Lua;

	UPROPERTY(VisibleAnywhere, meta = (category = "0-Details"))
	FLogger Log;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cosm)
	FName UID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cosm)
	FString Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cosm)
	FString ActiveCell;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cosm)
	FName CosmSpark;

	TMap<FString,ACell*> LoadedCells;

	void Start();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();

	UFUNCTION(BlueprintCallable)
	void LoadCell(FName Catalyst);
	

};