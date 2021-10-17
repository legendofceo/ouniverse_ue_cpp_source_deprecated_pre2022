// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CompanionTable.generated.h"

class UTexture2D;
class ACompanionActor;

USTRUCT(BlueprintType)
struct FCompanionTable : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText FirstName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText LastName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText ShortName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Wisdom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Spirit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Charm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Charisma;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Level;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* IconLarge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<ACompanionActor> EmbodyActraClass;


};
