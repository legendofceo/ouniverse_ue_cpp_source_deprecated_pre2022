// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kit.generated.h"


UCLASS()
class APP_API UKit : public UObject
{
	GENERATED_BODY()
	
public:


	virtual void Connect() {};
	virtual void Disconnect() {};

};
