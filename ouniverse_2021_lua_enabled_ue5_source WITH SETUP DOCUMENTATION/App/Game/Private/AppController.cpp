// Fill out your copyright notice in the Description page of Project Settings.


#include "AppController.h"
#include "AppInstance.h"
#include "AppCam.h"
#include "Log.h"
#include "InputRaw.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/UserInterfaceSettings.h"
#include "AppMode.h"
#include "MouseUi.h"
#include "NotificationUi.h"

const FName AAppController::SYS = "App";

namespace Global
{
	AAppController* AppController = nullptr;
}

AAppController* AAppController::Get()
{
	return Global::AppController;
}

AAppController::AAppController()
{
	bReplicates = true;
	bAutoManageActiveCameraTarget = false;
	PlayerCameraManagerClass = AAppCam::StaticClass();

}

void AAppController::GetAppController(AAppController*& AppController)
{
	//Cast<AAppController>(UGameplayStatics::GetPlayerController(WorldContextObject->GetWorld(), 0));
	AppController = Global::AppController;

}

void AAppController::BeginPlay()
{
	Super::BeginPlay();
	Global::AppController = this;

	Cam = Cast<AAppCam>(PlayerCameraManager);

	PlayerCameraManager->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AppControllerIndex = GetInputIndex();


	if (!NotificationWinClass)
	{
		LOG.S(SYS).T(TCRIT).W("NotificationWinClass was nullptr").DebugM();
		return;
	}

	NotificationWin = CreateWidget<UNotificationWin>(this, NotificationWinClass.Get());
	NotificationWin->AddToViewport(9990);

	if (NotificationPeripheralModeMouse.IsNull() || NotificationPeripheralModeGamepad.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("Notification soft wall nullptr").DebugM();
		return;
	}

	SetPeripheralMode(EPeripheralMode::Mouse, true);

	if (MouseUiClass == nullptr)
	{
		LOG.S(SYS).T(TCRIT).W("MouseUiClass is null").DebugM();
		return;
	}

	MouseUi = CreateWidget<UMouseUi>(this, MouseUiClass.Get());
	MouseUi->Init();
	MouseUi->AddToViewport(9991);
	EndMouseMode();

}

void AAppController::Tick(float DeltaSeconds)
{
	FVector2D viewportSize;
	GEngine->GameViewport->GetViewportSize(viewportSize);
	int32 X = FGenericPlatformMath::FloorToInt(viewportSize.X);
	int32 Y = FGenericPlatformMath::FloorToInt(viewportSize.Y);
	DpiScale = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass())->GetDPIScaleBasedOnSize(FIntPoint(X, Y));

	float MouseX;
	float MouseY;
	GetMousePosition(MouseX, MouseY);

	MouseDeltaX = MouseX - MouseLastX;
	MouseDeltaY = MouseY - MouseLastY;

	MouseUi->Update(MouseX/DpiScale, MouseY/DpiScale);

	MouseLastX = MouseX;
	MouseLastY = MouseY;
}

void AAppController::StartMouseMode(FName Context)
{

	if (bMouseMode)
	{
		LOG.S(SYS).T(TCRIT).W("MouseMode activated when it was already activated").DebugM();
	}
	bMouseMode = true;
	MouseModeContext = Context;
	MouseUi->Show();
}

void AAppController::EndMouseMode()
{
	bMouseMode = false;
	MouseModeContext = FName();
	MouseUi->Hide();
}

bool AAppController::IsPeripheralModeMouse()
{
	if (PeripheralMode == EPeripheralMode::Mouse)
	{
		return true;
	}

	return false;
}

EPeripheralMode AAppController::GetPeripheralMode()
{
	return PeripheralMode;
}


void AAppController::SetPeripheralMode(EPeripheralMode InPeripheralMode, bool bSilent)
{
	PeripheralMode = InPeripheralMode;

	if (!bSilent)
	{
		switch (PeripheralMode) {
		case EPeripheralMode::Mouse:
			if (bMouseMode)
			{
				MouseUi->Show();
			}
			NotificationWin->AddNotification(NotificationPeripheralModeMouse);
			break;
		case EPeripheralMode::Gamepad:
			MouseUi->Hide();
			NotificationWin->AddNotification(NotificationPeripheralModeGamepad);
			break;
		}
	}

	for (FListenerPeripheralMode& Listener : SubscriptionsPeripheralMode)
	{
		Listener.Delegate.Execute(PeripheralMode);
	}

}


void AAppController::SetupInputComponent()
{
	Super::SetupInputComponent();

	BTs.Init(nullptr, uint8(InputCodeBT::MAX));

	UBT::Create(this, &EKeys::BackSpace, InputCodeBT::BackSpace, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Tab, InputCodeBT::Tab, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Enter, InputCodeBT::Enter, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Pause, InputCodeBT::Pause, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::CapsLock, InputCodeBT::CapsLock, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Escape, InputCodeBT::Escape, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::SpaceBar, InputCodeBT::SpaceBar, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::PageUp, InputCodeBT::PageUp, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::PageDown, InputCodeBT::PageDown, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::End, InputCodeBT::End, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Home, InputCodeBT::Home, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::Up, InputCodeBT::Up, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Down, InputCodeBT::Down, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Left, InputCodeBT::Left, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Right, InputCodeBT::Right, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::Insert, InputCodeBT::Insert, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Delete, InputCodeBT::Delete, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::Zero, InputCodeBT::Zero, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::One, InputCodeBT::One, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Two, InputCodeBT::Two, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Three, InputCodeBT::Three, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Four, InputCodeBT::Four, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Five, InputCodeBT::Five, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Six, InputCodeBT::Six, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Seven, InputCodeBT::Seven, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Eight, InputCodeBT::Eight, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Nine, InputCodeBT::Nine, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::A, InputCodeBT::A, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::B, InputCodeBT::B, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::C, InputCodeBT::C, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::D, InputCodeBT::D, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::E, InputCodeBT::E, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F, InputCodeBT::F, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::G, InputCodeBT::G, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::H, InputCodeBT::H, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::I, InputCodeBT::I, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::J, InputCodeBT::J, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::K, InputCodeBT::K, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::L, InputCodeBT::L, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::M, InputCodeBT::M, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::N, InputCodeBT::N, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::O, InputCodeBT::O, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::P, InputCodeBT::P, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Q, InputCodeBT::Q, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::R, InputCodeBT::R, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::S, InputCodeBT::S, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::T, InputCodeBT::T, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::U, InputCodeBT::U, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::V, InputCodeBT::V, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::W, InputCodeBT::W, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::X, InputCodeBT::X, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Y, InputCodeBT::Y, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Z, InputCodeBT::Z, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::NumPadZero, InputCodeBT::NumPadZero, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadOne, InputCodeBT::NumPadOne, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadTwo, InputCodeBT::NumPadTwo, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadThree, InputCodeBT::NumPadThree, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadFour, InputCodeBT::NumPadFour, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadFive, InputCodeBT::NumPadFive, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadSix, InputCodeBT::NumPadSix, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadSeven, InputCodeBT::NumPadSeven, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadEight, InputCodeBT::NumPadEight, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::NumPadNine, InputCodeBT::NumPadNine, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::Multiply, InputCodeBT::Multiply, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Add, InputCodeBT::Add, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Subtract, InputCodeBT::Subtract, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Decimal, InputCodeBT::Decimal, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Divide, InputCodeBT::Divide, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::F1, InputCodeBT::F1, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F2, InputCodeBT::F2, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F3, InputCodeBT::F3, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F4, InputCodeBT::F4, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F5, InputCodeBT::F5, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F6, InputCodeBT::F6, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F7, InputCodeBT::F7, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F8, InputCodeBT::F8, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F9, InputCodeBT::F9, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F10, InputCodeBT::F10, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F11, InputCodeBT::F11, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::F12, InputCodeBT::F12, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::NumLock, InputCodeBT::NumLock, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::ScrollLock, InputCodeBT::ScrollLock, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::LeftShift, InputCodeBT::LeftShift, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::RightShift, InputCodeBT::RightShift, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::LeftControl, InputCodeBT::LeftControl, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::RightControl, InputCodeBT::RightControl, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::LeftAlt, InputCodeBT::LeftAlt, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::RightAlt, InputCodeBT::RightAlt, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::LeftCommand, InputCodeBT::LeftCommand, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::RightCommand, InputCodeBT::RightCommand, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::Semicolon, InputCodeBT::Semicolon, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Equals, InputCodeBT::Equals, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Comma, InputCodeBT::Comma, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Underscore, InputCodeBT::Underscore, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Hyphen, InputCodeBT::Hyphen, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Period, InputCodeBT::Period, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Slash, InputCodeBT::Slash, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Tilde, InputCodeBT::Tilde, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::LeftBracket, InputCodeBT::LeftBracket, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Backslash, InputCodeBT::Backslash, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::RightBracket, InputCodeBT::RightBracket, InputDevice::Keyboard);
	UBT::Create(this, &EKeys::Apostrophe, InputCodeBT::Apostrophe, InputDevice::Keyboard);

	UBT::Create(this, &EKeys::LeftMouseButton, InputCodeBT::LeftMouseButton, InputDevice::Mouse);
	UBT::Create(this, &EKeys::RightMouseButton, InputCodeBT::RightMouseButton, InputDevice::Mouse);
	UBT::Create(this, &EKeys::MiddleMouseButton, InputCodeBT::MiddleMouseButton, InputDevice::Mouse);
	UBT::Create(this, &EKeys::ThumbMouseButton, InputCodeBT::ThumbMouseButton, InputDevice::Mouse);
	UBT::Create(this, &EKeys::ThumbMouseButton2, InputCodeBT::ThumbMouseButton2, InputDevice::Mouse);

	UBT::Create(this, &EKeys::Gamepad_FaceButton_Top, InputCodeBT::Gamepad_FaceButton_Top, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_FaceButton_Bottom, InputCodeBT::Gamepad_FaceButton_Bottom, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_FaceButton_Left, InputCodeBT::Gamepad_FaceButton_Left, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_FaceButton_Right, InputCodeBT::Gamepad_FaceButton_Right, InputDevice::Gamepad);

	UBT::Create(this, &EKeys::Gamepad_Special_Left, InputCodeBT::Gamepad_Special_Left, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_Special_Right, InputCodeBT::Gamepad_Special_Right, InputDevice::Gamepad);


	UBT::Create(this, &EKeys::Gamepad_LeftShoulder, InputCodeBT::Gamepad_LeftShoulder, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightShoulder, InputCodeBT::Gamepad_RightShoulder, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_LeftTrigger, InputCodeBT::Gamepad_LeftTrigger, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightTrigger, InputCodeBT::Gamepad_RightTrigger, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_LeftThumbstick, InputCodeBT::Gamepad_LeftThumbstick, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightThumbstick, InputCodeBT::Gamepad_RightThumbstick, InputDevice::Gamepad);

	UBT::Create(this, &EKeys::Gamepad_DPad_Up, InputCodeBT::Gamepad_DPad_Up, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_DPad_Down, InputCodeBT::Gamepad_DPad_Down, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_DPad_Left, InputCodeBT::Gamepad_DPad_Left, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_DPad_Right, InputCodeBT::Gamepad_DPad_Right, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_LeftStick_Up, InputCodeBT::Gamepad_LeftStick_Up, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_LeftStick_Down, InputCodeBT::Gamepad_LeftStick_Down, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_LeftStick_Left, InputCodeBT::Gamepad_LeftStick_Left, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_LeftStick_Right, InputCodeBT::Gamepad_LeftStick_Right, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightStick_Up, InputCodeBT::Gamepad_RightStick_Up, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightStick_Down, InputCodeBT::Gamepad_RightStick_Down, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightStick_Left, InputCodeBT::Gamepad_RightStick_Left, InputDevice::Gamepad);
	UBT::Create(this, &EKeys::Gamepad_RightStick_Right, InputCodeBT::Gamepad_RightStick_Right, InputDevice::Gamepad);

	AXs.Init(nullptr, uint8(InputCodeAX::MAX));
	UAX::Create(this, &EKeys::MouseX, InputCodeAX::MouseX, InputDevice::Mouse);
	UAX::Create(this, &EKeys::MouseY, InputCodeAX::MouseY, InputDevice::Mouse);

	UAX::Create(this, &EKeys::Gamepad_LeftX, InputCodeAX::Gamepad_LeftX, InputDevice::Gamepad);
	UAX::Create(this, &EKeys::Gamepad_LeftY, InputCodeAX::Gamepad_LeftY, InputDevice::Gamepad);

	UAX::Create(this, &EKeys::Gamepad_RightX, InputCodeAX::Gamepad_RightX, InputDevice::Gamepad);
	UAX::Create(this, &EKeys::Gamepad_RightY, InputCodeAX::Gamepad_RightY, InputDevice::Gamepad);

	SetDefaultCommands();
}

void AAppController::SetDefaultCommands()
{
	BindMapMenu.Init(CommandMenu::None,int(InputCodeBT::MAX));
	BindMapMenu[uint8(InputCodeBT::Gamepad_DPad_Up)] = CommandMenu::Up;
	BindMapMenu[uint8(InputCodeBT::Gamepad_DPad_Down)] = CommandMenu::Down;
	BindMapMenu[uint8(InputCodeBT::Gamepad_DPad_Left)] = CommandMenu::Left;
	BindMapMenu[uint8(InputCodeBT::Gamepad_DPad_Right)] = CommandMenu::Right;
	BindMapMenu[uint8(InputCodeBT::Gamepad_FaceButton_Bottom)] = CommandMenu::Accept;
	BindMapMenu[uint8(InputCodeBT::Gamepad_FaceButton_Right)] = CommandMenu::Cancel;
}

UBT* AAppController::GetBT(uint8 Byte)
{
	return BTs[Byte];
}

void AAppController::BT(UBT* BT)
{
	/**
	if (BT->InputCode == InputCodeBT::Home && !BT->IsPressed())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "PRINT LOG");
		ULogger::Get()->OutputTextFile(UApp::Get()->AppLogFilePath, "SubInitComplete() (AppMode)");

	}
	*/

	if (BT->IsClick())
	{
		InputDevice Device = BT->GetDevice();

		if (Device == InputDevice::Mouse && PeripheralMode != EPeripheralMode::Mouse)
		{
			SetPeripheralMode(EPeripheralMode::Mouse, false);
			return;
		}
		else if (Device == InputDevice::Gamepad && PeripheralMode != EPeripheralMode::Gamepad)
		{
			SetPeripheralMode(EPeripheralMode::Gamepad, false);
			return;
		}
	}

	OnBT.Broadcast(BT);

	for (FListenerBT& Listener : SubscriptionsBT)
	{
		Listener.Delegate.Execute(BT);
	}

	//InputMap->AnyKey->Execute(BT);
}

void AAppController::AX(UAX* AX)
{
	OnAX.Broadcast(AX);
	for (FListenerAX& Listener : SubscriptionsAX)
	{
		Listener.Delegate.Execute(AX);
	}
}


void AAppController::SubscribeBT(FName Context, UObject* Subscriber, const FDelDynamicBT& Event)
{
	FListenerBT Listener = FListenerBT();
	Listener.Context = Context;
	Listener.Subscriber = Subscriber;
	Listener.Delegate = Event;
	SubscriptionsBT.Add(Listener);
}

void AAppController::SubscribeAX(FName Context, UObject* Subscriber, const FDelDynamicAX& Event)
{
	FListenerAX Listener = FListenerAX();
	Listener.Context = Context;
	Listener.Subscriber = Subscriber;
	Listener.Delegate = Event;
	SubscriptionsAX.Add(Listener);
}

void AAppController::SubscribePeripheralMode(FName Context, UObject* Subscriber, const FDelDynamicPeripheralMode& Event)
{
	FListenerPeripheralMode Listener = FListenerPeripheralMode();
	Listener.Context = Context;
	Listener.Subscriber = Subscriber;
	Listener.Delegate = Event;
	SubscriptionsPeripheralMode.Add(Listener);
}

void AAppController::UnsubscribeBT(UObject* Subscriber)
{
	int L = SubscriptionsBT.Num();

	for (int i = L - 1; i >= 0; i--)
	{
		if (SubscriptionsBT[i].Subscriber == Subscriber)
		{
			SubscriptionsBT.RemoveAt(i);
		}
	}
}

void AAppController::UnsubscribeAX(UObject* Subscriber)
{
	int L = SubscriptionsAX.Num();

	for (int i = L - 1; i >= 0; i--)
	{
		if (SubscriptionsAX[i].Subscriber == Subscriber)
		{
			SubscriptionsAX.RemoveAt(i);
		}
	}
}

void AAppController::UnsubscribePeripheralMode(UObject* Subscriber)
{
	int L = SubscriptionsPeripheralMode.Num();

	for (int i = L - 1; i >= 0; i--)
	{
		if (SubscriptionsPeripheralMode[i].Subscriber == Subscriber)
		{
			SubscriptionsPeripheralMode.RemoveAt(i);
		}
	}
}

void AAppController::Pilot(APawn* InPawn)
{
	Possess(InPawn);
	PossessedPawn = InPawn;
}

void AAppController::ForceCam(UCameraComponent* CamTarget)
{
	Cam->ForceCameraTarget(CamTarget);
}


CommandMenu AAppController::GetCommand(UBT* BT)
{
	return BindMapMenu[BT->GetInputByte()];
}

void AAppController::GetCommandMenu(UBT* BT, CommandMenu& Command)
{
	Command = GetCommand(BT);
}