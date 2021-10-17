// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EMenuMainWins.generated.h"


UENUM(BlueprintType)
enum EMenuMainWins
{
	EMenuMainWins_Exit  UMETA(DisplayName = "Exit"),
	EMenuMainWins_Default  UMETA(DisplayName = "Default"),
	EMenuMainWins_Overview  UMETA(DisplayName = "Overview"),
	EMenuMainWins_Party  UMETA(DisplayName = "Party"),
	EMenuMainWins_Inventory  UMETA(DisplayName = "Inventory"),
	EMenuMainWins_Map  UMETA(DisplayName = "Map"),
	EMenuMainWins_Quests  UMETA(DisplayName = "Quests"),
	EMenuMainWins_Stories  UMETA(DisplayName = "Stories"),
	EMenuMainWins_Compendium  UMETA(DisplayName = "Compendium"),
	EMenuMainWins_Feats  UMETA(DisplayName = "Feats"),
	EMenuMainWins_Settings  UMETA(DisplayName = "Settings"),
	EMenuMainWins_MAX UMETA(DisplayName = "MAX"),
};

UENUM(BlueprintType)
enum EMenuMainRootWins
{
	EMenuMainRootWins_Default  UMETA(DisplayName = "Default"),
	EMenuMainRootWins_Overview  UMETA(DisplayName = "Overview"),
	EMenuMainRootWins_Party  UMETA(DisplayName = "Party"),
	EMenuMainRootWins_Inventory  UMETA(DisplayName = "Inventory"),
	EMenuMainRootWins_Map  UMETA(DisplayName = "Map"),
	EMenuMainRootWins_Quests  UMETA(DisplayName = "Quests"),
	EMenuMainRootWins_Stories  UMETA(DisplayName = "Stories"),
	EMenuMainRootWins_Compendium  UMETA(DisplayName = "Compendium"),
	EMenuMainRootWins_Feats  UMETA(DisplayName = "Feats"),
	EMenuMainRootWins_Settings  UMETA(DisplayName = "Settings"),
	EMenuMainRootWins_MAX UMETA(DisplayName = "MAX"),
};