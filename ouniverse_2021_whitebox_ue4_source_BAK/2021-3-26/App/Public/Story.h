// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AreaAddress.h"
#include "Story.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActivateStoryComplete, UStory*, Story);

class UCompanion;
class UParty;
class ULogic;
struct FStoryMem;

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UStory : public UObject
{
	GENERATED_BODY()

public:

	UStory() {};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParty* Party;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Key = 0;

	void Init();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Initialized;

	UFUNCTION(BlueprintCallable)
	void SetKey(int NewKey);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int, UCompanion*> Companions;

	UFUNCTION(BlueprintCallable)
	UCompanion* AddCompanion(UCompanion* Companion);

	UFUNCTION(BlueprintCallable)
	UCompanion* GetCompanion(int CompanionKey);

//AreaAddress Override

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress AreaAddressOverride;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Set AreaAddress Override"))
	void SetAreaAddressOverride(FAreaAddress AreaAddress);

	bool HasAreaAddressOverride();

	FAreaAddress GetAreaAddressOverride();

	void ClearAreaAddressOverride();

//Mem

	FStoryMem* Mem;

	virtual void SetMem(FStoryMem* CompanionMem);

	UStory* Obtain();


	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Obtained"))
	void DoObtained();

	UFUNCTION(Category = "Story", BlueprintCallable, meta = (DisplayName = "#Obtain Story"))
	void ObtainBP(UStory*& Story);

	bool IsObtained();
	
	UFUNCTION(Category = "Story", BlueprintCallable, meta = (DisplayName = "#Is Obtained", ExpandEnumAsExecs = Execs))
	void IsObtainedBP(EYesNo& Execs);

	UParty* GetParty();

	UFUNCTION(Category = "Story", BlueprintCallable, meta = (DisplayName = "#Get Party"))
	void GetPartyBP(UParty*& OutParty);

	UPROPERTY(BlueprintAssignable)
	FActivateStoryComplete OnActivateStoryComplete;

};