// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InterfaceInput.h"
#include "Behavior.generated.h"

class UActraState;
class AActra;

class USchema;


UENUM(BlueprintType)
enum EHumanLocomotionSchema
{
	HumanLocomotionSchemaFoot	UMETA(DisplayName = "Foot"),
	HumanLocomotionSchemaClimb	UMETA(DisplayName = "Climb"),
	HumanLocomotionSchemaGlide	UMETA(DisplayName = "Glide"),
	HumanLocomotionSchemaSwim	UMETA(DisplayName = "Swim"),
	HumanLocomotionSchemaFly	UMETA(DisplayName = "Fly"),
};

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONE_API UBehavior : public UActorComponent, public IInterfaceInput
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBehavior();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Pilot();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Actra;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USchema* BaseBehavior;

	virtual void Command_Implementation(UCommand* Command) override;

	virtual void CommandAxis_Implementation(UCommandAxis* Command) override;

	UFUNCTION(BlueprintImplementableEvent)
	void InputCommand(UCommand* Command);

	UFUNCTION(BlueprintImplementableEvent)
	void InputCommandAxis(UCommandAxis* CommandAxis);
};