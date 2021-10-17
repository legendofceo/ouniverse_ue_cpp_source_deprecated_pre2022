// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RemoteModes.generated.h"


UENUM(Blueprintable)
enum ERemoteModes
{
	ERemoteModesNone		UMETA(DisplayName = "None"),
	ERemoteModesWorld	UMETA(DisplayName = "World"),
};