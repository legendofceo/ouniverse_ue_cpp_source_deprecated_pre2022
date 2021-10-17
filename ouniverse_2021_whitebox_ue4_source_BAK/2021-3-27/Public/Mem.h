// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Marshal/Marshal.h"
#include "Mem.generated.h"

class AStory;
class APlaythrough;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AMem: public AInfo
{
	GENERATED_BODY()

public:

	AMem();

protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshalNew Marshal;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	APlaythrough* Playthrough;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ACompanion*> Companions;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#AddCompanion"))
	void AddCompanion(ACompanion* Companion, FString Key, UPARAM(ref) ACompanion*& Param);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AStory*> Stories;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#AddStory"))
	void AddStory(AStory* Story, FString Key, UPARAM(ref) AStory*& Param);

};
