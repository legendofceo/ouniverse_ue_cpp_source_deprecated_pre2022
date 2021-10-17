// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AreaAddress.h"
#include "Log.h"
#include "AppMode.generated.h"

class UApp;
class ULogic;
class AAppController;
class AAppRemote;

class UPlayerManager;
class USoftServe;


/** Default delegate for callbacks */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppModeDelegate);



/**
 * The AppMode extends UE5 GameMode.
 * The program is booted by calling the Boot function.
 * Handles Multiplayer connections by housing AppPlayers and connecting with with AppControllers.
 */


UCLASS()
class APP_API AAppMode : public AGameModeBase
{
	GENERATED_BODY()

	AAppMode();

public:

	static const int MaxPlayers = 4;

	virtual void BeginPlay() override;

	static AAppMode* Get();

	/** Static Getter of the AppMode casting from UE5's GetGameMode. */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static AAppMode* GetAppMode(const UObject* WorldContextObject);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInitialized = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UApp* App;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	//~=============================================================================
	// Boot

	/**
	* The AppMode is responsible for booting the program.
	* The main systems are loaded asynchronously. Primarily the Pro and Mem systems.
	* The OnBootComplete delegate is called when the process ends.
	*/

	/**
	* The first function to be called which boots the game.
	* It has it's own function in case parameters need to be added.
	* This must be called from an empty level and occur 
	* a HasAuthority==true switch
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#BootEverything"))
	void Boot();

	/** The LazyLoaded continuation of Boot after the SoftClasses are loaded. */
	UFUNCTION()
	void Boot_SS(USoftServe* SoftServe);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* SS;

	/** Delegate broadcasted at the conclusion of the boot process. */
	UPROPERTY(BlueprintAssignable)
	FAppModeDelegate OnBootComplete;

	//~=============================================================================
	// Mem System Boot

	/**
	* The Mem (Memory) are ethereal data objects which hold all of the games data 
	* and run some of the logic. It also handles savegame states.
	* This system is created in it's entirety during the boot process.
	*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<UObject*> InitTasks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppRemote* AppRemote;


	//~=============================================================================
	// Logic

	/**
	* A centralized point to fire logic from. Logics are blank 
	* slate operators that function as a scripting language through UE5 Blueprints.
	*/
	UFUNCTION()
	ULogic* DoLogic(TSubclassOf<ULogic> Logic);

};
