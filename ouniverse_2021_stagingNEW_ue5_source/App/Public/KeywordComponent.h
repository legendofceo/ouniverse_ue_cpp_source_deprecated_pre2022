// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Keyword.h"
#include "KeywordComponent.generated.h"


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FKeywordEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	FKeyword Keyword;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	FName Source;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int UID;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Global), meta = (BlueprintSpawnableComponent))
class APP_API UKeywordComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKeywordComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FKeywordEntry> KeywordEntries;
	
	int AddKeyword(FKeyword Keyword, FName Source);

	int Ticket = 0;

};
