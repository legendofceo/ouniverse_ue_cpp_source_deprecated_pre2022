//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "CnsTrayU.generated.h"


class CnsTrayP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UCnsTray : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(CnsTrayP* InPro);

	CnsTrayP* Pro_;
};