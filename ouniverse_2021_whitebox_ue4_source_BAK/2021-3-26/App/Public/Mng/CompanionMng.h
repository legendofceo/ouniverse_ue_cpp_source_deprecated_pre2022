// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Log.h"
#include "CompanionMng.generated.h"


class UPlaythrough;
class UCompanion;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UCompanionMng : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCompanionMng();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPlaythrough* Playthrough;

	void Init();
	void InitII(UPlaythrough* InPlaythrough);

};
