// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Pact.h"
#include "HeroData.h"
#include "Data.generated.h"



struct FPact;
class UActraMem;
class UArea;
class UDataTable;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UDataInitializer : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UActraMem>> ActraMemSofts;


	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UArea>> AreaSofts;

	UPROPERTY(EditAnywhere)
	UDataTable* HeroDataTable;


};


UCLASS(Abstract,BlueprintType, Blueprintable)
class APP_API UData : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:
	// Sets default values for this component's properties
	UData();

public:

	static UData* Get();

	UFUNCTION(BlueprintCallable,BlueprintPure,meta=(DisplayName=":Data"))
	static void GetBP(UData*& Data);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Reset"))
	void ResetBP(const FDelDynamic&  Event);

	FDelDynamic OnResetComplete;

	void Reset();
	UFUNCTION()
	void Reset_DataInitializerStreamed();

	UPROPERTY(VisibleAnywhere)
	UDataInitializer* DataInitializer = nullptr;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UDataInitializer> DataInitializerSoft;

	UPROPERTY(VisibleAnywhere)
	int AreaCount = 0;

	UPROPERTY(VisibleAnywhere)
	int ActraCount = 0;

	UPROPERTY(VisibleAnywhere)
	TMap<FName,UActraMem*> ActraMems;
	
	UPROPERTY(VisibleAnywhere)
	TMap<int, UActraMem*> GeneratedActraes;

	UPROPERTY(VisibleAnywhere)
	TMap<int, FPact> Pacts;

	UPROPERTY(VisibleAnywhere)
	TMap<FName, UArea*> Areas;


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TMap<FName, FHeroData> Heroes;

	UPROPERTY(VisibleAnywhere)
	TMap<FName, FHeroData> GeneratedHeroes;

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#GetActiveHeroes"))
	TArray<FHeroData> GetActiveHeroes();

};
