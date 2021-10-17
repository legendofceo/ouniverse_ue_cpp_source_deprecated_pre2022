// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Chassis.generated.h"

class AActraEx;
class USkeletalMesh;
class USkeletalMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UChassis : public UObject
{
	GENERATED_BODY()

	static const FName SYS;


public:

	UPROPERTY(VisibleAnywhere)
	AActraEx* ActraEx;

	void Init(AActraEx* InActra);

	UPROPERTY()
	USkeletalMeshComponent* SMC;

	void SetSkeletalMeshComponent(USkeletalMeshComponent* InSMC);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMesh* SkeletalMesh;

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#AddDynamicSkeletalMeshComponent"))
	USkeletalMeshComponent* AddDynamicSkeletalMeshComponent();

	UPROPERTY(VisibleAnywhere)
	TArray<USkeletalMeshComponent*> DynamicSkeletalMeshComponents;

};