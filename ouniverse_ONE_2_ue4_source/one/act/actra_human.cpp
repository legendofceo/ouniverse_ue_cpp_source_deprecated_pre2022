// Fill out your copyright notice in the Description page of Project Settings.

#include "actra_human.h"

#include "LuaComponent.h"

#include "../kit/body_k.h"
#include "../kit/data_k.h"
#include "../kit/equipment_k.h"
#include "../kit/inventory_k.h"
#include "../lua/lua_state_actra.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
//////////////////////////////////////////////////////////////////////////
// AoneCharacter

FName AActraHuman::BodyNode(TEXT("BodyNode"));
FName AActraHuman::InventoryNode(TEXT("Inventory"));
FName AActraHuman::EquipmentNode(TEXT("Equipment"));
FName AActraHuman::DataNode(TEXT("Data"));
FName AActraHuman::LuaNode(TEXT("Lua"));


FName AActraHuman::MeshNameSkeletonAnim(TEXT("CharacterMesh2"));
FName AActraHuman::MeshNameSlotHead(TEXT("CharacterMesh3"));
FName AActraHuman::SlotTorsoName(TEXT("SlotTorso"));
FName AActraHuman::SlotLegsName(TEXT("SlotLegs"));
FName AActraHuman::SlotHandsName(TEXT("SlotHands"));
FName AActraHuman::SlotFeetName(TEXT("SlotFeet"));
FName AActraHuman::OutfitComponentName(TEXT("OutfitComponent"));

UActraHumanLua::UActraHumanLua()
{
	Table.Add("get_name", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(AActraHuman, LUA_GetName)));
	LuaState = ULuaStateActra::StaticClass();
}

AActraHuman::AActraHuman()
{
	/**
	MeshSkeletonAnim = CreateOptionalDefaultSubobject<USlotComponent>(AActraBiped::MeshNameSkeletonAnim);
	if (MeshSkeletonAnim)
	{
		MeshSkeletonAnim->SetupAttachment(RootComponent);
	}

	MeshSlotHead = CreateOptionalDefaultSubobject<USlotComponent>(AActraBiped::MeshNameSlotHead);
	if (MeshSlotHead)
	{
		MeshSlotHead->SetupAttachment(RootComponent);
	}
	*/
	

	Body = CreateOptionalDefaultSubobject<UBodyK>(AActraHuman::BodyNode);
	Data = CreateOptionalDefaultSubobject<UDataK>(AActraHuman::DataNode);
	Inventory = CreateOptionalDefaultSubobject<UInventoryK>(AActraHuman::InventoryNode);
	Equipment = CreateOptionalDefaultSubobject<UEquipmentK>(AActraHuman::EquipmentNode);
	Lua = CreateOptionalDefaultSubobject<UActraHumanLua>(AActraHuman::LuaNode);


	

	/**
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - (GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight())));

	
	MeshSkeletonAnim = CreateOptionalDefaultSubobject<USlotComponent>(AActraHuman::MeshNameSkeletonAnim);
	MeshSkeletonAnim->SetupAttachment(GetMesh());

	MeshSlotHead = CreateOptionalDefaultSubobject<UHeadSlotComponent>(AActraHuman::MeshNameSlotHead);
	MeshSlotHead->SetupAttachment(MeshSkeletonAnim);
	MeshSlotHead->SetMasterPoseComponent(MeshSkeletonAnim, false);

	MeshSlotTorso = CreateOptionalDefaultSubobject<USlotComponent>(AActraHuman::SlotTorsoName);
	MeshSlotTorso->SetupAttachment(MeshSkeletonAnim);
	MeshSlotTorso->SetMasterPoseComponent(MeshSkeletonAnim, false);

	MeshSlotLegs = CreateOptionalDefaultSubobject<USlotComponent>(AActraHuman::SlotLegsName);
	MeshSlotLegs->SetupAttachment(MeshSkeletonAnim);
	MeshSlotLegs->SetMasterPoseComponent(MeshSkeletonAnim, false);

	MeshSlotHands = CreateOptionalDefaultSubobject<USlotComponent>(AActraHuman::SlotHandsName);
	MeshSlotHands->SetupAttachment(MeshSkeletonAnim);
	MeshSlotHands->SetMasterPoseComponent(MeshSkeletonAnim, false);

	MeshSlotFeet= CreateOptionalDefaultSubobject<USlotComponent>(AActraHuman::SlotFeetName);
	MeshSlotFeet->SetupAttachment(MeshSkeletonAnim);
	MeshSlotFeet->SetMasterPoseComponent(MeshSkeletonAnim, false);

	ShapeHuman = CreateOptionalDefaultSubobject<UOutfitComponent>(AActraHuman::OutfitComponentName);
	//OutfitComponent->SetupAttachment(RootComponent);
	*/
};



void AActraHuman::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!IsPendingKill())
	{
		//if (MeshSkeletonAnim)
		//{
			// force animation tick after movement component updates
			//if (MeshSkeletonAnim->PrimaryComponentTick.bCanEverTick && GetCharacterMovement())
			//{
			//	MeshSkeletonAnim->PrimaryComponentTick.AddPrerequisite(GetCharacterMovement(), GetCharacterMovement()->PrimaryComponentTick);
			//}

			// force animation tick after movement component updates
			//if (MeshSlotHead->PrimaryComponentTick.bCanEverTick && GetCharacterMovement())
			//{
			//	MeshSlotHead->PrimaryComponentTick.AddPrerequisite(GetCharacterMovement(), GetCharacterMovement()->PrimaryComponentTick);
			//}
		//}
	}
}

bool AActraHuman::Permit()
{
	OX(true);
	return true;
}


void AActraHuman::OX(bool bOn)
{
	if(bOn)
	{
		Body->OX(true);
	}
}

FLuaValue AActraHuman::LUA_GetName()
{
	return FLuaValue(Name);
}