// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../Enum/EKeynetMenu.h"
#include "../Enum/EKeynetWorld.h"
#include "../Enum/EKeynets.h"
#include "MenuMainInitializer.h"
#include "AppController.generated.h"

/**
 * 
 */

class UInputButton;
class UKeynet;
class AMenuMainRootWin;
class ACam;
class UCameraComponent;
class UPeripheral;
class AAppPlayer;


class UAppPro;
class UStoryPro;
class UPartyPro;

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


UCLASS()
class APP_API AAppController : public APlayerController
{
	GENERATED_BODY()


	AAppController();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 AppControllerIndex;

	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginPlayLL();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppPlayer* AppPlayer;

	UFUNCTION(BlueprintPure, Category = "AppController", meta = (WorldContext = "WorldContextObject"))
	static AAppController* GetAppController(const UObject* WorldContextObject);

	virtual void SetupInputComponent()  override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UInputButton*> BTs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EPeripherals> Peripheral;

	void SetPeripheral(TEnumAsByte<EPeripherals> InPeripheral);
	void SetAppPlayer(AAppPlayer* InAppPlayer);

	void DefaultKeynet(TEnumAsByte<EKeynets> Keynet);

	void SendInputButtonEvent(UInputButton* InputButton);


	//UObject* InputFocus;

	UPROPERTY(VisibleAnywhere)
	AMenuMainRootWin* MenuMain;

//Class Registration

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AMenuMainRootWin> MenuMainClass;

//User Config

	UFUNCTION(category="AppController / Keynet", BlueprintCallable, meta = (DisplayName = "Convert To Keynet", ExpandEnumAsExecs = Execs))
	void ConvertToKeynetBP(TEnumAsByte<EKeynets> Keynet, uint8 InputCode, uint8& ConvertedInputCode, ESuccessExecs& Execs);

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<EKeynetWorld> KeynetConvertWorld(uint8 Byte);

		
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
	UAppPro* AppPro;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStoryPro* StoryPro;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyPro* PartyPro;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UAppPro> AppProClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UStoryPro> StoryProClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UPartyPro> PartyProClass;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULoadScreenUi* LoadScreenUi;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<ULoadScreenUi> LoadScreenUiClass;





	UFUNCTION(BlueprintCallable,Client,Reliable)
	void StartLoadScreen();
	void EndLoadScreen();
};