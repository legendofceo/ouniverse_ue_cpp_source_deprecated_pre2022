// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Marshal/Marshal.h"
#include "AreaAddress.h"
#include "Party.h"
#include "../Enum/EBranch.h"
#include "Story.generated.h"



UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UStory : public UObject
{
	GENERATED_BODY()

public:

	UStory() {};
	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Key;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMarshal Marshal;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Marshal"))
	void DoMarshalBP(FMarshal& MarshalHandle);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress AreaAddressOverride;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void Init();


	void PreStart();
	
	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "@PreStart"))
	void PreStartBP();
	virtual void PreStartBP_Implementation();

	UPROPERTY(VisibleAnywhere)
	FParty Party;

	UPROPERTY(VisibleAnywhere)
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