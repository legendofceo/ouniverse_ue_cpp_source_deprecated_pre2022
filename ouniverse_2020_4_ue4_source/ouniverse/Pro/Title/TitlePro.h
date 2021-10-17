// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Protocol.h"
#include "../../System/Input.h"
#include "../../System/Stroke.h"
#include "../../System/Flux.h"

#include "../../Ui/UiBase.h"
#include "../../Ui/UiWin.h"
#include "TitlePro.generated.h"

class UTextBlock;


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWIN_TitleMenuEL : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UWIN_TitleMenu* Title;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "TextHash", Meta = (DisplayName = "TextLocHash"))
	FName TLH;

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override { return FReply::Handled(); };

	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override {};
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override {};
};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWIN_TitleMenu : public UUiWin
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	int FocusIx;
	UWIN_TitleMenuEL* Focused;

	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenuEL* vNewGame;
	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenuEL* vContinue;
	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenuEL* vLoad;
	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenuEL* vOptions;
	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenuEL* vNews;
	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenuEL* vCredits;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<UWIN_TitleMenuEL*> Elements;

	void SelectEntry(int Adj);

	void PRE(UWIN_Title* Par);

	void BTN(StrokeC* S) override;

	UWIN_Title* ParentWindow_;


};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWIN_TitleSplash : public UUiWin
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void PRE(UWIN_Title* Par);
	void BTN(StrokeC* S) override;

	UWIN_Title* ParentWindow_;

	UFUNCTION(BlueprintImplementableEvent)
	void BeginClose();

	UFUNCTION(BlueprintCallable)
	void CloseComplete();

};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWIN_Title : public UUiWin
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void PRE(UTitlePro* TitleP);

	int MenuIx;

	UPROPERTY(meta = (BindWidget))
	UWIN_TitleMenu* vMenu;

	UPROPERTY(meta = (BindWidget))
	UWIN_TitleSplash* vSplash;
	
	UUiWin* GetMenu(int Ix);
	UUiWin* ActiveMenu;

	UTitlePro* Pro;

	void BTN(StrokeC* S) override;

	void ToTitle();


	enum CMDS
	{
		CMDS_NULL,
		NewGame,
		Continue,
		Load,
		Options,
		Credits,
		News,
		Title,
		Splash,
		CMDS_MAX
	};

	void CMD(CMDS InCMD);
};


UCLASS()
class OUNIVERSE_API UTitlePro : public UProtocol, public InputC
{
	GENERATED_BODY()

public:

	UTitlePro() {};

	static UTitlePro* Create();

	void Start();

	UWIN_Title* Win_;

	void BTN(StrokeC* S) override;


	enum CMDS
	{
		CMDS_NULL,
		StartNewGame,
	};

	void CMD(CMDS InCMD);
};