// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AreaAddress.h"
#include "Log.h"
#include "Tally.h"
#include "Delegate.h"
#include "AppMode.generated.h"

class UApp;
class AAppController;


class USoftServe;


class UMythPro;



/**
 * The AppMode extends UE5 GameMode.
 * The program is booted by calling the Boot function.
 * Handles Multiplayer connections by housing AppPlayers and connecting with with AppControllers.
 */


UENUM(Blueprintable)
enum class EAppPros : uint8
{
	None		UMETA(DisplayName = "None"),
	Outer		UMETA(DisplayName = "Outer"),
	Myth		UMETA(DisplayName = "Myth"),
};


UCLASS()
class APP_API AAppMode : public AGameModeBase
{
	GENERATED_BODY()

	AAppMode();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit = false;

	static const int MaxPlayers = 4;

	virtual void BeginPlay() override;

	static AAppMode* Get();

	/** Static Getter of the AppMode casting from UE5's GetGameMode. */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static AAppMode* GetAppMode(const UObject* WorldContextObject);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UApp* App;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EAppPros Pro;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EAppPros ProPending;


	void SetPro(EAppPros InPro);

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
	FDelegate OnBootComplete;

	//~=============================================================================
	// Mem System Boot

	/**
	* The Mem (Memory) are ethereal data objects which hold all of the games data 
	* and run some of the logic. It also handles savegame states.
	* This system is created in it's entirety during the boot process.
	*/

	UPROPERTY(VisibleAnywhere)
	FTallyObj TallySystems;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMythPro* MythPro;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UMythPro> MythProClass;

	UFUNCTION()
	void SubInitComplete(UObject* SystemObj);


	/** Array of AppControllers that are currently connected, Stored only for proof. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AAppController*> AppControllers;

	/**
	* When players join the new controller (AppController) is reported to the AppMode.
	* AppMode assigns a player to the controller once reported.
	*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AAppController*> PendingPlayers;


	void ReceiveNewPlayer(AAppController* AppController);
	void ConnectPendingPlayers();
	void ConnectNewPlayer(AAppController* AppController);

	/**
	* The BaseController is the first AppController to connect. This is always
	* always present as it cannot be disconnected.
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppController* BaseController;

	/** Add a local player to the game. */
	void AddLocalPlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bMultiplayer = false;

	bool IsMultiplayer();
};
