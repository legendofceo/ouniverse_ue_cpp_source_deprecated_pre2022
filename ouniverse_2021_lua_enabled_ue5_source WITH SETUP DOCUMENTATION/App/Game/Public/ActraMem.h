// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory.h"
#include "ActraMem.generated.h"

class AActraEx;


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UActraMem : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	void Init();

	virtual void BeginInit() {};

	virtual bool Validate();

	UPROPERTY(EditAnywhere)
	FName KeyID;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AActraEx> ActraExSoft;

	UPROPERTY(VisibleAnywhere)
	FInventory Inventory;



};