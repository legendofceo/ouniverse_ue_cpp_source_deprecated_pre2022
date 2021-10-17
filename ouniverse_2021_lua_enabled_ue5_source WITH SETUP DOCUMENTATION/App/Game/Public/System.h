// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Delegate.h"
#include "System.generated.h"


UCLASS()
class APP_API USystem : public UObjectPlus
{
	GENERATED_BODY()
	
public:	

	USystem();

	void SetInitCallback(FDelBasicObject OnInitComplete);

	virtual void Init();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit = false;

	void InitComplete();


	FDelBasicObject InitCompleteCB;

};
