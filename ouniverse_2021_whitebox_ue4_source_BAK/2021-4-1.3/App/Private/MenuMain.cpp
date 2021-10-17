// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuMain.h"
#include "Blueprint/UserWidget.h"



void AMenuMainAllWin::SetWinRelations(AMenuMainAllWin* Parent)
{
	ParentWin = Parent;
	RootWin = Parent->RootWin;
}

void AMenuMainAllWin::OpenAnyWin(TEnumAsByte<EMenuMainWins> Win)
{
	PendingWin = Win;

	if (ActiveWin != NULL)
	{
		ActiveWin->OnCloseWinInterrupted.AddDynamic(this, &AMenuMainAllWin::BeginCloseWinInterrupted);
		ActiveWin->OnCloseWinBaton.AddDynamic(this, &AMenuMainAllWin::BeginChangeWin);
		ActiveWin->OnCloseWinComplete.AddDynamic(ActiveWin, &AWin::BeginConcludeWin);
		ActiveWin->BeginCloseWin();
	}
	else
	{
		BeginChangeWin();
	}
}

void AMenuMainAllWin::BeginCloseWinInterrupted()
{
	ActiveWin->OnCloseWinBaton.RemoveDynamic(this, &AMenuMainAllWin::BeginChangeWin);
	ActiveWin->OnCloseWinComplete.RemoveDynamic(this, &AWin::BeginConcludeWin);
}

AMenuMainAllWin* AMenuMainAllWin::SetActiveWin(AMenuMainAllWin* NewActiveWin)
{
	ActiveWin = NewActiveWin;
	ActiveWin->SetWinRelations(this);
	ActiveWin->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	return ActiveWin;
}




AMenuMainRootWin::AMenuMainRootWin()
{
	PrimaryActorTick.bCanEverTick = false;
}

AMenuMainRootWin* AMenuMainRootWin::OpenMenu(FMenuMainInitializer Initializer, TSubclassOf<AMenuMainRootWin> MenuMainClass, const UObject* WorldContextObject)
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	AMenuMainRootWin* NewMenuMain = WorldContextObject->GetWorld()->SpawnActor<AMenuMainRootWin>(MenuMainClass, Location, Rotation, SpawnInfo);
	NewMenuMain->Setup(Initializer);
	NewMenuMain->BeginOpenWin();
	return NewMenuMain;
}

void AMenuMainRootWin::Setup(FMenuMainInitializer Initializer)
{
	RootWin = this;
}


void AMenuMainRootWin::BeginChangeWin_Implementation()
{

}

TEnumAsByte<EMenuMainWins> AMenuMainRootWin::ConvertRootWinToAnyWin(TEnumAsByte<EMenuMainRootWins> RootWinByte)
{
	switch (RootWinByte) {
	case EMenuMainRootWins::EMenuMainRootWins_Overview:
		return EMenuMainWins::EMenuMainWins_Overview;
	case EMenuMainRootWins::EMenuMainRootWins_Party:
		return EMenuMainWins::EMenuMainWins_Party;
	case EMenuMainRootWins::EMenuMainRootWins_Inventory:
		return EMenuMainWins::EMenuMainWins_Inventory;
	case EMenuMainRootWins::EMenuMainRootWins_Map:
		return EMenuMainWins::EMenuMainWins_Map;
	case EMenuMainRootWins::EMenuMainRootWins_Quests:
		return EMenuMainWins::EMenuMainWins_Quests;
	case EMenuMainRootWins::EMenuMainRootWins_Stories:
		return EMenuMainWins::EMenuMainWins_Stories;
	case EMenuMainRootWins::EMenuMainRootWins_Compendium:
		return EMenuMainWins::EMenuMainWins_Compendium;
	case EMenuMainRootWins::EMenuMainRootWins_Feats:
		return EMenuMainWins::EMenuMainWins_Feats;
	case EMenuMainRootWins::EMenuMainRootWins_Settings:
		return EMenuMainWins::EMenuMainWins_Settings;
	}

	return EMenuMainWins::EMenuMainWins_Overview;
}