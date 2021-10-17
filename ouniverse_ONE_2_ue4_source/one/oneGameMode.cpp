// Fill out your copyright notice in the Description page of Project Settings.

#include "oneGameMode.h"
#include "oneCharacter.h"
#include "UObject/ConstructorHelpers.h"

AoneGameMode::AoneGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
