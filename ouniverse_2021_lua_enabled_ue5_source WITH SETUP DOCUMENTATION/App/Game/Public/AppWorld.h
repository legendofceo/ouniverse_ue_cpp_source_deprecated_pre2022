// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AppWorld.generated.h"


class UWorld;

UCLASS()
class APP_API UAppWorld : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit = false;

	static UAppWorld* Get();
	static UWorld* GetAppWorld();
	static UObject* GetAppWorldContextObject();

	void Init(UWorld* InWorld, UObject* InWorldContextObject);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UObject* WorldContextObject;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UWorld* World;


};
