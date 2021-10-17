// Fill out your copyright notice in the Description page of Project Settings.


#include "AppController.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "AppMode.h"
#include "Cam.h"
#include "Input.h"
#include "Keynet.h"
#include "InputPoly.h"
#include "Kismet/GameplayStatics.h"
#include "MenuMain.h"
#include "Framework/Commands/InputChord.h"



#include "AppRemote.h"


#include "LoadScreenUi.h"

#include "SoftServe.h"


AAppController::AAppController()
{
	bReplicates = true;
	bAutoManageActiveCameraTarget = false;

	UserName = "Default";
	UserSymbol = 0;

	//WorldRemote = CreateDefaultSubobject(TEXT("WorldRemote"));

}

AAppController* AAppController::GetAppController(const UObject* WorldContextObject)
{
	return Cast<AAppController>(UGameplayStatics::GetPlayerController(WorldContextObject->GetWorld(), 0));
}

void AAppController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraManager->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AppControllerIndex = GetInputIndex();



	int L = ClientBootTasksEnum::ClientBootTasksMAX;
	for (int i = 0; i < L; i++)
	{
		ClientBootTasks.Add(TEnumAsByte<ClientBootTasksEnum>(i));
	}




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

void AAppController::SetRemoteMode(TEnumAsByte<ERemoteModes> InRemoteMode)
{
	switch (InRemoteMode) {
	case ERemoteModes::ERemoteModesNone:
		//ActiveRemote = NULL;
		break;
	case ERemoteModes::ERemoteModesWorld:
		//ActiveRemote = WorldRemote;
		//WorldRemote->Start();
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

void AAppController::ConvertToKeynetBP(TEnumAsByte<KeynetsEnum> Keynet, uint8 InputCode, uint8& ConvertedInputCode, ESuccessExecs& Execs)
{
	Execs = ESuccessExecs::Fail;
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
		Execs = ESuccessExecs::Success;
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













void AAppController::ClientBootTaskComplete(uint8 BootTask)
{

	ClientBootTasks.Remove(TEnumAsByte<ClientBootTasksEnum>(BootTask));

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "CheckIN: "+FString::FromInt(BootTask));

	if (ClientBootTasks.Num() == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "AAppControlller::Boot Complete");

		//AAppMode::GetAppMode(this)->AppRemote->ReceivePlayer(this);
		//TestText();
		SystemBooted();
	}
	

}


void AAppController::SystemBooted_Implementation()
{

	TestText();

}