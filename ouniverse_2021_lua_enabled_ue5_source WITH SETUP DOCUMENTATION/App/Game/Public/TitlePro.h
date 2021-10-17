// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol.h"
#include "TitlePro.generated.h"

class UTitleMenuUi;


UENUM(Blueprintable)
enum class ETitleProOptions: uint8
{
	None		UMETA(DisplayName = "None"),
	NewGame		UMETA(DisplayName = "NewGame"),
	LoadGame	UMETA(DisplayName = "LoadGame"),
	User		UMETA(DisplayName = "User"),
	News		UMETA(DisplayName = "News"),
	Settings	UMETA(DisplayName = "Settings"),
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UTitlePro : public UProtocol
{
	GENERATED_BODY()

	static const FName SYS;

public:
	// Sets default values for this component's properties
	UTitlePro();

public:

	static UTitlePro* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DisplayName=":TitlePro"))
	static void GetBP(UTitlePro*& TitlePro);
	
	void Init() override;

	void Engage();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Engage"))
	void EngageBP();

	UFUNCTION(BlueprintCallable , meta = (DisplayName = "#OptionBegin"))
	void OptionBeginBP();

};
