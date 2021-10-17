//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "App/ControlData.h"
#include "UiButton.generated.h"

class UUiBase;
class UTextBlock;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiButton : public UUiFocus
{

	GENERATED_BODY()

public:

	void SetupButton(int InID, UUiBase* InRelay);

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

	void ButtonLock();
	void ButtonUnlock();

	UFUNCTION(BlueprintImplementableEvent)
	void ButtonLockBP();
	UFUNCTION(BlueprintImplementableEvent)
	void ButtonUnlockBP();

	UFUNCTION(BlueprintImplementableEvent)
	void HoveredBP();
	UFUNCTION(BlueprintImplementableEvent)
	void UnhoveredBP();

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedBP();
	UFUNCTION(BlueprintImplementableEvent)
	void UnselectedBP();

	bool OnStroke(const FFKey& InStroke) override;

	UTextBlock* Text_;

	void SetText(FText InText);

	UFUNCTION(BlueprintCallable)
	void Require(UTextBlock* InText);

private:

	int ID_;
	UUiBase* Relay_;
	bool bPressed;

	bool bLocked;

};