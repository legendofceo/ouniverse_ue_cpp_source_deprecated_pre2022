// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "App/Controllable.h"
#include "MyCharacter.generated.h"


UCLASS()
class OUNIVERSE_API AMyCharacter : public ACharacter, public IControllable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceControllable")
	bool OnCommand(const FFKey& InCommand);  // This is the prototype declared in the interface
	virtual bool OnCommand_Implementation(const FFKey& InCommand) override; 

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceControllable")
	bool OnAxis(const FFAxis& InCommand);  // This is the prototype declared in the interface
	virtual bool OnAxis_Implementation(const FFAxis& InCommand) override;

};
