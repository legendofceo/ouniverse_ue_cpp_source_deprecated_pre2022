//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriFileU.generated.h"

class WriFileP;

class UTextBlock;
class UUiButton;
class UUiScroll;

class AtlasLibC;
class WriLoadoutC;

class UWriFile_ScrollEntry;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriFile : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriFileP* InPro, AtlasLibC* InAtlasLib);

	WriFileP* Pro_;

	AtlasLibC* AtlasLib_;

	bool FirstDraw_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscStatus;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vStatus;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vSave;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vLoad;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vUnload;
	

	UPROPERTY(meta = (BindWidget))
	UUiButton* vNew;
	
	UPROPERTY(meta = (BindWidget))
	UUiButton* vDelete;

	UPROPERTY(meta = (BindWidget))
	UUiScroll* vScroll;

	UFUNCTION(BlueprintImplementableEvent)
	void UiOpenBP();

	void OpenUi();

	UWriFile_ScrollEntry* MasterEntry_;

	void MasterSet(UWriFile_ScrollEntry* InMaster);
	void MasterCleared();

	static enum REG {
		RSave,
		RLoad,
		RUnload,
		RNew,
		RDelete,
	};

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget);

	void SetData(WriLoadoutC* InData);

	void UnloadedMode();

	void LoadedMode();

};