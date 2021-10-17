// Fill out your copyright notice in the Description page of Project Settings.

#include "TitlePro.h"
#include "../../System/Scope.h"
#include "../../System/Reg.h"
#include "../../System/Major.h"
#include "../../System/Ui.h"
#include "../../System/Director.h"

#include "Components/TextBlock.h"

void UWIN_TitleMenuEL::NativeConstruct()
{
	Super::NativeConstruct();
}





void UWIN_TitleMenu::NativeConstruct()
{
	FocusIx = 0;
	Elements.Init(NULL,6);
	Super::NativeConstruct();
	Elements[0] = vNewGame;
	Elements[1] = vContinue;
	Elements[2] = vLoad;
	Elements[3] = vOptions;
	Elements[4] = vNews;
	Elements[5] = vCredits;
	SelectEntry(0);

}

void UWIN_TitleMenu::SelectEntry(int Adj)
{
	FocusIx += Adj;
	
	if (Adj != 0 && IsValid(Focused))
	{
		Focused->Event(EUiEvent::Unfocus, 0);
	}

	if (FocusIx < 0)
	{
		FocusIx = Elements.Num() - 1;
	}
	else if(FocusIx > Elements.Num()-1)
	{
		FocusIx = 0;
	}

	Focused = Elements[FocusIx];
	Focused->Event(EUiEvent::Focus,0);
}

void UWIN_TitleMenu::PRE(UWIN_Title* Par)
{
	ParentWindow_ = Par;
}

void UWIN_TitleMenu::BTN(StrokeC* SE)
{
	if (SE->ToCodeLite())
	{
		switch (SE->GetCode()) {
		case StrokeC::CodeLite::Up:
			SelectEntry(-1);
			break;
		case StrokeC::CodeLite::Down:
			SelectEntry(1);
			break;
		case StrokeC::CodeLite::Accept:
			if (Focused == vNewGame)
			{
				ParentWindow_->CMD(UWIN_Title::NewGame);
			}
			break;
		}
	}
}









void UWIN_TitleSplash::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWIN_TitleSplash::PRE(UWIN_Title* Par)
{
	ParentWindow_ = Par;
}

void UWIN_TitleSplash::BTN(StrokeC* SE)
{
	BeginClose();
}

void UWIN_TitleSplash::CloseComplete()
{
	ParentWindow_->ToTitle();
}








void UWIN_Title::NativeConstruct()
{
	MenuIx = 0;
	Super::NativeConstruct();

}

void UWIN_Title::PRE(UTitlePro* TitleP)
{
	Pro = TitleP;

	vSplash->Hide();
	vMenu->Hide();
	

	vSplash->Show();
	ActiveMenu = vSplash;

	vMenu->PRE(this);
	vSplash->PRE(this);
}

 UUiWin* UWIN_Title::GetMenu(int Ix)
{
	switch (Ix) {
	case 0:
		return vSplash;
	case 1:
		return vMenu;
	default:
		return vSplash;
	}
}

void UWIN_Title::BTN(StrokeC* SE)
{
	ActiveMenu->BTN(SE);
}

void UWIN_Title::ToTitle()
{
	ActiveMenu = vMenu;
	vSplash->Hide();
	vMenu->Show();
}

void UWIN_Title::CMD(CMDS InCMD)
{
	switch (InCMD) {
	case CMDS::NewGame:
		ActiveMenu->Hide();
		Pro->CMD(UTitlePro::CMDS::StartNewGame);
		break;
	}

}





UTitlePro* UTitlePro::Create()
{
	UTitlePro* Obj = NewObject<UTitlePro>();
	return Obj;
}

void UTitlePro::Start()
{
	Win_ = CreateWidget<UWIN_Title>(ScopeC::World(), UReg::Get()->TitleWin_);
	UMajor::Get()->Ui()->ToViewport(Win_);

	Win_->PRE(this);
}

void UTitlePro::BTN(StrokeC* SE)
{
	Win_->BTN(SE);
}

void UTitlePro::CMD(CMDS InCMD)
{
	switch (InCMD) {
	case UTitlePro::CMDS::StartNewGame:
		UMajor::Get()->Director()->SetAct(FName("NewGame"));
		break;
	}
}