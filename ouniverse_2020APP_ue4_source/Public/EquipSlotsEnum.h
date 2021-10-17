// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquipSlotsEnum.generated.h"

/**
 * 
 */


UENUM()
enum EEquipSlots
{
	EquipSlotsNone			UMETA(DisplayName = "Stopped"),
	EquipSlotsNudeBust		UMETA(DisplayName = "NudeBust"),
	EquipSlotsNudeLegs		UMETA(DisplayName = "NudeLegs"),
	EquipSlotsNudeHands		UMETA(DisplayName = "NudeHands"),
	EquipSlotsNudeFeet		UMETA(DisplayName = "NudeFeet"),
	EquipSlotsHair 			UMETA(DisplayName = "Hair"),
	EquipSlotsHeadgear		UMETA(DisplayName = "Headgear"),
	EquipSlotsHeadcloth		UMETA(DisplayName = "Headcloth"),
	EquipSlotsEarringL		UMETA(DisplayName = "EarringL"),
	EquipSlotsEarringR		UMETA(DisplayName = "EarringR"),
	EquipSlotsNecklace		UMETA(DisplayName = "Necklace"),
	EquipSlotsShirt			UMETA(DisplayName = "Shirt"),
	EquipSlotsCuirass		UMETA(DisplayName = "Armor"),
	EquipSlotsCape			UMETA(DisplayName = "Cape"),
	EquipSlotsSocks			UMETA(DisplayName = "Sock"),
	EquipSlotsFeet			UMETA(DisplayName = "Feet"),
	EquipSlotsFingerNails	UMETA(DisplayName = "FingerNails"),
	EquipSlotsToeNails		UMETA(DisplayName = "ToeNails"),
	EquipSlotsRingR1		UMETA(DisplayName = "RingR1"),
	EquipSlotsRingR2		UMETA(DisplayName = "RingR2"),
	EquipSlotsFeetR3		UMETA(DisplayName = "RingR3"),
	EquipSlotsFeetR4		UMETA(DisplayName = "RingR4"),
	EquipSlotsFeetR5		UMETA(DisplayName = "RingR5"),
	EquipSlotsRingL1		UMETA(DisplayName = "RingL1"),
	EquipSlotsRingL2		UMETA(DisplayName = "RingL2"),
	EquipSlotsFeetL3		UMETA(DisplayName = "RingL3"),
	EquipSlotsFeetL4		UMETA(DisplayName = "RingL4"),
	EquipSlotsFeetL5		UMETA(DisplayName = "RingL5"),
};