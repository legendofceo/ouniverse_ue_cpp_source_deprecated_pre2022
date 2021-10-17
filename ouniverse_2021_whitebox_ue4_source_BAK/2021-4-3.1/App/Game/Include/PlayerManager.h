// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RemoteModes.h"
#include "PlayerManager.generated.h"


class AAppController;

UCLASS()
class APP_API UPlayerManager : public UObject
{
	GENERATED_BODY()

public:

	void Init();

	/**
* When players join the new controller (AppController) is reported to the AppMode.
* AppMode assigns a player to the controller once reported.
*/

	void ReceivePlayer(AAppController* AppController);

	/**
	* The BaseController is the first AppController to connect. This is always
	* always present as it cannot be disconnected.
	*/
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		AAppController* BaseController;

	/** Array of AppControllers that are currently connected for debugging. */
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TArray<AAppController*> AppControllers;

	/** Add a local player to the game. */
	void AddLocalPlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ERemoteModes> RemoteMode;

	void SetAllRemotes(TEnumAsByte<ERemoteModes> InRemoteMode);
};
