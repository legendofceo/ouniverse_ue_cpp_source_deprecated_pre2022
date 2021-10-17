// Fill out your copyright notice in the Description page of Project Settings.

/**

## AViewportUE

An extension to UE4's AViewport.

The program required access to window focus lost or received and this was the only way.

**Warning:**  *UE4 already uses Init as a function in Viewport so it can't be used.*
**Warning:** *If this code is related to a crash it's because this custom viewport got unset as the viewport to use in the UE4 editor settings.*

 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "viewport_ue.generated.h"


UCLASS()
class UViewportUE : public UGameViewportClient
{
	GENERATED_BODY()

public:

	//UE4 already was using UGameViewportClient::Init()

	void LostFocus(FViewport* InViewport) override;
	void ReceivedFocus(FViewport* InViewport) override;

	virtual void UpdateActiveSplitscreenType() override;

};