//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriMainU.generated.h"

class UUiButton;
class WriMenuP;

class UWriFile;
class UWriAtlas;
class UWriData;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriMenu : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriMenuP* InPro);

	WriMenuP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vLoadout;
	UPROPERTY(meta = (BindWidget))
	UUiButton* vAtlas;
	UPROPERTY(meta = (BindWidget))
	UUiButton* vData;
	UPROPERTY(meta = (BindWidget))
	UUiButton* vWorld;
	UPROPERTY(meta = (BindWidget))
	UUiButton* vTools;
	UPROPERTY(meta = (BindWidget))
	UUiButton* vExit;
	   	 

	UPROPERTY(meta = (BindWidget))
	UWriFile* View_Loadout;
	UPROPERTY(meta = (BindWidget))
	UWriAtlas* View_Atlas;
	UPROPERTY(meta = (BindWidget))
	UWriData* View_Form;

	static enum REG {
		RLoadout,
		RAtlas,
		RData,
		RWorld,
		RTools,
		RExit,

	};

	void DataLoad();
	void DataUnload();

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

};