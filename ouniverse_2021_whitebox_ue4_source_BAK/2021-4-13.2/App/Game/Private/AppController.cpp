// Fill out your copyright notice in the Description page of Project Settings.


#include "AppController.h"
#include "AppBae.h"
#include "AppMode.h"
#include "Cam.h"
#include "Input.h"
#include "Keynet.h"
#include "InputPoly.h"
#include "Kismet/GameplayStatics.h"
#include "MenuMain.h"
#include "Framework/Commands/InputChord.h"

#include "LoadScreenUi.h"

#include "SoftServe.h"


#include "AppRemote.h"
#include "MythRemote.h"
#include "SpectatorRemote.h"
#include "PartyRemote.h"
#include "CompanionRemote.h"

AAppController::AAppController()
{
	bReplicates = true;
	bAutoManageActiveCameraTarget = false;

	UserName = "Default";
	UserSymbol = 0;

	//MythRemote = CreateDefaultSubobject(TEXT("MythRemote"));


	AppRemote = CreateDefaultSubobject<UAppRemote>(TEXT("AppRemote"));
	MythRemote = CreateDefaultSubobject<UMythRemote>(TEXT("MythRemote"));
	SpectatorRemote = CreateDefaultSubobject<USpectatorRemote>(TEXT("SpectatorRemote"));
	PartyRemote = CreateDefaultSubobject<UPartyRemote>(TEXT("PartyRemote"));
	CompanionRemote = CreateDefaultSubobject<UCompanionRemote>(TEXT("CompanionRemote"));

}

AAppController* AAppController::GetAppController(const UObject* WorldContextObject)
{
	return Cast<AAppController>(UGameplayStatics::GetPlayerController(WorldContextObject->GetWorld(), 0));
}

void AAppController::BeginPlay()
{
	Super::BeginPlay();

	if (SpectatorUiClass == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A misc class was not properly set in AppController");
		return;
	}


	Bae = GetPlayerState<AAppBae>();

	PlayerCameraManager->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AppControllerIndex = GetInputIndex();





	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SoftServe->Add(LoadScreenUiClass);

	if (SoftServe->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ServeServe has Null in AppController");
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &AAppController::BeginPlay_SS);
	SoftServe->Stream();
}

void AAppController::BeginPlay_SS(USoftServe* SS)
{
	if (IsLocalPlayerController())
	{
		LoadScreenUi = CreateWidget<ULoadScreenUi>(this, LoadScreenUiClass.Get());
	}

	SoftServe = NULL;
	
	if (HasAuthority())
	{
		AAppMode::Get()->ReceiveNewPlayer(this);
	}
}

void AAppController::InitAfterServerSystemsReady()
{
	MythRemote->Init(this);
}

void AAppController::Host()
{
	bHost = true;
}

bool AAppController::IsHost()
{
	return bHost;
}

void AAppController::SetupInputComponent()
{
	Super::SetupInputComponent();

	BTs.Init(NULL, InputEnumBT::InputEnumBT_MAX);
	
	BTs.Add(UInputButton::Create(this, &EKeys::I, InputEnumBT::InputEnumBT_I));

	BTs[InputEnumBT::InputEnumBT_Gamepad_LeftTrigger] = UInputButton::Create(this, &EKeys::Gamepad_LeftTrigger, InputEnumBT::InputEnumBT_Gamepad_LeftTrigger);
	BTs[InputEnumBT::InputEnumBT_Gamepad_RightTrigger] = UInputButton::Create(this, &EKeys::Gamepad_RightTrigger, InputEnumBT::InputEnumBT_Gamepad_RightTrigger);

	BTs[InputEnumBT::InputEnumBT_Gamepad_FaceButton_Bottom] = UInputButton::Create(this, &EKeys::Gamepad_FaceButton_Bottom, InputEnumBT::InputEnumBT_Gamepad_FaceButton_Bottom);
	BTs[InputEnumBT::InputEnumBT_Gamepad_FaceButton_Right] = UInputButton::Create(this, &EKeys::Gamepad_FaceButton_Right, InputEnumBT::InputEnumBT_Gamepad_FaceButton_Right);



	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, EKeys::Gamepad_FaceButton_Bottom.ToString());

	TEnumAsByte<UInputButton> Byte = TEnumAsByte<UInputButton>(0);

	DefaultKeynet(KeynetsEnum::KeynetsEnum_Menu);
	DefaultKeynet(KeynetsEnum::KeynetsEnum_World);
}

void AAppController::DefaultKeynet(TEnumAsByte<KeynetsEnum> Keynet)
{
	switch (Keynet) {
	case KeynetsEnum::KeynetsEnum_Menu:
			KeynetMenu = UKeynet::Create();
			KeynetMenu->AddKeymap(FKeymap(KeynetMenuEnum::KeynetMenuEnum_Accept, BTs[InputEnumBT::InputEnumBT_Gamepad_FaceButton_Bottom]));
			KeynetMenu->AddKeymap(FKeymap(KeynetMenuEnum::KeynetMenuEnum_Cancel, BTs[InputEnumBT::InputEnumBT_Gamepad_FaceButton_Right]));
			KeynetMenu->AddKeymap(FKeymap(KeynetMenuEnum::KeynetMenuEnum_TabLeft, BTs[InputEnumBT::InputEnumBT_Gamepad_LeftTrigger]));
			KeynetMenu->AddKeymap(FKeymap(KeynetMenuEnum::KeynetMenuEnum_TabRight, BTs[InputEnumBT::InputEnumBT_Gamepad_RightTrigger]));
			KeynetMenu->Rebuild();
		break;
	case KeynetsEnum::KeynetsEnum_World:
			KeynetWorld = UKeynet::Create();
			KeynetWorld->AddKeymap(FKeymap(KeynetWorldEnum::KeynetWorldEnum_Inventory, BTs[InputEnumBT::InputEnumBT_I]));
			KeynetWorld->Rebuild();
		break;
	}
}

void AAppController::SendInputButtonEvent(UInputButton* InputButton)
{

	UDataBT* NewInputButtonEvent = NewObject<UDataBT>();
	NewInputButtonEvent->Fill(InputButton);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "KeyHappened");

	//if (IsValid(ActivePro))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "KeySent");
	//	WorldPro->BT(NewInputButtonEvent);
	//}
	
}

void AAppController::ConvertToKeynetBP(TEnumAsByte<KeynetsEnum> Keynet, uint8 InputCode, uint8& ConvertedInputCode, ESuccess& Execs)
{
	Execs = ESuccess::Fail;
	ConvertedInputCode = 0;
	UKeynet* QueryKeynet = NULL;	

	switch (Keynet) {
	case KeynetsEnum::KeynetsEnum_Menu:
		QueryKeynet = KeynetMenu;
		break;
	case KeynetsEnum::KeynetsEnum_World:
		QueryKeynet = KeynetWorld;
		break;
	}

	if(QueryKeynet!=NULL&& QueryKeynet->TryBind(ConvertedInputCode, InputCode))
	{
		Execs = ESuccess::Success;
	}
}

TEnumAsByte<KeynetWorldEnum> AAppController::KeynetConvertWorld(uint8 Byte)
{
	return KeynetWorldEnum::KeynetWorldEnum_Inventory;
}


bool AAppController::OpenMainMenu(FMenuMainInitializer Initializer)
{
	MenuMain = AMenuMainRootWin::OpenMenu(Initializer,MenuMainClass,this);
	return true;
}

bool AAppController::OpenConsole()
{
	return true;
}

bool AAppController::PrintScreen()
{
	return true;
}















void AAppController::StartLoadScreen_Implementation()
{
	if (LoadScreenUi)
	{
		LoadScreenUi->AddToViewport(9999);
	}
}

/** WithValidation
bool AAppController::StartLoadScreen_Validate()
{
	return true;
}
*/

void AAppController::EndLoadScreen()
{

}


void AAppController::Engage_SER_Implementation()
{

	switch (AAppMode::Get()->Pro) {
	case EAppPros::None:

		break;
	case EAppPros::Outer:

		break;
	case EAppPros::Myth:
		MythRemote->Engage();
		DebugTextBP("MythRemote Engaged");
		break;
	}

}