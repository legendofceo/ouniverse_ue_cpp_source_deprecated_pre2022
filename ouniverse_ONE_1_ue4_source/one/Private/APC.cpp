// Fill out your copyright notice in the Description page of Project Settings.


#include "APC.h"
#include "ACM.h"
#include "AGS.h"
#include "Kismet/GameplayStatics.h"
#include "InterfacePilot.h"
#include "Net/UnrealNetwork.h"
#include "Camera/CameraComponent.h"
#include "Input.h"
#include "AGM.h"
#include "UiHud.h"
#include "UiMouse.h"
#include "UiHudElect.h"
#include "CollisionTypes.h"
#include "InterfaceInteractive.h"
#include "InterfaceInput.h"
#include "Statics.h"
#include "Command.h"
#include "Party.h"
#include "Actra.h"


APC::APC()
{
	bReplicates = true;
	bAutoManageActiveCameraTarget = false;
	bAllowMouseInteractive = true;
}

APC* APC::GetPC()
{
	return Cast<APC>(UGameplayStatics::GetPlayerController(AGS::GetGS(),0));
}


// Called when the game starts or when spawned
void APC::BeginPlay()
{
	Super::BeginPlay();

	CM = Cast<ACM>(PlayerCameraManager);

	ControlIndex = GetInputIndex();

	AGameModeBase* BaseGameMode = GetWorld()->GetAuthGameMode();

	if (IsValid(BaseGameMode))
	{
		Cast<AGM>(BaseGameMode)->AddPlayer(this);
	}

	SetupUi();

}

ACM* APC::GetCM()
{
	return CM;
}

void APC::SetupInputComponent()
{
	Super::SetupInputComponent();
	MakeBindings();
}

void APC::MakeBindings()
{
	//Specials
	SpecialPrintScreen = NewObject<UBindSpecial>(this, UBindSpecial::StaticClass(), "SpecialPrintScreen");
	SpecialPrintScreen->RegisterComponent();
	SpecialPrintScreen->Setup(this, ECommandSpecialID::CommandSpecialPrintScreen, "printscreen");

	SpecialConsole = NewObject<UBindSpecial>(this, UBindSpecial::StaticClass(), "SpecialConsole");
	SpecialConsole->RegisterComponent();
	SpecialConsole->Setup(this, ECommandSpecialID::CommandSpecialPrintScreen, "console");

	//Mak
	MakInteract = NewObject<UBindMak>(this, UBindMak::StaticClass(), "MakInteract");
	MakInteract->RegisterComponent();
	MakInteract->Setup(this, "interact");
	MakInteract->Clean = ECommandID::CommandAccept;

	MakJump = NewObject<UBindMak>(this, UBindMak::StaticClass(), "MakJump");
	MakJump->RegisterComponent();
	MakJump->Setup(this, "jump");
	MakJump->Clean = ECommandID::CommandJump;

	PadModLeft = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadModLeft");
	PadModLeft->RegisterComponent();
	PadModLeft->Setup(this, EInputPad::InputPadModLeft, "Gamepad_FaceButton_Bottom");
	PadModLeft->Output.Open = ECommandID::CommandAccept;

	PadCross = NewObject<UBindPad>(this,UBindPad::StaticClass(),"PadCross");
	PadCross->RegisterComponent();
	PadCross->Setup(this, EInputPad::InputPadCross,"Gamepad_FaceButton_Bottom");
	PadCross->Output.Open = ECommandID::CommandAccept;

	PadCircle = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadCircle");
	PadCircle->RegisterComponent();
	PadCircle->Setup(this, EInputPad::InputPadCircle, "Gamepad_FaceButton_Right");
	PadCircle->Output.Open = ECommandID::CommandCancel;

	PadSquare = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadSquare");
	PadSquare->RegisterComponent();
	PadSquare->Setup(this, EInputPad::InputPadSquare, "Gamepad_FaceButton_Left");
	PadSquare->Output.Open = ECommandID::CommandDodge;
	
	PadTriangle = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadTriangle");
	PadTriangle->RegisterComponent();
	PadTriangle->Setup(this, EInputPad::InputPadTriangle, "Gamepad_FaceButton_Top");
	PadTriangle->Output.Open = ECommandID::CommandJump;


	PadDUp = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadDPadUp");
	PadDUp->RegisterComponent();
	PadDUp->Setup(this, EInputPad::InputPadDUp, "Gamepad_DPad_Up");
	PadDUp->Output.Open = ECommandID::CommandPartyUp;

	PadDDown = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadDPadDown");
	PadDDown->RegisterComponent();
	PadDDown->Setup(this, EInputPad::InputPadDDown, "Gamepad_DPad_Down");
	PadDDown->Output.Open = ECommandID::CommandPartyDown;

	PadDLeft = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadDPadLeft");
	PadDLeft->RegisterComponent();
	PadDLeft->Setup(this, EInputPad::InputPadDLeft, "Gamepad_DPad_Left");
	PadDLeft->Output.Open = ECommandID::CommandTabLeft;

	PadDRight = NewObject<UBindPad>(this, UBindPad::StaticClass(), "PadDPadRight");
	PadDRight->RegisterComponent();
	PadDRight->Setup(this, EInputPad::InputPadDRight, "Gamepad_DPad_Right");
	PadDRight->Output.Open = ECommandID::CommandTabRight;


	//FauxAxis
	MakForward = NewObject<UBindAxisFaux>(this, UBindAxisFaux::StaticClass(), "MakForward");
	MakForward->RegisterComponent();
	MakForward->Clean = CommandAxisMoveY;
	MakForward->Setup(this,EInputAxis::InputAxisMakForward,"W","S");
	
	MakSide = NewObject<UBindAxisFaux>(this, UBindAxisFaux::StaticClass(), "MakSide");
	MakSide->RegisterComponent();
	MakSide->Clean = CommandAxisMoveX;
	MakSide->Setup(this, EInputAxis::InputAxisMakSide, "A", "D");

	//Axis
	AxisMakMouseX = NewObject<UBindAxis>(this, UBindAxis::StaticClass(), "MakMouseX");
	AxisMakMouseX->RegisterComponent();
	AxisMakMouseX->Setup(this, EInputAxis::InputAxisMakMouseX, "MouseX", EControlType::ControlTypeMak);
	AxisMakMouseX->Clean = CommandAxisLookX;

	AxisMakMouseY = NewObject<UBindAxis>(this, UBindAxis::StaticClass(), "MakMouseY");
	AxisMakMouseY->RegisterComponent();
	AxisMakMouseY->Setup(this, EInputAxis::InputAxisMakMouseY, "MouseY", EControlType::ControlTypeMak);
	AxisMakMouseY->Clean = CommandAxisLookY;

	AxisPadMoveX = NewObject<UBindAxis>(this, UBindAxis::StaticClass(), "PadMoveX");
	AxisPadMoveX->RegisterComponent();
	AxisPadMoveX->Setup(this, EInputAxis::InputAxisPadMoveX,"Gamepad_LeftX", EControlType::ControlTypePad);
	AxisPadMoveX->Clean = CommandAxisMoveX;

	AxisPadMoveY = NewObject<UBindAxis>(this, UBindAxis::StaticClass(), "PadMoveY");
	AxisPadMoveY->RegisterComponent();
	AxisPadMoveY->Setup(this, EInputAxis::InputAxisPadMoveY, "Gamepad_LeftY", EControlType::ControlTypePad);
	AxisPadMoveY->Clean = CommandAxisMoveY;

	AxisPadLookX = NewObject<UBindAxis>(this, UBindAxis::StaticClass(), "PadLookX");
	AxisPadLookX->RegisterComponent();
	AxisPadLookX->Setup(this, EInputAxis::InputAxisPadLookX, "Gamepad_RightX", EControlType::ControlTypePad);
	AxisPadLookX->Clean = CommandAxisLookX;

	AxisPadLookY = NewObject<UBindAxis>(this, UBindAxis::StaticClass(), "PadLookY");
	AxisPadLookY->RegisterComponent();
	AxisPadLookY->Setup(this, EInputAxis::InputAxisPadLookY, "Gamepad_RightY", EControlType::ControlTypePad);
	AxisPadLookY->Clean = CommandAxisLookY;


	//Faux Axis Listeners to detect if the user switches from Keyboard to GamePad
	InputComponent->BindAxisKey(FKey("Gamepad_LeftX"), this, &APC::PadAxisDetector);
	InputComponent->BindAxisKey(FKey("Gamepad_LeftY"), this, &APC::PadAxisDetector);

	InputComponent->BindAxisKey(FKey("Gamepad_RightX"), this, &APC::PadAxisDetector);
	InputComponent->BindAxisKey(FKey("Gamepad_RightY"), this, &APC::PadAxisDetector);

	ControlMode = EControlType::ControlTypeMak;
	UpdateControlMode();
}

void APC::PadAxisDetector(float Power)
{
	if (Power != 0.0)
	{
		APC::AllowInputFromControl(EControlType::ControlTypePad);
	}
}

void APC::SetInputInterface(UObject* InterfaceInputObject)
{
	InputInterface = InterfaceInputObject;
}

void APC::ClearInputInterface()
{
	InputInterface = NULL;
}

bool APC::AllowInputFromControl(TEnumAsByte<EControlType> ControlType)
{
	if (ControlType == EControlType::ControlTypeAny || ControlType == ControlMode)
	{
		return true;
	}

	ControlMode = ControlType;
	UpdateControlMode();
	return false;
}

void APC::UpdateControlMode()
{

	if (ControlMode == EControlType::ControlTypeMak)
	{
		MakForward->Enable(true);
		MakSide->Enable(true);
		AxisMakMouseX->Enable(true);
		AxisMakMouseY->Enable(true);
		AxisPadMoveX->Enable(false);
		AxisPadMoveY->Enable(false);
		AxisPadLookX->Enable(false);
		AxisPadLookY->Enable(false);
	}
	else if (ControlMode == EControlType::ControlTypePad)
	{
		MakForward->Enable(false);
		MakSide->Enable(false);
		AxisMakMouseX->Enable(false);
		AxisMakMouseY->Enable(false);
		AxisPadMoveX->Enable(true);
		AxisPadMoveY->Enable(true);
		AxisPadLookX->Enable(true);
		AxisPadLookY->Enable(true);
	}
}

void APC::SendCommand(UCommand* Command)
{
	if (IsValid(InputInterface))
	{
		IInterfaceInput::Execute_Command(InputInterface, Command);
	}
}

void APC::SendCommandAxis(UCommandAxis* Command)
{
	if (IsValid(InputInterface))
	{
		IInterfaceInput::Execute_CommandAxis(InputInterface, Command);
	}
}

void APC::SendSpecial(TEnumAsByte<ECommandSpecialID> Command, bool bPressed)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void APC::Fuck()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void APC::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	MakForward->Trigger();
	MakSide->Trigger();

	if (bMouseActivated && bAllowMouseInteractive)
	{
		FHitResult HitResult;

		bool bHit = GetHitResultUnderCursor(COLLISION_INTERACTIVE, false, HitResult);

		if (bHit)
		{
			AActor* HitActor = HitResult.Actor.Get();

			if (HitActor != MouseHoveredActor)
			{
				//UiHud->Interest->CloseInterest();
				MouseHoveredActor = HitActor;

				if (HitActor->GetClass()->ImplementsInterface(UInterfaceInteractive::StaticClass()))
				{

					//IInterfaceInteractive::Execute_InteractiveHover(MouseHoveredActor, MouseHoveredActor);
					//UiHud->Interest->OpenInterest(IInterfaceInteractive::Execute_GetInterest(MouseHoveredActor));
					//ActiveInteractive->DoHover(EInteractiveTrigger::InteractiveTriggerPointer);
				}
				else
				{
					//UiHud->Interest->CloseInterest();
				}


			}
		}
		else 
		{
			MouseHoveredActor = NULL;
			//UiHud->Interest->CloseInterest();
		}

	}


}



void APC::SetupUi_Implementation()
{
	UiMouse = CreateWidget<UUiMouse>(this, MouseClass.Get());
	UiMouse->AddToViewport(999999); // Z-order, this just makes it render on the very top.
	DeactivateMouse();
	UiHud = CreateWidget<UUiHud>(this, UiHudSoftClass.Get());
	UiHud->AddToViewport(); // Z-order, this just makes it render on the very top.
}

void APC::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APC, PlayerIndex);
	DOREPLIFETIME(APC, UiHud);
}


void APC::Pilot_Implementation(APawn* InPawn)
{	

	if (InPawn->GetClass()->ImplementsInterface(UInterfacePilot::StaticClass()))
	{
		PilotedBase = InPawn;
		PilotedGoal = IInterfacePilot::Execute_GetPilotGoal(InPawn);
		Possess(PilotedGoal);		
		IInterfacePilot::Execute_Engage(InPawn,this);
	}
}



void APC::MatchCamera(UCameraComponent* InCamera)
{
	CM->ForceCameraTarget(InCamera);
}
/**
void APC::SetAvatar(AAvatar* InAvatar)
{
	Avatar = InAvatar; 

	Avatar->PlayerController = this;
	
}


AAvatar* APC::GetAvatar(UObject* WorldContext)
{
	return Cast<APC>(UGameplayStatics::GetPlayerController(WorldContext, 0))->Avatar;
}
*/



void APC::AuxModeStart()
{
	//UiHud->AuxModeStart();
	UiMouse->CenterMouse();
	ActivateMouse();
}

void APC::AuxModeEnd()
{
	//UiHud->AuxModeEnd();
	DeactivateMouse();
}



void APC::ActivateMouse()
{
	bMouseActivated = true;
	bShowMouseCursor = true;
	FInputModeUIOnly InputMode;
	SetInputMode(InputMode);
	UiMouse->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void APC::DeactivateMouse()
{
	bMouseActivated = false;
	bShowMouseCursor = false;
	SetInputMode(FInputModeGameOnly());
	UiMouse->SetVisibility(ESlateVisibility::Collapsed);
	ResetMouse();
}

void APC::ResetMouse()
{
	MouseHoveredActor = NULL;
}


void APC::OpenHud_Implementation(bool bAnimate)
{

}



FVector2D APC::GetMousePos()
{
	return UiMouse->MousePosition;
}





bool APC::DabbleCommand(const UCommand* Command)
{
	
	if (Command->Pressed)
	{
		switch (Command->ID) {
		case ECommandID::CommandTabLeft:
			TabSelectNext(true, ETabSelectionMode::TabSelectionModeAll);
			return true;
			break;
		case ECommandID::CommandTabRight:
			TabSelectNext(false, ETabSelectionMode::TabSelectionModeAll);
			return true;
			break;
		case ECommandID::CommandAccept:			
			if (InputParadigm == EInputParadigm::InputParadigmTabSelect)
			{
				IInterfaceInteractive::Execute_InteractiveAccept(TabSelected);
				return true;
			}
			break;
		case ECommandID::CommandCancel:

			if (InputParadigm == EInputParadigm::InputParadigmTabSelect)
			{
				ClearTabSelected();
				return false;
			}
			break;
		case ECommandID::CommandPartyUp:
			PartySelectNext(true);
			return true;
			break;
		case ECommandID::CommandPartyDown:
			PartySelectNext(false);
			return true;
			break;
		}
	}

	return false;
}

bool APC::DabbleCommandAxis(const UCommandAxis* CommandAxis)
{
	return false;
}




void APC::SetInputParadigm(EInputParadigm InInputParadigm)
{
	InputParadigm = InInputParadigm;
}

void APC::SetTabSelected(UObject* NewTabSelected)
{
	if (TabSelected != NewTabSelected)
	{
		if (TabSelected != NULL)
		{
			UiHud->Elect->ClearElect();
			IInterfaceInteractive::Execute_InteractiveUnselect(TabSelected);
		}

		TabSelected = NewTabSelected;
		IInterfaceInteractive::Execute_InteractiveSelect(TabSelected);
		UiHud->Elect->OpenElectWidget(IInterfaceInteractive::Execute_GetElectWidget(TabSelected));
	}


	SetInputParadigm(EInputParadigm::InputParadigmTabSelect);
}

void APC::ClearTabSelected()
{
	if (TabSelected != NULL)
	{
		IInterfaceInteractive::Execute_InteractiveUnselect(TabSelected);
		UiHud->Elect->ClearElect();
		IInterfaceInteractive::Execute_InteractiveUnselect(TabSelected);
	}

	TabSelected = NULL;
	SetInputParadigm(EInputParadigm::InputParadigmStandard);
}


void APC::TabSelectNext(bool bLeft, const ETabSelectionMode InMode)
{
	TArray<TEnumAsByte<EObjectTypeQuery>> Collisions;
	TArray<AActor*> IgnoreActors;
	Collisions.Add(EObjectTypeQuery::ObjectTypeQuery7);
	TArray<AActor*> List = UStatics::GetAllActorsOnScreenInRadius(PilotedGoal, PilotedGoal->GetActorLocation(), 1500.0f, Collisions, AActor::StaticClass(), IgnoreActors);

	int Num = List.Num();

	TArray<UObject*> AllowedList;

	for (int i = 0; i < Num; i++)
	{
		if (List[i]->GetClass()->ImplementsInterface(UInterfaceInteractive::StaticClass()))
		{
			//Check here if it's allowed individually by addition logic
			AllowedList.Add(List[i]);
		}
	}

	Num = AllowedList.Num();
	
	if (Num > 0)
	{
		if (Num == 1)
		{
			SetTabSelected(AllowedList[0]);
		}
		else if (TabSelected == NULL)
		{
			//Change to SelectNearest or Highest Priority;
			SetTabSelected(AllowedList[0]);
		}
		else
		{

			int Found = AllowedList.Find(TabSelected);
			
			if (Found == INDEX_NONE)
			{
				//Change to SelectNearest or Highest Priority;
				SetTabSelected(AllowedList[0]);
			}
			else
			{
				int Result;

				if (bLeft)
				{

					Result = Found - 1;
					if (Result < 0)
					{
						Result = Num - 1;
					}
				}
				else
				{
					Result = Found + 1;
					if (Result >= Num)
					{
						Result = 0;
					}
				}

				SetTabSelected(AllowedList[Result]);
			}
		}
	}
}


void APC::ConnectToParty()
{
	AGS::GetGS()->Party->ConnectToParty(this);
}

void APC::PartySelectNext(bool bReverse)
{
	UPartyMember* NextMember = PartyMember->GetNextAvailable(false);
	
	ClearTabSelected();

	if(NextMember != PartyMember)
	{
		NextMember->ConnectPlayer(this);
	}		
}