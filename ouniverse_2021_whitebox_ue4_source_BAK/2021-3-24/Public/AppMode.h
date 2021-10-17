// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AppMode.generated.h"

class AAppMem;
class AAppPro;
class AApController;
class UAppMemInitializer;
class AAppPlayer;
class ULogic;

/** Default delegate for callbacks */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppModeDelegate);


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

	/** Static Getter of the AppMode casting from UE5's GetGameMode. */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static AAppMode* GetAppMode(const UObject* WorldContextObject);



	//~=============================================================================
	// Boot

	/**
	* The AppMode is responsible for booting the program.
	* The main systems are loaded asynchronously. Primarily the Pro and Mem systems.
	* The OnBootComplete delegate is called when the process ends.
	*/

	/** Begins the BOOT process. This must be called from an empty ULevel BeginPlay event. */
	UFUNCTION(BlueprintCallable)
	void Boot();

	/** The LazyLoaded continuation of Boot after the SoftClasses are loaded. */
	UFUNCTION()
	void BootLL();

	/** Does cleanup and calls the OnBootComplete Delegate. */
	UFUNCTION()
	void BootComplete();

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

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<AAppMem> AppMemClass = NULL;

	/** Storage of the Mem singleton. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppMem* AppMem = NULL;




	//~=============================================================================
	// Pro System Boot

	/**
	* The Pro (Protocol) are a group of actors each handeling a certain control state 
	* that the game can be in. These are all created at once during boot and data is 
	* slotted into them as their control targets change.
	* AppMode creates this system in it's entirety during the boot process.
	*/

	/** SoftClassPointer of the Mem singeleton. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<AAppPro> AppProClass = NULL;

	/** Storage of the Pro singleton. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppPro* AppPro = NULL;

	/** Sets up the Pro singleton. Separated for asynchronous processing. */
	UFUNCTION()
	void SetupAppPro();




	//~=============================================================================
	// Multiplayer Management

	/**
	* During BOOT The AppMode creates an AppPlayer for every potential player that can join at once.
	*/
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly)
	TArray<AAppPlayer*> AppPlayers;

public:
	/**
	* When players join the new controller (AppController) is reported to the AppMode.
	* AppMode assigns a player to the controller once reported.
	*/
	UFUNCTION(BlueprintCallable)
	void AddAppController(AAppController* AppController);

private:
	/**
	* The BaseController is the first AppController to connect. This is always
	* always present as it cannot be disconnected.
	*/
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AAppController* BaseController;

	/** Array of AppControllers that are currently connected for debugging. */
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<AAppController*> AppControllers;

	/** The multiplayer state of the game. Solo, Local or Remote. */
	UPROPERTY(Category = "Players Management", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EPlayerConnectionMode> PlayerConnectionMode;

public:
	/** Add a local player to the game. */
	void AddLocalPlayer();




	//~=============================================================================
	// Logic

	/**
	* A centralized point to fire logic from. Logics are blank 
	* slate operators that function as a scripting language through UE5 Blueprints.
	*/
	UFUNCTION()
	ULogic* DoLogic(TSubclassOf<ULogic> Logic);

};
