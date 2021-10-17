// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AnythingUiFetch.h"
#include "InteractiveComponent.generated.h"



class UInteractiveComponent;

USTRUCT()
struct FInteractiveComponentAndScreenX
{
	GENERATED_BODY()


	UPROPERTY()
	float ScreenX;

	UPROPERTY()
	UInteractiveComponent* InteractiveComponent;

public:

	FInteractiveComponentAndScreenX() {};
	FInteractiveComponentAndScreenX(float InScreenX, UInteractiveComponent* InInteractiveComponent)
	{
		ScreenX = InScreenX;
		InteractiveComponent = InInteractiveComponent;
	}
};

struct FSortInteractiveComponentAndScreenX
{
	FSortInteractiveComponentAndScreenX() {};

	bool operator()(const FInteractiveComponentAndScreenX A, const FInteractiveComponentAndScreenX B) const
	{
		return A.ScreenX < B.ScreenX;
	}
};



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APP_API UInteractiveComponent : public USceneComponent
{
	GENERATED_BODY()

	static const FName SYS;

public:	
	// Sets default values for this component's properties
	UInteractiveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	float MaxConsiderationDistance = 200;

	void SetInteractiveMutual(UObject* InMutual);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UObject* InteractiveMutual;

	void On();

	void Off();

	FText GetInteractiveName();

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#GetInteractiveName"))
	FText GetInteractiveNameBP();

	void GetUi(FAnythingUiFetch& Fetch);

	static void FilterOnScreenInteractivesAndSortByScreenX(TArray<UInteractiveComponent*>& InteractiveComponents, TArray<UInteractiveComponent*>& Output);
};
