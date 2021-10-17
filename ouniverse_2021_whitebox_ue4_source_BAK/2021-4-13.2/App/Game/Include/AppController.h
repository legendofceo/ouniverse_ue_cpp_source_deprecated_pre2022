// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KeynetMenuEnum.h"
#include "KeynetWorldEnum.h"
#include "KeynetsEnum.h"
#include "MenuMainInitializer.h"
#include "Log.h"
#include "Execs.h"
#include "AppController.generated.h"

/**
 * 
 */

class USoftServe;

class AAppBae;

class UInputButton;
class UKeynet;
class AMenuMainRootWin;
class ACam;
class UCameraComponent;

class ULoadScreenUi;

class URemote;
class UAppRemote;
class UMythRemote;
class USpectatorRemote;
class UPartyRemote;
class UCompanionRemote;

class USpectatorUi;

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

	void InitAfterServerSystemsReady();

	UFUNCTION(BlueprintPure, Category = "AppController", meta = (WorldContext = "WorldContextObject"))
	static AAppController* GetAppController(const UObject* WorldContextObject);

	virtual void SetupInputComponent()  override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppBae* Bae;

	void Host();

	bool IsHost();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bHost = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAppRemote* AppRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMythRemote* MythRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpectatorRemote* SpectatorRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyRemote* PartyRemote;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCompanionRemote* CompanionRemote;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<USpectatorUi> SpectatorUiClass;

//Keynet Input

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UInputButton*> BTs;

	void DefaultKeynet(TEnumAsByte<KeynetsEnum> Keynet);

	void SendInputButtonEvent(UInputButton* InputButton);


	//UObject* InputFocus;

	UPROPERTY(VisibleAnywhere)
	AMenuMainRootWin* MenuMain;

//Class Registration

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AMenuMainRootWin> MenuMainClass;

//User Config

	UFUNCTION(category="AppController / Keynet", BlueprintCallable, meta = (DisplayName = "Convert To Keynet", ExpandEnumAsExecs = Execs))
	void ConvertToKeynetBP(TEnumAsByte<KeynetsEnum> Keynet, uint8 InputCode, uint8& ConvertedInputCode, ESuccess& Execs);

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
	USpectatorUi* SpectatorUi;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULoadScreenUi* LoadScreenUi;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<ULoadScreenUi> LoadScreenUiClass;





	UFUNCTION(BlueprintCallable,Client,Reliable)
	void StartLoadScreen();
	void EndLoadScreen();



	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="@PrintText"))
	void DebugTextBP(const FString& Text);


	UFUNCTION(Server, Reliable)
	void Engage_SER();

};