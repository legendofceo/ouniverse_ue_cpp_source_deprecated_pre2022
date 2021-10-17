// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InputRepeater.h"
#include "InteractorComponent.generated.h"


class UAnythingUi;
class UInteractiveComponent;

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class APP_API UInteractorComponent : public USceneComponent
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UInteractorComponent();

protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInteractiveComponent* Target = nullptr;

	void Init();



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAnythingUi* ActiveUi;

	UPROPERTY(VisibleAnywhere)
	FInputRepeater InputRepeater;

	void On();
	
	void Off();

	/**
	bool TryButtonKB(UButtonKB* BT);
	bool TryButtonGP(UButtonGP* BT);

	void TryTargetAxis(UBT* BT, bool bRight);
	*/

	void TabTarget(bool bLeft);

	void SetTarget(UInteractiveComponent* InteractiveComponent);
	void ClearTarget(bool bEmpty);
};