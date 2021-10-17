// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Enum/EBranch.h"
#include "Companion.generated.h"

/**
 * 
 */


struct FCompanionMem;
class UStory;
class ACompanionActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActraEmbodyComplete, UCompanion*, Companion, ACompanionActor*, Actra);


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UCompanion : public UObject
{
	GENERATED_BODY()

public:

	UCompanion() {};


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int Key = 0;

	void SetKey(int CompanionKey);

	FCompanionMem* Mem;
	
	virtual void SetMem(FCompanionMem* CompanionMem);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStory* Story;

	void SetStory(UStory* InStory);

//Obtain

public:

	UCompanion* Obtain();

	UFUNCTION(Category = "Companion", BlueprintCallable, meta = (DisplayName = "#Obtain Companion"))
	void ObtainBP(UCompanion*& Companion);

	bool IsObtained();

	UFUNCTION(Category = "Companion", BlueprintCallable, meta = (DisplayName = "#Is Obtained", ExpandEnumAsExecs = Execs))
	void IsObtainedBP(EYesNo& Execs);

//Join Party

	void JoinParty();

	UFUNCTION(Category = "Companion", BlueprintCallable, meta = (DisplayName = "#Join Party"))
	void JoinPartyBP(bool& Success, UCompanion*& CompanionR);

//Companion Properties

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText FirstName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText LastName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText ShortName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Strength;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Agility;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Intelligence;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Wisdom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Spirit;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Charm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Charisma;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTexture2D* IconLarge;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ACompanionActor* EmbodyActra;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSoftClassPtr<ACompanionActor> EmbodyActraClass;

	void EmbodyAsActra();

	UFUNCTION()
	void EmbodyAsActraLL();
	
	UFUNCTION()
	void EmbodyAsActraComplete(ACompanionActor* Actra);

	UPROPERTY(BlueprintAssignable)
	FActraEmbodyComplete OnActraEmbodyComplete;

};
