// Fill out your copyright notice in the Description page of Project Settings.

#include "viewport_ue.h"
//#include "System/DebugMinimal.h"


// WARNING INIT is already registered with Viewport so use a different name


void UViewportUE::LostFocus(FViewport * InViewport)
{
	Super::LostFocus(InViewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Lost Focus...");
}

void UViewportUE::ReceivedFocus(FViewport * InViewport)
{
	Super::ReceivedFocus(InViewport);
	//DEBUGPRINT(FColor::Turquoise, "Game Gained Focus...");
}

void UViewportUE::UpdateActiveSplitscreenType()
{

}