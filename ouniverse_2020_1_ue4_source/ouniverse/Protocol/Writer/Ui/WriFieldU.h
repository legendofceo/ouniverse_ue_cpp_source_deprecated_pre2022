//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiEditText.h"
#include "WriFieldU.generated.h"

class UTextBlock;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriField : public UUiEditText
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void SetupWriField(FText inText, int InHelpID);


	UTextBlock* vDesc;

	UFUNCTION(BlueprintCallable)
	void RequireWriField(UTextBlock* InDesc);

private:

	int HelpID_;
};