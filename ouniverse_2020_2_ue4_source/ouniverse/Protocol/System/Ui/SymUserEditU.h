//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "SymUserEditU.generated.h"

class SymUserEditP;
class UserLibC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymUserEdit : public UUiBaseNew
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;
	
	void UiConstruct(SymUserEditP* InPro);

	SymUserEditP* Pro_;
	UserLibC* UserLib_;

};