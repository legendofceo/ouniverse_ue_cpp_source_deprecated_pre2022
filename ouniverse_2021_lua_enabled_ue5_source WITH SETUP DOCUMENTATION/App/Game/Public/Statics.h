// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Statics.generated.h"

/**
 * 
 */

class AActor;
class UUserWidget;

UENUM(BlueprintType)
enum class EIncrementParam : uint8
{
	Increment,
	Decrement,
};

UENUM(BlueprintType)
enum class ENumericOverflowMethodParam : uint8
{
	Wrap,
	Clamp,
};

UENUM(BlueprintType)
enum class ESpawnFormation : uint8
{
	ESpawnFormationTriangle UMETA(DisplayName = "Triangle"),
	ESpawnFormationCircular UMETA(DisplayName = "Circular"),
	ESpawnFormationLine UMETA(DisplayName = "Line"), 
};


UCLASS()
class APP_API UStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(category="App Statics", BlueprintPure, BlueprintCallable, meta = (DisplayName = "#TForm"))
	static FTransform EmptyTransform();


	UFUNCTION(category = "App Statics", BlueprintPure, BlueprintCallable, meta = (DisplayName = "#Limbo"))
	static void Limbo(FTransform& XForm);

	UFUNCTION(category = "App Statics", BlueprintCallable, meta = (DisplayName = "Increment Byte"))
	static uint8 IncrementByteBP(uint8 Byte, bool bDecrement, uint8 Min, uint8 Max, ENumericOverflowMethodParam OverflowMethod);

	UFUNCTION(category = "App Statics", BlueprintCallable)
	static void PlaceActorsAtActor(TArray<AActor*> Actors, AActor* Target, float RotateRandom, FVector TranslateRandom, ESpawnFormation Formation);


	static bool HasFunctionBP(UObject* Obj, FName FunctionName);









	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#HotParamObject"))
	static void HotParamObject(UPARAM(ref) UObject*& Param, TSoftClassPtr<UObject> Soft);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#HotParamWidget"))
	static void HotParamWidget(UPARAM(ref) UUserWidget*& Param, TSoftClassPtr<UUserWidget> Soft);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#SoftToObject"))
	static void SoftToObject(TSoftClassPtr<UObject> Soft, UObject*& R);


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#ForceObjectParam"))
	static void ForceObjectParam(UObject* Object, UPARAM(ref) UObject*& Param, UObject*& R);

};
