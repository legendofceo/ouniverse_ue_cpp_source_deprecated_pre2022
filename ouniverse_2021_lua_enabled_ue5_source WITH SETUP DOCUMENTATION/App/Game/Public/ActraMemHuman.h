// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActraMem.h"
#include "ActraMemHuman.generated.h"

class UHeadHuman;
class UHairHuman;
class UBodyMemHuman;
class UEquipRackHuman;
class UVizRack;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UActraMemHuman : public UActraMem
{
	GENERATED_BODY()

	static const FName SYS;

public:

	virtual void BeginInit() override;

	virtual bool Validate() override;

	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="#BeginInitBP"))
	void BeginInitBP();

	UPROPERTY(VisibleAnywhere)
	UEquipRackHuman* EquipRackHuman;

	UPROPERTY(VisibleAnywhere)
	UVizRack* VizRack;

	UPROPERTY(VisibleAnywhere)
	UHeadHuman* HeadHuman;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UHeadHuman> HeadHumanClass = nullptr;

	/**
	UPROPERTY(VisibleAnywhere)
	UHairHuman* HairHuman;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UHairHuman> HairHumanClass = nullptr;
	*/

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBodyMemHuman* BodyMemHuman;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBodyMemHuman> BodyHumanClass = nullptr;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#AddItem"))
	void AddItem() {};

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#AddItem"))
	void AddItemAndEquip() {};


};