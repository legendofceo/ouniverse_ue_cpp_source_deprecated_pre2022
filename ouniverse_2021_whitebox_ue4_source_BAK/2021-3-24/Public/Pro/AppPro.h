// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pro.h"
#include "Delegate.h"
#include "AppPro.generated.h"


class AStoryPro;
class UInputButtonEvent;
class AAppMem;
class UStory;

USTRUCT(BlueprintType)
struct FNewGameSettings
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bEssentialsCanDie;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool DeathPerm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool SingleSave;
};


UENUM(BlueprintType)
enum EAppMode
{
	EAppModeMenu  UMETA(DisplayName = "Menu"),
	EAppModeStory UMETA(DisplayName = "Story"),
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AAppPro : public APro
{
	GENERATED_BODY()


public:

	AAppPro();
	//UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static AAppPro* GetAppPro(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get AppPro"))
	static void GetAppProBP(AAppPro*& AppPro);

	virtual void BeginPlay() override;

	void Init(AAppMem* AppMem);
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	UFUNCTION()
	void InitLL();
	
	UFUNCTION()
	void InitSO();


	UPROPERTY(BlueprintAssignable)
	FDelegate OnInitComplete;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EAppMode> AppMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Initialized = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppMem* AppMem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AStoryPro* StoryPro;

	void RouteBT(UInputButtonEvent* BT);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Start App"))
	void StartApp();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Start App"))
	void DoStartAppBP();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Start NewGame"))
	void StartNewGame(FNewGameSettings NewGameSettings);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Start NewGame"))
	void DoStartNewGameBP();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Start Story"))
	void StartStoryBP(UStory* Story);


public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<AStoryPro> StoryProClass = NULL;

};
