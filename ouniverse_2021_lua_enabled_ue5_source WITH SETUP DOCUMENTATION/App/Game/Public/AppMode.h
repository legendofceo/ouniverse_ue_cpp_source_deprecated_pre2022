// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Delegate.h"
#include "AppMode.generated.h"

class UApp;
class UData;
class UPrimaryPro;


UCLASS(Blueprintable,BlueprintType)
class APP_API AAppMode : public AGameModeBase
{
	GENERATED_BODY()

	AAppMode();

	static const FName SYS;

public:

	virtual void BeginPlay() override;

	static AAppMode* Get();

	/** Static Getter of the AppMode casting from UE5's GetGameMode. */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static AAppMode* GetAppMode(const UObject* WorldContextObject);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UApp* App;

	void Boot();
	void Boot_Stream();

	UPROPERTY(VisibleAnywhere)
	UPrimaryPro* PrimaryPro;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UPrimaryPro> PrimaryProSoft;

	UPROPERTY(EditAnywhere)
	UData* Data;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UData> DataClass = nullptr;

	UPROPERTY()
	bool bBooted = false;

	UFUNCTION(BlueprintCallable, CallInEditor)
	void CreateData();

	UPROPERTY(BlueprintAssignable)
	FDelDynamicMulticast OnCreateDataComplete;

};
