// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Marshal/Marshal.h"
#include "Companion.generated.h"


class ACompanionActor;

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API ACompanion : public AInfo
{
	GENERATED_BODY()

public:

	ACompanion();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshalNew Marshal;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSoftClassPtr<ACompanionActor> EmbodyActraClass;
};
