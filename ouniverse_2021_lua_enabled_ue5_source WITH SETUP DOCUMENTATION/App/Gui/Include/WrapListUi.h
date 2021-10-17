// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegate.h"
#include "WrapListUi.generated.h"


class UScrollBox;
class UWrapBox;
class USizeBox;
class UWrapListElement;


UENUM(BlueprintType)
enum class EWrapListUiDirections : uint8
{
	Up UMETA(DisplayName = "Up"),
	Down UMETA(DisplayName = "Down"),
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelDynamicMulticastWrapListUiDirections, EWrapListUiDirections, Direction);

UCLASS(Blueprintable,BlueprintType)
class APP_API UWrapListUi : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float ElementSizeX;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ElementSizeY;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Columns;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Rows;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int SelectedIndex = 0;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USizeBox* SizeBoxOuterVar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UScrollBox* ScrollBoxVar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USizeBox* SizeBoxInnerVar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWrapBox* WrapBoxVar;





	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<UWrapListElement> EmptyElementClass = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UWrapListElement*> EmptyElements;


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Update"))
	void Update();


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetSelected"))
	UWrapListElement* GetSelected();

	UFUNCTION(BlueprintCallable, meta = (BindWidget))
	void AddWidget(UWrapListElement* WidgetToAdd);

	UFUNCTION(BlueprintCallable, meta = (BindWidget))
	void RemoveWidget(UWrapListElement* WidgetToRemove);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWrapListElement* SparkedElement = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UWrapListElement*> VisibleElements;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#MoveIndex"))
	void MoveIndex(EWrapListUiDirections Direction);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Spark"))
	void DoSpark();

	void Spark();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#BeginSpark"))
	void BeginSpark();

	void Unspark();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#BeginUnspark"))
	void BeginUnspark();


	UPROPERTY(BlueprintAssignable)
	FDelDynamicMulticastWrapListUiDirections OnEdgeHit;

};

UCLASS(Blueprintable, BlueprintType)
class APP_API UWrapListElement : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USizeBox* SizeBoxVar;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#ListAdd"))
	void ListAdd();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#ListRemove"))
	void ListRemove();

	void Spark();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#BeginSpark"))
	void BeginSpark();

	void Unspark();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#BeginUnspark"))
	void BeginUnspark();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName="#Unhover"))
	void Unhover();


};