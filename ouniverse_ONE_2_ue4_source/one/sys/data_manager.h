// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "log.h"
#include "../type/map.h"
#include "form_type.h"
#include "data_manager.generated.h"

class UAtlas;
class ULoadout;
class UDataTable;
class UFormType;

UCLASS()
class UDataManager : public UObject
{
	GENERATED_BODY()

	UDataManager();

public:

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bAtlasesLoaded;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bAtlasDataLoaded;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	UAtlas* MasterAtlas;

	static FString AtlasFileEXT;
	static FString AtlasDataFileEXT;
	static FString AtlasDirName;

	static UDataManager* Create(TSoftClassPtr<UDataManager> SoftClass, UObject* WorldCTX);

	static UDataManager* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UDataManager* GetDataManager();

	void Constructor();
	
	void LoadAtlases();

	UFUNCTION(BlueprintCallable)
	void LoadAtlasDataFromScribe(UAtlas* Master, TArray<UAtlas*> AtlasList);

	void LoadAtlasDataFromLoadout(ULoadout* Loadout);

	UPROPERTY(Category = "0 Editable", EditAnywhere, BlueprintReadOnly)
	UDataTable* FormTypeSheet;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	TMap<int,UFormType*> FormTypes;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	FString AtlasDir;

	UPROPERTY(Category = "1 Details", VisibleAnywhere)
	TMap<int, UAtlas*> Atlases;

	UPROPERTY(Category = "1 Details", VisibleAnywhere)
	TMap<int, UAtlas*> ActiveAtlases;

	bool TryAtlas(UAtlas*& Output, int UN);

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	int AtlasCount;
	
	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	int AtlasScannedCount;

	UPROPERTY(Category = "1 Details", VisibleAnywhere)
	FLogger Log;

	UFUNCTION(BlueprintCallable)
	TArray<UForm_F*> Query(FString Query, UFormType* ParentType, TArray<UFormType*> FormTypeFilters);

	UFUNCTION(BlueprintCallable)
	static TArray<UAtlas*> GetAllAtlas();

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	UAtlas* ActiveScribeAtlas;

	static FString GetDataDir();

	ULoadout* GetOfficialLoadout();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UFormType*> GetAllFormTypes();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UFormType* GetFormType(int FormType);

	UFUNCTION(BlueprintCallable)
	void SaveMaster();

};