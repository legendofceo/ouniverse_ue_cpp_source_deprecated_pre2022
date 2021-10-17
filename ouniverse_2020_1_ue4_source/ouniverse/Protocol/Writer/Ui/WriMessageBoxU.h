//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriMessageBoxU.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriMessageBox : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

};