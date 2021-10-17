// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "Reg.generated.h"

class UUi;
class UPauseWin;
class UWIN_Title;
class UOmniWin;
class UAct;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UReg : public UObject
{

	GENERATED_BODY()

public:

	static void Initialize();

	static UReg* Get();

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TSubclassOf<UUi>				UiWin_;

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TSubclassOf<UPauseWin>			PauseWin_;
	
	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TSubclassOf<UWIN_Title>			TitleWin_;

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TSubclassOf<UOmniWin>			OmniWin_;

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TMap<FName, TSoftClassPtr<UAct>>		   ActMap_;
};