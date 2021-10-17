// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Marshal.h"
#include "Log.h"
#include "GameData.generated.h"

class USoftServe;
class ULib;
class UAreaLib;
class UCompanionLib;
class UStoryLib;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UGameData : public UObject
{
	GENERATED_BODY()
	
public:

	UGameData();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;


	void Init();

	UFUNCTION()
	void InitSS(USoftServe* SS);

	UFUNCTION()
	void SubInitComplete(UObject* SubObject);
	
	UFUNCTION()
	void PostInitComplete(UObject* Object);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* SoftServe;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<UObject*> InitTasks;

	UPROPERTY()
	FDelegateObj OnInitComplete;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ULib*> Libs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAreaLib* AreaLib;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCompanionLib* CompanionLib;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStoryLib* StoryLib;

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UAreaLib> AreaLibClass = NULL;

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UCompanionLib> CompanionLibClass = NULL;

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UStoryLib> StoryLibClass = NULL;

};