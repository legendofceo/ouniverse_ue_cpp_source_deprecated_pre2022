// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "LatentQue.h"
#include "TroopRemote.generated.h"

struct FPact;
class UActraMem;
class AActraEx;

UCLASS(BlueprintType)
class APP_API UActraHandle : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:


	UPROPERTY(VisibleAnywhere)
	UActraMem* ActraMem;
	UPROPERTY(VisibleAnywhere)
	AActraEx* ActraEx;

	void SetActra(UActraMem* InActra);

	void Spawn3d(FDelBasic Callback);
	UFUNCTION()
	void Spawn3d_Stream();

	FDelBasic Spawn3dComplete;

};

UCLASS(BlueprintType)
class APP_API UTroopRemote : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	FPact* Pact;

	void ChangePact(FPact* NewPact, FDelBasic Callback);

	FDelBasic OnChangePactComplete;

	UPROPERTY(VisibleAnywhere)
	TArray<UActraHandle*> ActraHandles;

	UPROPERTY(VisibleAnywhere)
	FLatentQue SpawnQue;

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#SetTroopPosition"))
	void SetTroopPosition(FTransform Transform);

	void Engage();

};
