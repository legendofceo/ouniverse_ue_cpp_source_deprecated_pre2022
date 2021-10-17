//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriDataCreateU.generated.h"

class WriDataCreateP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriDataCreate : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void UiConstruct(WriDataCreateP* InPro);

	WriDataCreateP* Pro_;
};