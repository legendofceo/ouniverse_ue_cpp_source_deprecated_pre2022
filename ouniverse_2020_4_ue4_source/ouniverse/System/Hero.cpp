// Fill out your copyright notice in the Description page of Project Settings.



#include "Hero.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include "Components/SkeletalMeshComponent.h"

AHero::AHero()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);


	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;


	//ConstructObject<USphereComponent>(USphereComponent::StaticClass, this, TEXT("MySphereComponent"));

	//Skeleton_ = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("My Skeletal Mesh Component"));
	//Skeleton_->SetupAttachment(RootComponent);
	//Skeleton_->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	TSoftObjectPtr<USkeletalMesh> Mesh_SP = TSoftObjectPtr<USkeletalMesh>(FSoftObjectPath("/Game/study/sketchup/humanfemale_torso.humanfemale_torso"));
	USkeletalMesh* TestMesh = Mesh_SP.LoadSynchronous();
	GetMesh()->SetSkeletalMesh(TestMesh);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));

	OrbitBoom_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("OrbitBoom"));
	OrbitBoom_->SetupAttachment(RootComponent);
	CamZoomGoal = 750.f;
	OrbitBoom_->TargetArmLength = CamZoomGoal;

	OrbitBoom_->SocketOffset = FVector(0.f, 0.f, 0.f);
	OrbitBoom_->SetRelativeLocation(FVector(0.f, 0.f, 70.f));
	OrbitBoom_->SetRelativeRotation(FRotator(-10.f, 0.f, 0.f));
	OrbitBoom_->bEnableCameraLag = true;
	OrbitBoom_->CameraLagSpeed = 3.0f;
	OrbitBoom_->bUsePawnControlRotation = true;

	OrbitCam_ = CreateDefaultSubobject<UCameraComponent>(TEXT("OrbitCam"));
	OrbitCam_->SetupAttachment(OrbitBoom_, USpringArmComponent::SocketName);
	OrbitCam_->bUsePawnControlRotation = false;
}

void AHero::BeginPlay()
{
	Super::BeginPlay();
}

void AHero::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void AHero::MoveX(float Value)
{
	if (Controller != NULL)
	{

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AHero::MoveY(float Value)
{
	if (Controller != NULL)
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

void AHero::TurnY(float Value)
{
	AddControllerYawInput(Value);
}

void AHero::LookX(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds() * -1);
}


void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // Call parent class tick function  
}

void AHero::Zoom(float AxisValue)
{
	float Result;
	Result = AxisValue * -50;
	Result += CamZoomGoal;

	CamZoomGoal = FMath::Clamp(Result, 200.0f, 1000.0f);

	OrbitBoom_->TargetArmLength = FMath::FInterpTo(OrbitBoom_->TargetArmLength, CamZoomGoal, GetWorld()->GetDeltaSeconds(), 10.0f);

}