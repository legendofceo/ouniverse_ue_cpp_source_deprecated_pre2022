// Fill out your copyright notice in the Description page of Project Settings.

#include "body_k.h"
#include "equipslot.h"


FName UBodyK::ShapeNode(TEXT("BodyShape"));

FName UBodyshape::EqSlotHeadNode(TEXT("EqSlot_Head"));
FName UBodyshape::EqSlotBustNode(TEXT("EqSlot_Bust"));
FName UBodyshape::EqSlotLegsNode(TEXT("EqSlot_Legs"));
FName UBodyshape::EqSlotUndershirtNode(TEXT("EqSlot_Undershirt"));
FName UBodyshape::EqSlotIntimatesNode(TEXT("EqSlot_Intimates"));
FName UBodyshape::EqSlotHandsNode(TEXT("EqSlot_Hands"));
FName UBodyshape::EqSlotStockingsNode(TEXT("EqSlot_Stockings"));
FName UBodyshape::EqSlotFeetNode(TEXT("EqSlot_Feet"));
FName UBodyshape::EqSlotHarnessNode(TEXT("EqSlot_Harness"));
FName UBodyshape::EqSlotCapeNode(TEXT("EqSlot_Cape"));
FName UBodyshape::EqSlotHatNode(TEXT("EqSlot_Hat"));
FName UBodyshape::EqSlotHairNode(TEXT("EqSlot_Hair"));


UBodyK::UBodyK()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UBodyK::OX(bool On)
{

	//Shape = NewObject<UBodyshape>(this, ShapeType.Get(), ShapeNode);
	//if (!Shape)
	//{
	//	return;
	//}
	//Shape->RegisterComponent();        //You must ConstructObject with a valid Outer that has world, see above	 ;
	//Shape->OX();

	//Shape->AttachTo(GetOwner()->GetRootComponent());
	//could use different than Root Comp
}

UBodyshape::UBodyshape()
{
	PrimaryComponentTick.bCanEverTick = false;

	/**
	SetComponentTickEnabled(false);	
	Bust = NewObject<UEquipSlot>(this, EqSlotBustNode);

	SetComponentTickEnabled(false);
	Legs = NewObject<UEquipSlot>(this, EqSlotLegsNode);

	SetComponentTickEnabled(false);
	Undershirt = NewObject<UEquipSlot>(this, EqSlotUndershirtNode);

	SetComponentTickEnabled(false);
	Intimates = NewObject<UEquipSlot>(this, EqSlotIntimatesNode);

	SetComponentTickEnabled(false);
	Hands = NewObject<UEquipSlot>(this, EqSlotHandsNode);

	SetComponentTickEnabled(false);
	Stockings = NewObject<UEquipSlot>(this, EqSlotStockingsNode);

	SetComponentTickEnabled(false);
	Feet = NewObject<UEquipSlot>(this, EqSlotFeetNode);

	SetComponentTickEnabled(false);
	Harness = NewObject<UEquipSlot>(this, EqSlotHarnessNode);

	SetComponentTickEnabled(false);
	Cape = NewObject<UEquipSlot>(this, EqSlotCapeNode);

	SetComponentTickEnabled(false);
	Hat = NewObject<UEquipSlot>(this, EqSlotHatNode);

	SetComponentTickEnabled(false);
	Hair = NewObject<UEquipSlot>(this, EqSlotHairNode);
*/
}

void UBodyshape::OX()
{
	//Head = NewObject<UEquipSlot>(this, EqSlotBustNode);
}