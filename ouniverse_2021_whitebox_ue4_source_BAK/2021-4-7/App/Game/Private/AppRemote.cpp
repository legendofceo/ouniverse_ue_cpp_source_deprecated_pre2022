// Fill out your copyright notice in the Description page of Project Settings.


#include "AppRemote.h"
#include "WorldRemote.h"
#include "AppController.h"
#include "AppPort.h"


namespace Remote
{
	AAppRemote* App = NULL;
}

AAppRemote::AAppRemote() : ARemote()
{
	UAppPort* AppPort = NULL;

	for (int i = 0; i < AAppMode::MaxPlayers; i++)
	{
		FString Name = "AppPort" + FString::FromInt(i);
		AppPort = CreateDefaultSubobject<UAppPort>(*Name);
		Ports.Add(AppPort);
	}
}

AAppRemote* AAppRemote::Get()
{
	return Remote::App;
}

void AAppRemote::BeginPlay()
{
	Super::BeginPlay();

#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

	Remote::App = this;

	MaxPlayersDisplay = AAppRemote::MaxPlayers;


	if (HasAuthority())
	{

		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.bNoFail = true;

		WorldRemote = GetWorld()->SpawnActor<AWorldRemote>(AWorldRemote::StaticClass(), Location, Rotation, SpawnInfo);
		WorldRemote->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}

	AAppController::GetAppController(this)->ClientBootTaskComplete(ClientBootTasksEnum::ClientBootTasksAppRemote);
	
}


void AAppRemote::ReceivePlayer(AAppController* AppController)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "I HAVE HAPPENED");

	AppController->AppControllerIndex = AppControllers.Num();
	AppControllers.Add(AppController);

	if (AppController->AppControllerIndex == 0)
	{
		BaseController = AppController;
	}

	for (UAppPort* Port : Ports)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "X");
		if (Port->IsEmpty())
		{
			Port->Plug(AppController);
			break;
		}
		
	}
}


void AAppRemote::AddLocalPlayer()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, "Adding Local Player");
	AAppController* NewController = Cast<AAppController>(UGameplayStatics::CreatePlayer(this, 1, true));
	AppControllers.Add(NewController);

}