// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleMenuPro.h"
#include "Log.h"
#include "AppStream.h"
#include "AppWorld.h"
#include "AppController.h"
#include "InputRaw.h"
#include "Components/CanvasPanel.h"
#include "TitleNewGamePro.h"

const FName UTitleMenuPro::SYS = "TitleMenuPro";

void UTitleMenuPro::Run()
{
	//SetState(TitleMenuState::TopMenu);
	RunBP();
}


void UTitleMenuPro::SetState(TitleMenuState NewState)
{
	State = NewState;
	Update();
}

void UTitleMenuPro::Update()
{
	if (ActiveMenu)
	{
		ActiveMenu->RemoveFromParent();
		ActiveMenu = nullptr;
	}

	switch (State) {
	case TitleMenuState::TopMenu:

		if (!TitleMenuUiClass)
		{
			LOG.S(SYS).T(TCRIT).W("TitleMenuUiClass is null").DebugM();
			return;
		}
			{
				UTitleMenuUi* TitleMenuUi = CreateWidget<UTitleMenuUi>(UAppWorld::GetAppWorld(), TitleMenuUiClass.Get());
				ActiveMenu = TitleMenuUi;
				TitleMenuUi->AddToViewport(500);
				TitleMenuUi->Init(this);
				TitleMenuUi->BeginOpenBP();
			}

		break;
	case TitleMenuState::NewGame:

		if (!TitleNewGameProSoft)
		{
			LOG.S(SYS).T(TCRIT).W("TitleNewGameProSoft is null").DebugM();
			return;
		}
		
		UAppStream::Get()->Stream(TitleNewGameProSoft.ToSoftObjectPath(), FStreamableDelegate::CreateLambda([&]()
			{
				TitleNewGamePro = NewObject<UTitleNewGamePro>(this, TitleNewGameProSoft.Get());
				TitleNewGamePro->Run();
			})); 

		break;
		
	}
}


void UTitleMenuUi::Init(UTitleMenuPro* InTitleMenuPro)
{
	TitleMenuPro = InTitleMenuPro;
	Options.Add(NewGame);
	Options.Add(Continue);
	Options.Add(LoadGame);
	Options.Add(Settings);
	Options.Add(Credits);
	Index.MaxValue = Options.Num() - 1;
	OptionUpdate();
	Connect();
}


void UTitleMenuUi::Connect()
{
	InputHandle = AAppController::Get()->OnBT.AddUObject(this, &UTitleMenuUi::InputBT);
}

void UTitleMenuUi::InputBT(UBT* BT)
{
	/**
	FCommandMenu BindMenu = AAppController::Get()->Transpose(BT);

	switch (BindMenu.Get()) {
	case CommandMenu::Left:
		if (InputRepeater.Update(BT))
		{
			Index--;
			OptionUpdate();
		}
		break;
	case CommandMenu::Right:
		if (InputRepeater.Update(BT))
		{
			Index++;
			OptionUpdate();
		}
		break;
	case CommandMenu::Accept:
		if (BT->IsClick())
		{
			Accept();
		}
		break;
	}
	*/
}

void UTitleMenuUi::OptionUpdate()
{
	if (ActiveOption)
	{
		ActiveOption->UnselectBP();
	}
	ActiveOption = Options[Index.Get()];
	ActiveOption->SelectBP();
}

void UTitleMenuUi::Accept()
{
	AAppController::Get()->OnBT.Remove(InputHandle);
	TitleMenuPro->SetState(TitleMenuState::NewGame);
}