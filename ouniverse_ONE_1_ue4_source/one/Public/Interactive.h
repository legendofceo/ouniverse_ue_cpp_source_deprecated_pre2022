// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/BoxComponent.h"
#include "Interactive.generated.h"

/**
 * 
 */


class UInteractive;
class AActra;
class APC;

UCLASS(BlueprintType, Blueprintable)
class ONE_API UInteractor : public UBoxComponent
{
	GENERATED_BODY()

public:

	UInteractor();

	virtual void BeginPlay() override;

	void Update();

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Num = 0;

	UFUNCTION()
	bool UpdateResults(float DeltaTime);

	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//UUiHudInteractive* HudInteractive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<AActor*, UInteractive*> InteractiveList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInteractive* ActiveInteractive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInteracting;

};


UCLASS()
class ONE_API UUiInteractiveIcon: public UUserWidget
{
	GENERATED_BODY()

public:


};

UCLASS()
class ONE_API UUiInteractiveFlag : public UUserWidget
{
	GENERATED_BODY()

public:


};

UCLASS()
class ONE_API UUiInteractiveMenu: public UUserWidget
{
	GENERATED_BODY()

public:


};

UCLASS()
class ONE_API UInteractive : public UObject
{
	GENERATED_BODY()

public:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiInteractiveIcon* Icon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiInteractiveFlag* Flag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiInteractiveMenu* Menu;

};