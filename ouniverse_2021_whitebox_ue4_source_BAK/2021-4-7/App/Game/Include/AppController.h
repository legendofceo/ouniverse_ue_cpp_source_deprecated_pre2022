// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KeynetMenuEnum.h"
#include "KeynetWorldEnum.h"
#include "KeynetsEnum.h"
#include "RemoteModes.h"
#include "MenuMainInitializer.h"
#include "Log.h"
#include "AppController.generated.h"

/**
 * 
 */

class USoftServe;

class UInputButton;
class UKeynet;
class AMenuMainRootWin;
class ACam;
class UCameraComponent;

class ULoadScreenUi;



UENUM(BlueprintType)
enum class ESuccessExecs : uint8
{
	Success,
	Fail,
};

UENUM(Blueprintable)
enum EControllerDesignation
{
	EControllerDesignationBase			UMETA(DisplayName = "Base"),
	EControllerDesignationLocal			UMETA(DisplayName = "Local"),
	EControllerDesignationRemote		UMETA(DisplayName = "Remote"),
};


UENUM(Blueprintable)
enum EPeripherals
{
	EPeripheralMouseKeyboardAndGamepad	UMETA(DisplayName = "MouseKeyboardAndGamepad"),
	EPeripheralMouseAndKeyboard			UMETA(DisplayName = "MouseAndKeyboard"),
	EPeripheralGamepad1					UMETA(DisplayName = "Gamepad1"),
	EPeripheralGamepad2					UMETA(DisplayName = "Gamepad2"),
	EPeripheralRemote1					UMETA(DisplayName = "Remote1"),
	EPeripheralRemote2					UMETA(DisplayName = "Remote2"),
	EPeripheralMax						UMETA(DisplayName = "MAX"),
};

UENUM(Blueprintable)
enum ClientBootTasksEnum
{
	ClientBootTasksAppRemote		UMETA(DisplayName = "AppRemote"),
	ClientBootTasksWorldRemote		UMETA(DisplayName = "WorldRemote"),
	ClientBootTasksPartyRemote		UMETA(DisplayName = "PartyRemote"),
	ClientBootTasksMAX				UMETA(DisplayName = "MAX"),
};

UCLASS()
class APP_API AAppController : public APlayerController
{
	GENERATED_BODY()


	AAppController();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 AppControllerIndex;

	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginPlay_SS(USoftServe* SS);

	UFUNCTION(BlueprintPure, Category = "AppController", meta = (WorldContext = "WorldContextObject"))
	static AAppController* GetAppController(const UObject* WorldContextObject);

	virtual void SetupInputComponent()  override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UInputButton*> BTs;

	void DefaultKeynet(TEnumAsByte<KeynetsEnum> Keynet);

	void SendInputButtonEvent(UInputButton* InputButton);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<ERemoteModes> RemoteMode;

	void SetRemoteMode(TEnumAsByte<ERemoteModes> InRemoteMode);
	//UObject* InputFocus;

	UPROPERTY(VisibleAnywhere)
	AMenuMainRootWin* MenuMain;

//Class Registration

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AMenuMainRootWin> MenuMainClass;

//User Config

	UFUNCTION(category="AppController / Keynet", BlueprintCallable, meta = (DisplayName = "Convert To Keynet", ExpandEnumAsExecs = Execs))
	void ConvertToKeynetBP(TEnumAsByte<KeynetsEnum> Keynet, uint8 InputCode, uint8& ConvertedInputCode, ESuccessExecs& Execs);

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<KeynetWorldEnum> KeynetConvertWorld(uint8 Byte);

		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString UserName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int UserSymbol;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UKeynet* KeynetMenu;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UKeynet* KeynetWorld;


//Global Commands

	UFUNCTION(BlueprintCallable)
	bool OpenMainMenu(FMenuMainInitializer Initializer);

	UFUNCTION(BlueprintCallable)
	bool OpenConsole();

	UFUNCTION(BlueprintCallable)
	bool PrintScreen();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* SoftServe;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULoadScreenUi* LoadScreenUi;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<ULoadScreenUi> LoadScreenUiClass;





	UFUNCTION(BlueprintCallable,Client,Reliable)
	void StartLoadScreen();
	void EndLoadScreen();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<TEnumAsByte<ClientBootTasksEnum>> ClientBootTasks;

	UFUNCTION()
	void ClientBootTaskComplete(uint8 BootTask);

	UFUNCTION(Server,Reliable)
	void SystemBooted();

	UFUNCTION(BlueprintImplementableEvent)
	void TestText();


};