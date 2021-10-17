//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriInfoU.generated.h"

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriInfo : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

};