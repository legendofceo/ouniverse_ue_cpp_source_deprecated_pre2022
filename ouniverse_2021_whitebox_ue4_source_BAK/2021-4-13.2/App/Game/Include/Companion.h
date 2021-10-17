// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal.h"
#include "Companion.generated.h"


class ACompanionActor;

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UCompanion : public UObject
{
	GENERATED_BODY()

public:

	UCompanion();

	void Init();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Key;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshal Marshal;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Marshal"))
	void DoMarshalBP();

//Companion Properties

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText FirstName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText LastName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText ShortName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Strength;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Agility;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Intelligence;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Wisdom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Spirit;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Charm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Charisma;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTexture2D* IconLarge;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ACompanionActor* EmbodyActra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<ACompanionActor> CompanionActorClass;
};
