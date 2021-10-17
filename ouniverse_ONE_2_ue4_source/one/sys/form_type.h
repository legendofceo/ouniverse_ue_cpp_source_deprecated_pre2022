// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Engine/DataTable.h"
#include "form_type.generated.h"

class UForm_F;
class UTexture2D;
class UScribeFormPage_U;


USTRUCT(BlueprintType)
struct FFormTypeRow : public FTableRowBase
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int UID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ParentUID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName NameKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Abbreviation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UScribeFormPage_U> FormPage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UForm_F> FormObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAbstract;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bMapPlaceable;

public:

	FFormTypeRow()
	{
		UID = -1;
	}
};


UCLASS(Blueprintable)
class UFormType : public UObject
{
	GENERATED_BODY()

public:



	static UFormType* Create(FFormTypeRow* Row);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int UID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int ParentUID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFormType* Parent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName NameKey;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText Abbreviation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLinearColor Color;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UScribeFormPage_U> FormPage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UForm_F> FormObject;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bAbstract;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bMapPlaceable;


	void Translate();
	void SetParent();

	bool IsRelative(UFormType* InFormType);

	static int const Form = 1;
	static int const Area = 2;
	static int const Cell = 3;
	static int const Manifest = 6;
	static int const Spawn = 9;
	static int const Actra = 44;
	static int const Bodyshape = 37;
	static int const Head = 18;
	static int const Fitting = 24;
	static int const Wearable = 85;
	static int const Skeleton = 74;
	static int const Condition = 97;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeFormID() { return UFormType::Form; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeAreaID() { return UFormType::Area; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeCellID() { return UFormType::Cell; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeManifestID() { return UFormType::Manifest; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeSpawnID() { return UFormType::Spawn; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeActraID() { return UFormType::Actra; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeBodysyhapeID() { return UFormType::Bodyshape; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeHeadID() { return UFormType::Head; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeFittingID() { return UFormType::Fitting; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeWearableID() { return UFormType::Wearable; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeSkeletonID() { return UFormType::Skeleton; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int FormTypeConditionID() { return UFormType::Condition; };

};