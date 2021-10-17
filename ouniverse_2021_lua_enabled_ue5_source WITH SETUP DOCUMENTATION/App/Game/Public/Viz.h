// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EquipSlot.h"
#include "Delegate.h" 
#include "Viz.generated.h"



class AActraEx;
class AActraExHuman;
class ItemMem;

UCLASS(BlueprintType, Blueprintable)
class APP_API UVizEx : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActraEx* ActraEx;

	void Init(AActraEx* InActraEx);

	virtual	void BeginInit() {};
	
	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="#BeginInitBP"))
	void BeginInitBP();

};


UCLASS(BlueprintType, Blueprintable)
class APP_API UVizExHuman : public UVizEx
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AActraExHuman* ActraExHuman;

	virtual void BeginInit() override;

};




UCLASS(BlueprintType, Blueprintable)
class APP_API UViz : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	UObject* Source;

	void SetSource(UObject* Object);

	UObject* GetSource() { return Source; };

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UVizEx> ExSoft;

};

UCLASS(BlueprintType, Blueprintable)
class APP_API UVizRack : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	void Init();


	UPROPERTY(VisibleAnywhere)
	TArray<UViz*> Vizs;

	void AddViz(UViz* VizToAdd);

	void RemoveVizBySource(UObject* Source);

	void RemoveViz(UViz* VizToRemove);

	
	void Stream(FDelBasic Callback);
	void Stream_Complete(FDelBasic Callback);

	void GetAllEx(TArray<UVizEx*>& Output);


};