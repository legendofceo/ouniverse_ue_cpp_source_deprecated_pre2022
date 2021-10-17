// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputList.generated.h"

UENUM(BlueprintType)
enum ECommandID
{
	CommandJump				UMETA(DisplayName = "Jump"),
	CommandCancel			UMETA(DisplayName = "Cancel"),
	CommandDodge			UMETA(DisplayName = "Dodge"),	
	CommandAccept			UMETA(DisplayName = "Accept"),
	CommandRun				UMETA(DisplayName = "Run"),
	CommandSheath			UMETA(DisplayName = "Sheath"),
	CommandStart			UMETA(DisplayName = "Start"),
	CommandSelect			UMETA(DisplayName = "Select"),

	CommandAct				UMETA(DisplayName = "Act"),
	CommandAttack			UMETA(DisplayName = "Attack"),
	CommandAttackL			UMETA(DisplayName = "AttackL"),
	CommandAttackR			UMETA(DisplayName = "AttackR"),
	CommandBlock			UMETA(DisplayName = "Block"),
	CommandBlockL			UMETA(DisplayName = "BlockL"),
	CommandBlockR			UMETA(DisplayName = "BlockR"),
	CommandArmamentUp		UMETA(DisplayName = "ArmamentUp"),
	CommandArmamentDown		UMETA(DisplayName = "ArmamentDown"),
	CommandTabLeft			UMETA(DisplayName = "TabLeft"),
	CommandTabRight			UMETA(DisplayName = "TabRight"),
	CommandPartyUp			UMETA(DisplayName = "PartyUp"),
	CommandPartyDown		UMETA(DisplayName = "PartyDown"),
	CommandParty1			UMETA(DisplayName = "Party1"),
	CommandParty2			UMETA(DisplayName = "Party2"),
	CommandParty3			UMETA(DisplayName = "Party3"),
	CommandParty4			UMETA(DisplayName = "Party4"),
};

UENUM(BlueprintType)
enum ECommandAxisID
{
	CommandAxisMoveX	UMETA(DisplayName = "MoveX"),
	CommandAxisMoveY	UMETA(DisplayName = "MoveY"),
	CommandAxisLookX	UMETA(DisplayName = "LookX"),
	CommandAxisLookY	UMETA(DisplayName = "LookY"),
	CommandAxisZoom		UMETA(DisplayName = "Zoom"),
};

UENUM(BlueprintType)
enum ECommandSpecialID
{
	CommandSpecialConsole			UMETA(DisplayName = "Console"),
	CommandSpecialPrintScreen		UMETA(DisplayName = "PrintScreen"),
};

UENUM(BlueprintType)
enum EControlType
{
	ControlTypeAny		UMETA(DisplayName = "Any"),
	ControlTypeMak		UMETA(DisplayName = "Mak"),
	ControlTypePad		UMETA(DisplayName = "Pad"),
	
};


UENUM()
enum EInputPad
{
	InputPadCross			UMETA(DisplayName = "Cross"),
	InputPadCircle			UMETA(DisplayName = "Circle"),
	InputPadSquare			UMETA(DisplayName = "Square"),
	InputPadTriangle		UMETA(DisplayName = "Triangle"),
	InputPadDUp				UMETA(DisplayName = "DPadUp"),
	InputPadDDown			UMETA(DisplayName = "DPadDown"),
	InputPadDLeft			UMETA(DisplayName = "DPadLeft"),
	InputPadDRight			UMETA(DisplayName = "DPadRight"),
	InputPadModLeft			UMETA(DisplayName = "ModLeft"),
	InputPadModRight		UMETA(DisplayName = "ModRight"),
};

UENUM()
enum EInputAxis
{
	InputAxisMakForward			UMETA(DisplayName = "MakForward"),
	InputAxisMakSide			UMETA(DisplayName = "MakSide"),
	InputAxisMakZoom			UMETA(DisplayName = "MakZoom"),
	InputAxisMakMouseX				UMETA(DisplayName = "MakMouseX"),
	InputAxisMakMouseY				UMETA(DisplayName = "MakMouseX"),
	InputAxisPadMoveX			UMETA(DisplayName = "PadMoveX"),
	InputAxisPadMoveY			UMETA(DisplayName = "PadMoveY"),
	InputAxisPadLookX			UMETA(DisplayName = "PadLookX"),
	InputAxisPadLookY			UMETA(DisplayName = "PadLookY"),
};


UENUM()
enum EInputMak
{
	InputMakUp			UMETA(DisplayName = "Up"),
	InputMakDown		UMETA(DisplayName = "Down"),
	InputMakLeft		UMETA(DisplayName = "Left"),
	InputMakRight		UMETA(DisplayName = "Right"),
	InputMakInteract	UMETA(DisplayName = "Interact"),
	InputMakMouseLeft	UMETA(DisplayName = "MouseLeft"),
	InputMakMouseRight	UMETA(DisplayName = "MouseRight"),

};