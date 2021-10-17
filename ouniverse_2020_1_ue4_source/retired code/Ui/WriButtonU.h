//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiButton.h"
#include "WriButtonU.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiButton : public UUiButton
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

};