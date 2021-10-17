//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriAtlasU.generated.h"


class WriAtlasP;
class AtlasC;

class UTextBlock;
class UWriField;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriAtlas : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriAtlasP* InPro);

	WriAtlasP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscUID;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vUID;

	UPROPERTY(meta = (BindWidget))
	UWriField* vID;

	UPROPERTY(meta = (BindWidget))
	UWriField* vTitle;
	
	UPROPERTY(meta = (BindWidget))
	UWriField* vDesc;

	UPROPERTY(meta = (BindWidget))
	UWriField* vAuthor;

	UPROPERTY(meta = (BindWidget))
	UWriField* vWebsite;

	void OpenUI(AtlasC* InAtlas);

	static enum REG {
		RID,
		RTitle,
		RAuthor,
		RDesc,
		RWebsite,
	};

};