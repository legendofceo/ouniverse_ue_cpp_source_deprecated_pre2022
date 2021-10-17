// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleNewGamePro.generated.h"

class UBT;
class UCanvasPanel;
class UTitleNewGameOptionsUi;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UTitleNewGamePro : public UObject
{
	GENERATED_BODY()

		static const FName SYS;

public:

	void Run();

	UPROPERTY(VisibleAnywhere)
	UTitleNewGameOptionsUi* NewGameOptions = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UTitleNewGameOptionsUi> TitleNewGameOptionsUiClass = nullptr;

};


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UTitleNewGameOptionsUi : public UUserWidget
{
	GENERATED_BODY()

public:


};
