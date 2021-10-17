// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectPlus.h"
#include "Blueprint/UserWidget.h"
#include "Delegate.h"
#include "InputRepeater.h"
#include "Index.h"
#include "TitleMenuPro.generated.h"

class UBT;
class UCanvasPanel;
class UTitleNewGamePro;

UENUM(BlueprintType)
enum class TitleMenuState : uint8
{
	None  UMETA(DisplayName = "None"),
	TopMenu  UMETA(DisplayName = "TopMenu"),
	NewGame  UMETA(DisplayName = "NewGame"),
	MAX UMETA(DisplayName = "MAX"),
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UTitleMenuPro : public UObjectPlus
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UPROPERTY(VisibleAnywhere)
	UTitleNewGamePro* TitleNewGamePro;

	UPROPERTY(VisibleAnywhere)
	UUserWidget* ActiveMenu = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UTitleMenuUi> TitleMenuUiClass = nullptr;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UTitleNewGamePro> TitleNewGameProSoft;

	void Run();

	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="#RunBP"))
	void RunBP();

	UPROPERTY(VisibleAnywhere)
	TitleMenuState State = TitleMenuState(0);

	void SetState(TitleMenuState NewState);

	void Update();
};




UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UTitleMenuOptUi : public UUserWidget
{
	GENERATED_BODY()

		static const FName SYS;

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#SelectBP"))
	void SelectBP();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#UnselectBP"))
	void UnselectBP();

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UTitleMenuUi: public UUserWidget
{
	GENERATED_BODY()

	static const FName SYS;

public:


	void Init(UTitleMenuPro* InTitleMenuPro);

	UPROPERTY(VisibleAnywhere)
	UTitleMenuPro* TitleMenuPro;

	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="#BeginOpenBP"))
	void BeginOpenBP();

	FDelegateHandle InputHandle;

	void Connect();

	void OptionUpdate();

	void Accept();

	UPROPERTY(VisibleAnywhere)
	FIndex Index;

	UPROPERTY(VisibleAnywhere)
	FInputRepeater InputRepeater;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* Canvas;

	void InputBT(UBT* BT);

	UPROPERTY(VisibleAnywhere)
	UTitleMenuOptUi* ActiveOption = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TArray<UTitleMenuOptUi*> Options;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTitleMenuOptUi* NewGame;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTitleMenuOptUi* Continue;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTitleMenuOptUi* LoadGame;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTitleMenuOptUi* Settings;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTitleMenuOptUi* Credits;


};