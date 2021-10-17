// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AreaAddress.h"
#include "AreaMng.generated.h"

class UArea;
UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UAreaMng : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAreaMng();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** AppMode does centralized handeling of all Level Streaming. */

/** Address of pending Area stored during asynchronous loading. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress PendingAreaAddress;

	/** Current Area Address for debugging. */
	FAreaAddress AreaAddress;

	/** Current active Area. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UArea* Area;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Change Area"))
		void DoChangeArea(FAreaAddress NextArea);

	UFUNCTION()
		void AreaUnloaded();

	UFUNCTION()
		void LoadNextArea();

};
