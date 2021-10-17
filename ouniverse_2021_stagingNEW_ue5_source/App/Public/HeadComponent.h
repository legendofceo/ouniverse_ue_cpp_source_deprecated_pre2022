// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Keyword.h"
#include "HeadComponent.generated.h"

/**
 * 
 */

class AActraHuman;
class UKeywordComponent;

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Actra), meta = (BlueprintSpawnableComponent))
class APP_API UHeadComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:

	UHeadComponent();

	virtual void BeginPlay() override;

	void Init();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActraHuman* ActraHuman;

	UKeywordComponent* KeywordComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FKeyword> AutoKeywords;

};
