//Copyright 2015-2019, All Rights Reserved.

#pragma once


#include "UiStyle.generated.h"


UENUM(BlueprintType)
enum class EUiStyle : uint8
{
	Undefined 		UMETA(DisplayName = "Undefined"),
	Default			UMETA(DisplayName = "Default"),
	Fantasy 		UMETA(DisplayName = "Fantasy"),
	Capitalis 		UMETA(DisplayName = "Capitalis"),
	EndOfTime		UMETA(DisplayName = "EndOfTime"),
	Modern			UMETA(DisplayName = "Modern"),
	DarkLord		UMETA(DisplayName = "DarkLord"),
};


USTRUCT(BlueprintType)
struct FUiStyle
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, meta = (Category = "Styles"))
	TSubclassOf<UUserWidget> Default;

};