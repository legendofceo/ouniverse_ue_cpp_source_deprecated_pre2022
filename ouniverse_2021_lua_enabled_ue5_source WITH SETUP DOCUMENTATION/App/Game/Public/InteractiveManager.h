// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Delegate.h"
#include "InteractiveManager.generated.h"

class UInteractiveComponent;
class UInteractorComponent;

class UBT;
class UHudInteractorUi;



UCLASS()
class APP_API UInteractiveManager : public USystem
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UInteractiveManager();

	void Init() override;

	static UInteractiveManager* Get();

	void AddInteractiveComponent(UInteractiveComponent* InteractiveComponent);
	void RemoveInteractiveComponent(UInteractiveComponent* InteractiveComponent);

	UPROPERTY(VisibleAnywhere)
	TArray<UInteractiveComponent*> InteractiveComponents;

	TArray<UInteractiveComponent*>& GetRelevantInteractiveComponents();

};
