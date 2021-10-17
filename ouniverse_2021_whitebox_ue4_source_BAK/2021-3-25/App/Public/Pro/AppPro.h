// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pro.h"
#include "Delegate.h"
#include "AppPro.generated.h"


class UStoryPro;
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


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UAppPro : public UPro
{
	GENERATED_BODY()


public:

	UAppPro();


	virtual void BeginPlay() override;

	void Init(AAppMem* AppMem);
	
	void BT(UInputButtonEvent* BT);

	UFUNCTION(BlueprintImplementableEvent)
	void Test();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	UPROPERTY(BlueprintAssignable)
	FDelegate OnInitComplete;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EAppMode> AppMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Initialized = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppMem* AppMem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStoryPro* StoryPro;

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
	TSoftClassPtr<UStoryPro> StoryProClass = NULL;

};
