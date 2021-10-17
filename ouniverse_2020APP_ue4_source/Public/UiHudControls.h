// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UiHudControls.generated.h"

/**
 * 
 */

UCLASS()
class ETREIAAPP_API UControlSchema : public UUserWidget
{
	GENERATED_BODY()

};

UCLASS()
class ETREIAAPP_API UControlSchemaRaw : public UControlSchema
{
	GENERATED_BODY()

};


UCLASS()
class ETREIAAPP_API UControlSchemaStandard : public UControlSchema
{
	GENERATED_BODY()

};


UCLASS()
class ETREIAAPP_API UUiHudControls : public UUserWidget
{
	GENERATED_BODY()
	
};
