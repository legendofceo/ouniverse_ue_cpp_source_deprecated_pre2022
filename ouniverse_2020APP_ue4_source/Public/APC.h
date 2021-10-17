// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputList.h"
#include "APC.generated.h"

/**
 * 
 */



class UCameraComponent;
class UBindPad;

//Required Variables
class UUiHud;
class UUiMouse;
class UUiMouseStyle;
class UUiInterest;

class UBindSpecial;
class UBindMak;
class UBindPad;
class UBindAxis;
class UBindAxisFaux;

class AActra;
class UCommand;
class UCommandAxis;

class UPartyMember;

UENUM()
enum EMouseStyle
{
	MouseStyleDefault		UMETA(DisplayName = "MouseStyleDefault"),
};

UENUM(BlueprintType)
enum ETabSelectionMode
{
	TabSelectionModeAll		 UMETA(DisplayName = "All"),
	TabSelectionModeTarget	 UMETA(DisplayName = "Characters"),
};

UENUM(BlueprintType)
enum EInputParadigm
{
	InputParadigmStandard			UMETA(DisplayName = "Standard"),
	InputParadigmTabSelect			UMETA(DisplayName = "TabSelect"),
	InputParadigmMenuController		UMETA(DisplayName = "MenuController"),
	InputParadigmMenuMouse			UMETA(DisplayName = "MenuMouse"),
};


UCLASS()
class ETREIAAPP_API APC : public APlayerController
{
	GENERATED_BODY()

	APC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 ControlIndex;

public:

	//Required Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUiHud> UiHudSoftClass;

public:


	UFUNCTION(BlueprintCallable,BlueprintPure)
	static APC* GetPC();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ACM* GetCM();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACM* CM;

	void MakeBindings();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUiMouse* UiMouse;


	UPROPERTY(replicated, VisibleAnywhere, BlueprintReadOnly)
	UUiHud* UiHud;

	UPROPERTY(replicated,VisibleAnywhere, BlueprintReadOnly)
	int32 PlayerIndex;

	UFUNCTION(Reliable, Client)
	void SetupUi();

	UFUNCTION(BlueprintCallable)
	void MatchCamera(UCameraComponent* InCamera);

	void SetupInputComponent() override;

	UFUNCTION()
	void Fuck();

	UFUNCTION()
	virtual void PlayerTick(float DeltaTime) override;


	void AuxModeStart();
	void AuxModeEnd();

//MOUSE RELATED

	//Required Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUiMouse> MouseClass;

	UFUNCTION(BlueprintCallable)
	FVector2D GetMousePos();

	void ActivateMouse();
	void DeactivateMouse();
	void ResetMouse();
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<TEnumAsByte<EMouseStyle>, TSubclassOf<UUiMouseStyle>> MouseStyles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bMouseActivated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bAllowMouseInteractive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* MouseHoveredActor;


	UFUNCTION(Reliable, Client)
	void OpenHud(bool bAnimate);


//INPUT


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UObject* InputInterface = NULL;

	UFUNCTION(BlueprintCallable)
	void SetInputInterface(UObject* InterfaceInputObject);
	
	UFUNCTION(BlueprintCallable)
	void ClearInputInterface();

	void UpdateControlMode();
	bool AllowInputFromControl(TEnumAsByte<EControlType> ControlType);

	void SendCommand(UCommand* Command);
	void SendCommandAxis(UCommandAxis* Command);
	void SendSpecial(TEnumAsByte<ECommandSpecialID> Command, bool bPressed);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindSpecial* SpecialConsole;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindSpecial* SpecialPrintScreen;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindMak* MakInteract;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindMak* MakJump;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadModLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadCross;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadCircle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadSquare;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadTriangle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadDUp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadDDown;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadDLeft;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindPad* PadDRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxis* AxisMakMouseX;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxis* AxisMakMouseY;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxis* AxisPadMoveX;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxis* AxisPadMoveY;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxis* AxisPadLookX;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxis* AxisPadLookY;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxisFaux* MakForward;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBindAxisFaux* MakSide;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EControlType> ControlMode;

	UFUNCTION()
	void PadAxisDetector(float Power);

//PILOT

	UFUNCTION()
	void ConnectToParty();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int PartySlot;

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	virtual void Pilot(APawn* InPawn);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APawn* PilotedGoal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APawn* PilotedBase;

//PARTY

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMember* PartyMember = NULL;


//INPUT ADVANCED


	UFUNCTION(BlueprintCallable)
	bool DabbleCommand(const UCommand* Command);

	UFUNCTION(BlueprintCallable)
	bool DabbleCommandAxis(const UCommandAxis* CommandAxis);


//INPUT PARADIGM


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EInputParadigm> InputParadigm;

	void SetInputParadigm(EInputParadigm InInputParadigm);


//TAB


	void SetTabSelected(UObject* NewTabSelected);
	void ClearTabSelected();

	UFUNCTION(BlueprintCallable)
	void TabSelectNext(bool bLeft, const ETabSelectionMode Mode);
	
	UFUNCTION(BlueprintCallable)
	void PartySelectNext(bool bDown);


	//UFUNCTION(Reliable, Client)
	///void TabSelectNext(TEnumAsByte<ETabSelectDirection> Direction, TEnumAsByte<ETabSelectionMode> Mode) ;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UObject* TabSelected = NULL;

};
