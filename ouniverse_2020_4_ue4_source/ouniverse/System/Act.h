// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Act.generated.h"

class ULevelStreamingDynamic;

UENUM(BlueprintType)
enum class EActType : uint8 {
	ERROR UMETA(DisplayName = "Focus"),
	Episode UMETA(DisplayName = "Episode"),
	OpenWorld UMETA(DisplayName = "Openworld"),
};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UAct : public UObject
{

	GENERATED_BODY()

public:

	UAct();
	//static UAct* Get();
	//static UAct* Create();	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EActType ActType;

	void Mount();
	UFUNCTION(BlueprintImplementableEvent)
	void MountBP();

	void Dismount();
	UFUNCTION(BlueprintImplementableEvent)
	void DismountBP();

	UFUNCTION(BlueprintCallable)
	void LoadMap(FString LoadLevel);

	UFUNCTION()
	void OnLevelStreamed();

private:

	bool bMapLoaded;
	ULevelStreamingDynamic* StreamedLevel_;

};