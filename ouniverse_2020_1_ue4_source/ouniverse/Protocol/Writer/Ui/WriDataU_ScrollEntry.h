//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiScrollEntry.h"
#include "WriDataU_ScrolLEntry.generated.h"


class AtlasC;
class WriDataP;

class UImage;
class UTextBlock;
class UUiMouseInput;

//class UUiBool;
class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriData_ScrollEntry : public UUiScrollEntry
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWriData_ScrollEntry* Create(WriDataP* InDataPro, FormDataC* InFormData);

	void Init(WriDataP* InDataPro, FormDataC* InFormData);

	FormDataC* FormData_;
	WriDataP* DataPro_;

	bool bSelected_;

	UPROPERTY(meta = (BindWidget))
	UImage* vType;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* vTitle;
	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* vSelect;

	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* vOpen;

	/**
	UPROPERTY(meta = (BindWidget))
	UUiBool* vUnsaved;
	UPROPERTY(meta = (BindWidget))
	UUiBool* vOpen;
	UPROPERTY(meta = (BindWidget))
	UUiBool* vError;
	*/


	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;


	void BoolSelectedToggle();

	UFUNCTION(BlueprintImplementableEvent)
	void BoolSelectedOn();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolSelectedOff();

	static enum REG {
		MiOpen,
		MiSelect,
	};
};