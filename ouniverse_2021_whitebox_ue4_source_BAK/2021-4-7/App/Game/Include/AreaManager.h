// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaAddress.h"
#include "AreaManager.generated.h"

class UArea;
struct FZone;



UCLASS()
class APP_API UAreaManager : public UObject
{
	GENERATED_BODY()

public:

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
