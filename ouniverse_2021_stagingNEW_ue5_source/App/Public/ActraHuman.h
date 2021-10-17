// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ActraHuman.generated.h"

class UKeywordComponent;
class UEquipmentComponent;
class UBodyComponent;
class UHeadComponent;

UCLASS(Blueprintable, BlueprintType)
class APP_API AActraHuman : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActraHuman();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UKeywordComponent* KeywordComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UEquipmentComponent* EquipmentComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBodyComponent* BodyComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UHeadComponent* HeadComponent;


};
