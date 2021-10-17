// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "MythRemote.generated.h"


class UMythPro;
class USpectatorRemote;
class UPartyRemote;
class UCompanionRemote;

UENUM(Blueprintable)
enum class EPartyEngageStatus : uint8
{
	None		UMETA(DisplayName = "None"),
	Specator	UMETA(DisplayName = "Spectator"),
	Party		UMETA(DisplayName = "Party"),
	Companion	UMETA(DisplayName = "Companion"),
};

UCLASS(BlueprintType, Blueprintable)
class APP_API UMythRemote : public URemote
{
	GENERATED_BODY()

public:

	UMythRemote();

	void Init(AAppController* AP);

	virtual void BeginPlay() override;

	void Engage();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpectatorRemote* SpectatorRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyRemote* PartyRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCompanionRemote* CompanionRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMythPro* MythPro;

	/** If the player has interacted at all with the party menu. Stored for auto-assignment logic. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInteracted = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EPartyEngageStatus PartyEngageStatus;


	void EngageCompanion();

};
