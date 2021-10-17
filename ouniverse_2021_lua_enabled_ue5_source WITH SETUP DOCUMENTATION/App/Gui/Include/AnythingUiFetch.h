// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnythingUiFetch.generated.h"


class UAnythingUi;
struct FAnythingUiFetch;

DECLARE_DELEGATE_OneParam(FDelMulticastAnythingUiFetch,FAnythingUiFetch&)


USTRUCT(Blueprintable,BlueprintType)
struct APP_API FAnythingUiFetch
{

	GENERATED_BODY()

public:

	FDelMulticastAnythingUiFetch Func;

	UPROPERTY()
	UAnythingUi* AnythingUi;

	UPROPERTY()
	int Iteration;

};

UCLASS()
class APP_API UAnythingUiFetchUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, category=Fetch, meta=(DisplayName="#Fetch Complete: AnythingUi"))
	static void FetchAnythingUiCompleteBP(UPARAM(ref) FAnythingUiFetch& Fetch, UAnythingUi* AnythingUi);


};