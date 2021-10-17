//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiBase.h"
#include "UiFocus.generated.h"

class ProtocolC;
class FocusUiC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiFocus : public UUiBase
{

	GENERATED_BODY()

public:

	FocusUiC* Focus_;
	
	void SetupFocus(FocusUiC* InFocus);

	void Focus_Mechanism();
	void Unfocus_Mechanism();

	UFUNCTION(BlueprintImplementableEvent)
	void FocusBP();
	UFUNCTION(BlueprintImplementableEvent)
	void UnfocusBP();

};