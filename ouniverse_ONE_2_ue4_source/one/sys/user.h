// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "base.h"
#include "user.generated.h"

class ULoadout;
class ULoadoutLib;

struct FLogger;

UCLASS()
class AUser : public ABase
{
	GENERATED_BODY()

public:

	AUser();
	static AUser* Create(AActor* WorldActor);
	void Constructor();

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bActive;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	int32 UID;
	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	FString StringUID;
	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	FString ID;
	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	int Icon;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	int LastLoadout;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString AbsolutePath;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (category = "0 Details"))
	FString DocPath;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bValid;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	ULoadoutLib* LoadoutLib;

	UFUNCTION(BlueprintCallable)
	FText PrintID();

	UFUNCTION(BlueprintCallable)
	int32 GetUID();

	UFUNCTION(BlueprintCallable)
	bool IsActive();

	void Activate();
	void Deactivate();

	void FromJsonDocument(int32 NumericUID, FLogger* Log);

	bool IsValid();

};