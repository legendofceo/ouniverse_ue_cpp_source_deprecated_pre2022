// Fill out your copyright notice in the Description page of Project Settings.


#include "Body.h"
#include "Actra.h"
#include "AGS.h"
#include "EquipSlot.h"
#include "Equipable.h"
#include "EquipSlotsEnum.h"


bool FBodyHumanRow::Try(FBodyHumanRow*& Output, FName Key)
{
	FString ContextString;
	Output = AGS::GetGS()->BodyHumanTable->FindRow<FBodyHumanRow>(Key, *ContextString, false);

	if (Output == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ActraBody Not Found!"));
		return false;
	}

	return true;
}


// Sets default values for this component's properties
UBody::UBody()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UBody::Setup(AActra* InActra)
{
	Actra = InActra;
}

// Called when the game starts
void UBody::BeginPlay()
{
	Super::BeginPlay();

	// ...
}




UBodyHuman::UBodyHuman()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UBodyHuman::BeginPlay()
{
	Super::BeginPlay();
}

void UBodyHuman::FromRow(FName Key)
{

	
	SlotNudeBust = NewObject<UEquipSlot>();
	SlotNudeBust->Setup(this, EEquipSlots::EquipSlotsNudeBust);
	SlotNudeLegs = NewObject<UEquipSlot>();
	SlotNudeLegs->Setup(this, EEquipSlots::EquipSlotsNudeLegs);
	SlotNudeHands = NewObject<UEquipSlot>();
	SlotNudeHands->Setup(this, EEquipSlots::EquipSlotsNudeHands);
	SlotNudeFeet = NewObject<UEquipSlot>();
	SlotNudeFeet->Setup(this, EEquipSlots::EquipSlotsNudeFeet);


	FBodyHumanRow* Row;
	if (FBodyHumanRow::Try(Row, Key))
	{
		UWearableNudeBust* Bust = NewObject<UWearableNudeBust>(this, Row->NudeBust.LoadSynchronous(), "WearableNudeBust");
		UWearableNudeLegs* Legs = NewObject<UWearableNudeLegs>(this, Row->NudeLegs.LoadSynchronous(), "WearableNudeLegs");
		UWearableNudeHands* Hands = NewObject<UWearableNudeHands>(this, Row->NudeHands.LoadSynchronous(), "WearableNudeHands");
		UWearableNudeFeet* Feet = NewObject<UWearableNudeFeet>(this, Row->NudeFeet.LoadSynchronous(), "WearableNudeFeet");

		MasterMesh = NewObject<USkeletalMeshComponent>(this, USkeletalMeshComponent::StaticClass(), "BodyMesh");
		MasterMesh->RegisterComponent();
		MasterMesh->SetSkeletalMesh(Row->MasterMesh.LoadSynchronous());
		MasterMesh->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetIncludingScale);

		SlotNudeBust->Equip(Bust);
		SlotNudeLegs->Equip(Legs);
		SlotNudeHands->Equip(Hands);
		SlotNudeFeet->Equip(Feet);
	}
}


void UBodyHuman::UpdatePoly()
{
	SlotNudeBust->Equipped->UpdatePoly();
	SlotNudeLegs->Equipped->UpdatePoly();
	SlotNudeHands->Equipped->UpdatePoly();
	SlotNudeFeet->Equipped->UpdatePoly();
}