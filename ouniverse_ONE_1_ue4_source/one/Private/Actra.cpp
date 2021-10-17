// Fill out your copyright notice in the Description page of Project Settings.


#include "Actra.h"
#include "AGS.h"
#include "Body.h"
#include "Reg.h"
#include "Behavior.h"
#include "Equipable.h"
#include "EquipSlot.h"
#include "EquipSlotsEnum.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Input.h"
#include "Kismet/GameplayStatics.h"
#include "APC.h"
#include "Interactive.h"

bool FActraRow::Try(FActraRow*& Output, FName Key)
{
	FString ContextString;
	Output = AGS::GetGS()->ActraTable->FindRow<FActraRow>(Key, *ContextString, false);

	if (Output == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ActraHuman Not Found!"));
		return false;
	}

	return true;
}

// Sets default values
AActra::AActra()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Inventory = CreateOptionalDefaultSubobject<UInventory>("Inventory");

	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));


	// Don't rotate when the controller rotates. Let that just affect the camera.
	//bUseControllerRotationPitch = false;
	//bUseControllerRotationYaw = false;
	//bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;

	//Order here matter
	Wearables = CreateDefaultSubobject<UWearableRack>(TEXT("Wearable"));
}

void AActra::Load()
{

}

// Called when the game starts or when spawned
void AActra::BeginPlay()
{
	Super::BeginPlay();


}

void AActra::CreateAsNPC()
{
	FActraRow* Row;
	if (FActraRow::Try(Row, Key))
	{
		//FirstName = Row->FirstName;
		//LastName = Row->LastName;

		Body = NewObject<UBody>(this, Row->BodyClass.LoadSynchronous(), "Body");
		Body->RegisterComponent();
		Body->Setup(this);

		Body->FromRow(Row->BodyKey);
		Body->UpdatePoly();

		Behavior = NewObject<UBehavior>(this, AGS::GetGS()->Reg->BehaviorTest.Get(), "Behavior");
		Behavior->RegisterComponent();

	}
}

void AActra::CreateAsPartyMember(FName InKey)
{
	FActraRow* Row;
	if (FActraRow::Try(Row, InKey))
	{
		//FirstName = Row->FirstName;
		//LastName = Row->LastName;

		Body = NewObject<UBody>(this, Row->BodyClass.LoadSynchronous(), "Body");
		Body->RegisterComponent();
		Body->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		Body->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		Body->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));
		Body->Setup(this);


		Body->FromRow(Row->BodyKey);
		Body->UpdatePoly();

		Behavior = NewObject<UBehavior>(this, AGS::GetGS()->Reg->BehaviorTest.Get(), "Will");
		Behavior->RegisterComponent();

	}
}




void AActra::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Input->BindInputComponent(PlayerInputComponent);
	//Interactor->PlayerConnect();

	//Behavior->PlayerConnect();
}



// Called every frame
void AActra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AActra::Engage_Implementation(APC* InController)
{
	PC = InController;
	Behavior->Pilot();
}





void AActra::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}


void AActra::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}



UInteractor* AActra::AddInteractor()
{
	Interactor = NewObject<UInteractor>(this, UInteractor::StaticClass(), "Interactor");
	Interactor->RegisterComponent();
	Interactor->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	return Interactor;
}


APawn* AActra::GetPilotGoal_Implementation()
{
	return this;
}

UCameraComponent* AActra::GetPilotCamera_Implementation()
{
	return FollowCamera;
}