// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UiMouse.generated.h"

/**
 * 
 */

class APlayerController;
class UCanvasPanelSlot;
class UCanvasPanel;
class UNamedSlot;
class UUiMouseCursor;

UCLASS()
class ONE_API UUiMouse: public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APlayerController* PC;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCanvasPanelSlot* OuterSlot;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UNamedSlot* StyleSlot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector2D MousePosition;

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	 
	void CenterMouse();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiMouseStyle* Style;
	UFUNCTION(BlueprintImplementableEvent)
	UUiMouseStyle* CreateDefaultStyle();

};
/**
UCLASS()
class ONE_API UUiMouseCursor : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiMouseStyle* Style;
	UFUNCTION(BlueprintImplementableEvent)
	UUiMouseStyle* CreateDefaultStyle();
};
*/

UCLASS()
class ONE_API UUiMouseStyle : public UUserWidget
{
	GENERATED_BODY()

public:

};