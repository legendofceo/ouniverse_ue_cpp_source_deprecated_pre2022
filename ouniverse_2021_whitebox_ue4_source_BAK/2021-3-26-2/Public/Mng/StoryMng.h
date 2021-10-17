// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StoryMng.generated.h"

class APlaythrough;
class UPartyMng;
class UAreaMng;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UStoryMng : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStoryMng();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	void Init();

	void InitII(APlaythrough* InPlaythrough, UPartyMng* InPartyMng, UAreaMng* InAreaMng);

	UPROPERTY(BlueprintReadOnly)
	UPartyMng* PartyMng;

	UPROPERTY(BlueprintReadOnly)
	UAreaMng* AreaMng;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	APlaythrough* Playthrough;


	UFUNCTION()
	void Start();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
