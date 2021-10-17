// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "HeroData.generated.h"

class UActraMem;
class UTexture2d;

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FHeroData : public FTableRowBase
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere)
	FName Actra;

	UPROPERTY(EditAnywhere)
	bool bActive = false;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2d> PlaythroughPortrait;

	UPROPERTY(VisibleAnywhere);
	UActraMem* ActraMem = nullptr;


};
