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
class UWorldAnnex;

class UPlayerManager;

class USoftServe;

class ULib;
class UAnnex;


/** Default delegate for callbacks */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppModeDelegate);


UENUM(BlueprintType)
enum EAppState
{
	EAppStateAppVoid	UMETA(DisplayName = "Void"),
	EAppStateAppMenu	UMETA(DisplayName = "AppMenu"),
	EAppStateStory		UMETA(DisplayName = "Story"),
	EAppStateMainMenu	UMETA(DisplayName = "MainMenu"),

};

/** Multiplayer connection state of the game, recorded in AppMode incase it's needed. */
UENUM(Blueprintable)
enum EPlayerConnectionMode
{
	EPlayerConnectionModeSolo    UMETA(DisplayName = "Solo"),
	EPlayerConnectionModeLocal    UMETA(DisplayName = "Local"),
	EPlayerConnectionModeRemote    UMETA(DisplayName = "Remote"),
};

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


	virtual void BeginPlay() override;

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
	void BootLL(USoftServe* SoftServe);

	UFUNCTION()
	void InitComplete(UObject* Object);

	/** Does cleanup and calls the OnBootComplete Delegate. */
	UFUNCTION()
	void BootComplete();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* BootSS;

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
	UWorldAnnex* WorldAnnex;

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UWorldAnnex> WorldAnnexClass = NULL;


	void SetAllRemotes(TEnumAsByte<ERemoteModes> InRemoteMode);

	void ReceivePlayer(AAppController* AppController);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPlayerManager* PlayerManager;

	//~=============================================================================
	// Logic

	/**
	* A centralized point to fire logic from. Logics are blank 
	* slate operators that function as a scripting language through UE5 Blueprints.
	*/
	UFUNCTION()
	ULogic* DoLogic(TSubclassOf<ULogic> Logic);

};
