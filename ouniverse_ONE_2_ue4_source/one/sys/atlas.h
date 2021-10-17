// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "base.h"
#include "log.h"

#include "../type/map.h"
#include "../type/json.h"
#include "../type/map.h"

#include "atlas.generated.h"

class Form_F;
class UForm_F;
class UFormType;
struct FLogger;

UENUM()
enum EDataStatus
{
	DataStatusNone			UMETA(DisplayName = "None"),
	DataStatusApproved		UMETA(DisplayName = "Approved"),
	DataStatusNoticed		UMETA(DisplayName = "Noticed"),
	DataStatusWarned		UMETA(DisplayName = "Warned"),
	DataStatusCritical		UMETA(DisplayName = "Critical")
};

USTRUCT(BlueprintType)
struct FAtlasReport
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Total;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Created;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int Approved;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Noticed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Warned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Critical;

	FAtlasReport()
	{
		Total = 0;
		Created = 0;
		Approved = 0;
		Noticed = 0;
		Warned = 0;
		Critical = 0;
	}
};



UCLASS(BlueprintType)
class UAtlas : public UObject
{
	GENERATED_BODY()

public:
	UAtlas();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details", DisplayName = "Unique Identifier"))
	int32 UID;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString StringUID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString ShortName;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString LongName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString Author;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString Subtitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString AbsolutePath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString DocPath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString ContentPath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesTotal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesParsed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesCreated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesApproved;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesNoticed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesWarning;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	int EntriesCrtitical;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	bool bValid;

	int NewUID();

	void AddNewData(Form_F* NewData);

	MapC<int, Form_F*> Lib;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FLogger Log;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FLogger DataLog;

	FString GetAbsolutePath() { return AbsolutePath; };
	FString GetDocPath() { return DocPath; };
	FString GetContentPath() { return ContentPath; };
	bool IsValid() { return bValid; };

	void Constructor();
	void AtlasFromJsonDocument(int32 NumericUID,FLogger* InLog);
	void DataFromJson(FLogger* InLog);

	
	void Save();

	bool TryData(Form_F*& Output, int InUN);

	static bool TryAtlas(UAtlas*& Output, int UN);

	UFUNCTION(BlueprintCallable)
	static TArray<UAtlas*> GetEmptyAtlasArray();

	void Query(TArray<UForm_F*>* ValidData, FString Query, UFormType* ParentType, TArray<UFormType*> FormTypeFilters);

};