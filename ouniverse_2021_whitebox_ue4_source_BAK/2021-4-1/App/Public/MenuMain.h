// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuMainInitializer.h"
#include "Win.h"
#include "../Enum/EKeynetMenu.h"
#include "MenuMain.generated.h"

class UUserWidget;
class UIndexByte;
class UInputButtonEvent;

UCLASS()
class APP_API AMenuMainAllWin : public AWin
{
	GENERATED_BODY()

public:

	AMenuMainAllWin() {};

	UFUNCTION(BlueprintCallable)
	void SetWinRelations(AMenuMainAllWin* Parent);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void InsetSubUi(UUserWidget* WidgetToInset);

	UFUNCTION(BlueprintCallable)
	void OpenAnyWin(TEnumAsByte<EMenuMainWins> Win);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EMenuMainWins> PendingWin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AMenuMainRootWin* RootWin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AMenuMainAllWin* ParentWin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AMenuMainAllWin* ActiveWin = NULL;

	UFUNCTION(BlueprintCallable)
	AMenuMainAllWin* SetActiveWin(AMenuMainAllWin* NewActiveWin);

	UFUNCTION()
	void BeginCloseWinInterrupted();

};

UCLASS()
class APP_API AMenuMainRootWin : public AMenuMainAllWin
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMenuMainRootWin();

	UFUNCTION(Category = "MenuMain", meta = (WorldContext = "WorldContextObject"))
	static AMenuMainRootWin* OpenMenu(FMenuMainInitializer Initializer, TSubclassOf<AMenuMainRootWin> MenuMainClass, const UObject* WorldContextObject);


	void Setup(FMenuMainInitializer Initializer);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AWin* ActiveSubmenu;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TabHeader(bool bReverse);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TryMenuAction(EKeynetMenu MenuAction, UInputButtonEvent* InputButtonEvent);

	virtual void BeginChangeWin_Implementation();

	UFUNCTION(BlueprintCallable)
	static TEnumAsByte<EMenuMainWins> ConvertRootWinToAnyWin(TEnumAsByte<EMenuMainRootWins> RootWinByte);
};