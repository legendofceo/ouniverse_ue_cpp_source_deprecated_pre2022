//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiScrollEntry.h"
#include "WriFileU_ScrollEntry.generated.h"


class AtlasC;
class UWriFile;
class UUi_Bool;
class UImage;
class UTextBlock;
class UUiMouseInput;
class UWriFile;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriFile_ScrollEntry : public UUiScrollEntry
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWriFile_ScrollEntry* Create(UWriFile* InView, AtlasC* InAtlas);

	void Init(UWriFile* InView, AtlasC* InAtlas);

	AtlasC* Atlas_;
	UWriFile* View_;

	bool AtlasMaster_;
	bool AtlasActive_;

	UPROPERTY(meta = (BindWidget))
	UImage* vFormType;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* vTitle;
	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* vMiMaster;
	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* vMiSupport;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;


	void BoolMasterToggle(bool FromView);
	void BoolActiveToggle();

	UFUNCTION(BlueprintImplementableEvent)
	void BoolMasterOn();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolMasterOff();

	UFUNCTION(BlueprintImplementableEvent)
	void BoolActiveOn();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolActiveOff();

	static enum REG {
		BoolMaster,
		BoolActive,
	};
};