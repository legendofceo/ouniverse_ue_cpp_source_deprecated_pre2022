// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager.h"
#include "AreaAddress.h"
#include "AreaManager.generated.h"

class UArea;
struct FZone;



UCLASS()
class APP_API UAreaManager : public UManager
{
	GENERATED_BODY()

public:

	UAreaManager();

	void Init();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress PendingAreaAddress;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress AreaAddress;

	void ChangeArea(UArea* NextArea, FAddress NextAddress);

	UFUNCTION()
	void AreaUnloaded();

	FZone* ActiveZone;

	void LoadZone(FZone* Zone);


};
