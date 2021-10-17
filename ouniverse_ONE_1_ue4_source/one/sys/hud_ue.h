// Fill out your copyright notice in the Description page of Project Settings.

/**

## AControlUE

AControlUE is an exension to UE4's AHud.

The Coherent Lab's Ui solution extends this.
This is an extension of Coherent Lab's extension for further control.

#### Tasks
* Sets up the primary UI overlay.
* Outputs a UI bridge singleton to access all of Coherent Lab's functionality.

 */


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "hud_ue.generated.h"


UCLASS()
class AHudUE : public AHUD
{
	GENERATED_BODY()

public:

	AHudUE();
	static AHudUE* Get(AActor* WorldActor);

	UPROPERTY()
	USceneComponent* Dock;

};
