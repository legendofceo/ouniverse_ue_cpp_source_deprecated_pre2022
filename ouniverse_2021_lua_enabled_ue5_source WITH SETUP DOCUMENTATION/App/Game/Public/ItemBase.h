// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.generated.h"


struct FTableRowBase;
class UItemOld;

UCLASS(Blueprintable, BlueprintType)
class APP_API UItemBase : public UObject
{
	GENERATED_BODY()


public:

	UItemBase();

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FName KeyID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int NumID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Test;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UUserWidget> Icon;

	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("ItemBase", GetFName());
	}

	void DataFromTable(FName RowKey, FTableRowBase* TableData);

};