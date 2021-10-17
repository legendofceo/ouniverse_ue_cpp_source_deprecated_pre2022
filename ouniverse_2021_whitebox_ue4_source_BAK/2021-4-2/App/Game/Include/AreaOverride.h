// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaAddress.h"
#include "AreaOverride.generated.h"

class UArea;

UCLASS()
class APP_API UAreaOverride : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	UArea* Area_ = NULL;

	UPROPERTY(VisibleAnywhere)
	FAddress Address_;

	UFUNCTION(BlueprintCallable,meta = (DisplayName="#Set Area Override"))
	void SetAreaOverride(UArea* Area, FAddress Address);

	bool IsActive();
};
