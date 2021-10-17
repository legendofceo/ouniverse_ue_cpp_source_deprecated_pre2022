// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MouseUi.generated.h"

class UCanvasPanel;
class UCanvasPanelSlot;

UCLASS(Abstract, Blueprintable, BlueprintType)
class APP_API UMouseDartUi : public UUserWidget
{
	GENERATED_BODY()

public:
	
};

UCLASS(Abstract, Blueprintable, BlueprintType)
class APP_API UMouseUi : public UUserWidget
{
	GENERATED_BODY()

	static const FName SYS;

public:

	void Show();

	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY()
	UCanvasPanelSlot* CanvasSlot;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UUserWidget> DefaultDartSoft;

	void SetActiveDart(TSoftClassPtr<UUserWidget> DartSoft);
	void SetActiveDart_Stream(TSoftClassPtr<UUserWidget> DartSoft);

	UPROPERTY(VisibleAnywhere)
	UUserWidget* ActiveDart = nullptr;

	void Init();

	void Update(float MouseX, float MouseY);
};