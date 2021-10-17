// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Marshal/Marshal.h"
#include "AreaAddress.h"
#include "Party.h"
#include "../Enum/EBranch.h"
#include "Story.generated.h"



UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API AStory : public AInfo
{
	GENERATED_BODY()

public:

	AStory() {};

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshalNew Marshal;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Marshal"))
	void DoMarshalBP(FMarshalNew& MarshalHandle);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress AreaAddressOverride;

	UPROPERTY()
	FParty Party;

	UPROPERTY()
	FCompany Company;


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set AreaAddress Override"))
	void SetAreaAddressOverride(FAreaAddress AreaAddress);

	bool HasAreaAddressOverride();

	FAreaAddress GetAreaAddressOverride();

	void ClearAreaAddressOverride();

//Mem

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (DisplayName = "#IsAvailable", ExpandEnumAsExecs = Branch))
	void IsAvailable(EYesNo& Branch);
	void IsAvailable_Implmentation(EYesNo& Branch);

};