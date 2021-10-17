// Fill out your copyright notice in the Description page of Project Settings.

/**

## Mode

Extends UE4's AGameMode and holds default game mode assignments.

#### Current Swaps:
* APlayerController to AControLUE
* AHud to AHudUE

*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ModeUE.generated.h"


UCLASS()
class OUNIVERSE_API AModeUE : public AGameModeBase
{
	GENERATED_BODY()
	
	AModeUE();

};
