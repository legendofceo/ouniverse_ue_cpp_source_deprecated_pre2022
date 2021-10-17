//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "UiEditText.generated.h"

class UEditableText;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiEditText : public UUiFocus
{

	GENERATED_BODY()


public:
	virtual void NativeConstruct() override;


	void SetupEditText(int ID, UUiBase* InRelay);

	UEditableText* vText;

	int ID_;

	UUiBase* Relay_;

	UFUNCTION(BlueprintCallable)
	void Require(UEditableText* InText);

	void SetText(FText InText);

};