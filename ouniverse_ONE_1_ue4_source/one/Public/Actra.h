// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "InterfacePilot.h"
#include "InterfaceInteractive.h"
#include "Actra.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerConnect);

class UWearableRack;
class UBody;
class UBehavior;

class UEquipSlot;
class UInventory;

class UWearableNudeBust;
class UWearableNudeLegs;
class UWearableNudeHands;
class UWearableNudeFeet;


class UInput;
class UInputKey;
class UInputAxis;

class APC;
class UInteractor;

USTRUCT()
struct ONE_API FActraRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText FirstName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText LastName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UBody> BodyClass;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	FName BodyKey;


	static bool Try(FActraRow*& Output, FName Key);
};

USTRUCT()
struct FScreenTabStorageStruct
{
	GENERATED_BODY()


	UPROPERTY()
	float X;
	
	UPROPERTY()
	AActor* Actor;

public:

	FScreenTabStorageStruct() {};
	FScreenTabStorageStruct(float InX, AActor* InActor)
	{
		X = InX;
		Actor = InActor;
	}
};

struct FSortByScreenX
{
	FSortByScreenX() {};

	bool operator()(const FScreenTabStorageStruct A, const FScreenTabStorageStruct B) const
	{
		return A.X > B.X;
	}
};

/**
cool example:
struct FSortByDistance
{
	FSortByDistance(const FVector& InSourceLocationg)
		: SourceLocation(InSourceLocation)
	{

	}


	FVector SourceLocation;

	bool operator()(const AActor* A, const AActor* B) const
	{
		float DistanceA = FVector::DistSquared(SourceLocation, A.GetActorLocation());
		float DistanceB = FVector::DistSquared(SourceLocation, B.GetActorLocation());

		return DistanceA > DistanceB;
	}
};
*/

UCLASS(Blueprintable)
class ONE_API AActra : public ACharacter, public IInterfacePilot, public IInterfaceInteractive
{
	GENERATED_BODY()



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	AActra();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CreateAsNPC();

	void CreateAsPartyMember(FName Key);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC;

	UFUNCTION()
	UInteractor* AddInteractor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInteractor* Interactor;

	UPROPERTY(category = Actra, VisibleAnywhere, BlueprintReadOnly)
	UInventory* Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBehavior* Behavior;

	UPROPERTY(category = Actra, EditAnywhere, BlueprintReadOnly)
	FName Key;

	UFUNCTION()
	void Load();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBody* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWearableRack* Wearables;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerConnect OnPlayerConnect;

	//Interface - Controllable
	void Engage_Implementation(APC* InController) override;







	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);





	APawn* GetPilotGoal_Implementation();
	UCameraComponent* GetPilotCamera_Implementation();

};