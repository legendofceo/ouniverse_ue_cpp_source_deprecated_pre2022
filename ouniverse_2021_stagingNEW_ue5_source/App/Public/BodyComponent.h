// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Keyword.h"
#include "BodyComponent.generated.h"


class UKeywordComponent;
class AActraHuman;

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Global), meta = (BlueprintSpawnableComponent))
class APP_API UBodyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBodyComponent();

	virtual void BeginPlay() override;

	void Init();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AActraHuman* ActraHuman;

	UKeywordComponent* KeywordComponent;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<FKeyword> AutoKeywords;

};
