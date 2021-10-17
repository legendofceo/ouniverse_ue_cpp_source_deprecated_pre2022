//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriDataEditU.generated.h"

class WriDataEditP;

class UUiButton;
class UMultiLineEditableTextBox;
class UTextBlock;
class UUiPolyViewer;

class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriDataEdit : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void UiConstruct(WriDataEditP* InPro);

	WriDataEditP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vUID;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vAUID;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vDataMode;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vOutputMode;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vSave;

	UPROPERTY(meta = (BindWidget))
	UUiPolyViewer* vPoly;

	UPROPERTY(meta = (BindWidget))
	UMultiLineEditableTextBox* vOutput;

	void OpenForm(FormDataC* InFormData);

	static enum REG {
		RDataMode,
		ROutputMode,
		RSave,
		RVerify,
	};
};