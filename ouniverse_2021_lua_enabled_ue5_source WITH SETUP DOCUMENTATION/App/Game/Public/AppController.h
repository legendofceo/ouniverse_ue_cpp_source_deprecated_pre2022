// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CommandsMenu.h"
#include "AppController.generated.h"

class AAppPro;
class AAppCam;
class UCameraComponent;
class UInputMap;

class UMouseUi;

class UNotificationWin;
class UNotificationUi;

class UBT; class UAX;

DECLARE_DELEGATE_OneParam(FDelBasicBT, UBT*);
DECLARE_DELEGATE_OneParam(FDelBasicAX, UAX*);

UENUM(BlueprintType)
enum class EPeripheralMode : uint8
{
	Mouse  UMETA(DisplayName = "Mouse"),
	Gamepad  UMETA(DisplayName = "Gamepad"),
};


DECLARE_DYNAMIC_DELEGATE_OneParam(FDelDynamicBT, UBT*, BT);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDelDynamicAX, UAX*, AX);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDelDynamicPeripheralMode, EPeripheralMode, PeripheralMode);

DECLARE_MULTICAST_DELEGATE_OneParam(FDelMulticastBT, UBT*);
DECLARE_MULTICAST_DELEGATE_OneParam(FDelMulticastAX, UAX*);

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelDynamicMulticastBT, UBT*, BT);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelDynamicMulticastAX, UAX*, AX);


USTRUCT(Blueprintable, BlueprintType)
struct APP_API FListenerPeripheralMode
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FName Context;

	UPROPERTY(VisibleAnywhere)
	UObject* Subscriber;

	FDelDynamicPeripheralMode Delegate;

};

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FListenerBT
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FName Context;

	UPROPERTY(VisibleAnywhere)
	UObject* Subscriber;

	FDelDynamicBT Delegate;

};

USTRUCT(Blueprintable, BlueprintType)
struct APP_API FListenerAX
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FName Context;

	UPROPERTY(VisibleAnywhere)
	UObject* Subscriber;

	FDelDynamicAX Delegate;

};

UCLASS()
class APP_API AAppController : public APlayerController
{
	GENERATED_BODY()


	AAppController();

	static const FName SYS;

public:

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppCam* Cam;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 AppControllerIndex;

	virtual void BeginPlay() override;

	static AAppController* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":AppController"))
	static void GetAppController(AAppController*& AppController);

	virtual void SetupInputComponent()  override;
	
	void SetDefaultCommands();


//Input Buttons/Axis

	void SetPeripheralMode(EPeripheralMode InPeripheralMode, bool bSilent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EPeripheralMode PeripheralMode;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#IsPeripheralModeMouse"))
	bool IsPeripheralModeMouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetPeripheralMode"))
	EPeripheralMode GetPeripheralMode();

	UBT* GetBT(uint8 Byte);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UBT*> BTs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UAX*> AXs;

	void BT(UBT* BT);
	void AX(UAX* AX);

	FDelMulticastBT OnBT;
	FDelMulticastAX OnAX;

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#SubscribeBT",DefaultToSelf="Subscriber"))
	void SubscribeBT(FName Context, UObject* Subscriber, const FDelDynamicBT& Event);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#SubscribeAX", DefaultToSelf = "Subscriber"))
	void SubscribeAX(FName Context, UObject* Subscriber, const FDelDynamicAX& Event);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#SubscribeMode", DefaultToSelf = "Subscriber"))
	void SubscribePeripheralMode(FName Context, UObject* Subscriber, const FDelDynamicPeripheralMode& Event);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#UnsubscribeBT", DefaultToSelf = "Subscriber"))
	void UnsubscribeBT(UObject* Subscriber);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#UnsubscribeAX", DefaultToSelf = "Subscriber"))
	void UnsubscribeAX(UObject* Subscriber);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#UnsubscribePeripheralMode", DefaultToSelf = "Subscriber"))
	void UnsubscribePeripheralMode(UObject* Subscriber);

	UPROPERTY(VisibleAnywhere)
	TArray<FListenerBT> SubscriptionsBT;
	UPROPERTY(VisibleAnywhere)
	TArray<FListenerAX> SubscriptionsAX;
	UPROPERTY(VisibleAnywhere)
	TArray<FListenerPeripheralMode> SubscriptionsPeripheralMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<CommandMenu> BindMapMenu;

	
	CommandMenu GetCommand(UBT* BT);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#GetCommandMenu"))
	void GetCommandMenu(UBT* BT, CommandMenu& Command);


//Mouse

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#StartMouseMode"))
	void StartMouseMode(FName Context);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#EndMouseMode"))
	void EndMouseMode();

	UPROPERTY(VisibleAnywhere)
	FName MouseModeContext;

	UPROPERTY(VisibleAnywhere)
	bool bMouseMode = false;

	UPROPERTY(VisibleAnywhere)
	float DpiScale=0.0;

	UPROPERTY(VisibleAnywhere)
	float MouseLastX=0.0;
	UPROPERTY(VisibleAnywhere)
	float MouseLastY=0.0;

	UPROPERTY(VisibleAnywhere)
	float MouseDeltaX=0.0;
	UPROPERTY(VisibleAnywhere)
	float MouseDeltaY=0.0;



	UPROPERTY(VisibleAnywhere)
	UMouseUi* MouseUi = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMouseUi> MouseUiClass = nullptr;

//Pawn and Cam


	void Pilot(APawn* InPawn);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APawn* PossessedPawn = nullptr;

	void ForceCam(UCameraComponent* CamTarget);


//Notification

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UNotificationWin* NotificationWin = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UNotificationWin> NotificationWinClass = nullptr;


	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UNotificationUi> NotificationPeripheralModeMouse;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UNotificationUi> NotificationPeripheralModeGamepad;

};