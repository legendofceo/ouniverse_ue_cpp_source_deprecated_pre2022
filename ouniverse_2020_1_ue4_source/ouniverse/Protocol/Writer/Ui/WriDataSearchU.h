//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "Interface/Array.h"
#include "WriDataSearchU.generated.h"


class WriDataSearchP;
class WriDataP;

class AtlasLibC;

class UTextBlock;
class UUiButton;
class UEditableText;
class UUiScroll;

class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriDataSearch : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	void UiConstruct(WriDataSearchP* InPro, WriDataP* InDataPro, AtlasLibC* InAtlasLib);

	WriDataSearchP* Pro_;
	AtlasLibC* AtlasLib_;
	WriDataP* DataPro_;


	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscFilters;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscOptions;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vQuery;

	UPROPERTY(meta = (BindWidget))
	UUiScroll* vScroll;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vData;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vRevision;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vAmmend;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vNew;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vDelete;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vSearch;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscView;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vView0;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vView1;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vView2;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vMaster;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vSupport;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vJson;

	UFUNCTION()
	void OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	void Query();

	ArrayC<FormDataC*> FormRefs_;

	static enum REG {
		RQuery,
		RScroll,
		RData,
		RRevision,
		RAmmend,
		RNew,
		RDelete,
		RSearch,
		RView0,
		RView1,
		RView2,
		RMaster,
		RSupport,
		RJson,
	};
};