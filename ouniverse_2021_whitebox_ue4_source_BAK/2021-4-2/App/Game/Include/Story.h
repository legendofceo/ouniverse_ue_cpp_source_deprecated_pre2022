// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mem.h"
#include "Party.h"
#include "Company.h"
#include "Execs.h"
#include "Story.generated.h"


class UAreaOverride;

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UStory : public UMem
{
	GENERATED_BODY()

public:

	UStory() {};
	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Key;

	void Init();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	void PreStart();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@StartPre"))
	void PreStartBP();


	void PostStart(UAreaOverride* AreaOverride);
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@StartPost"))
	void PostStartBP(UAreaOverride* AreaOverride);

	UPROPERTY(VisibleAnywhere)
	FParty Party;

	UPROPERTY(VisibleAnywhere)
	FCompany Company;


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Add Companion To Party"))
	void AddCompanionToParty(UCompanion* Companion);

};