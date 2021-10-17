// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Party.generated.h"

/**
 * 
 */

class AActra;
class APC;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPartyMemberSlotChanged, AActra*, PartyMember);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyMemberSlotEmpty);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerChange, int, PlayerIndex);

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONE_API UPartyMember : public UActorComponent
{
	GENERATED_BODY()

public:

	void Setup(int Index);


	void SetAdjacent(UPartyMember* InNext, UPartyMember* InPrevious);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMember* Previous;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMember* Next;


	UPartyMember* GetNextAvailable(bool bReverse);

private:
	UPartyMember* GetNextAvailableIterator(int StartIndex, bool bReverse);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Index;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActra* Member = NULL;

	UPROPERTY(BlueprintAssignable)
	FOnPartyMemberSlotChanged OnChanged;
	UPROPERTY(BlueprintAssignable)
	FOnPartyMemberSlotEmpty OnEmpty;
	UPROPERTY(BlueprintAssignable)
	FOnPlayerChange OnPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APC* PC = NULL;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<APC*> Spectators;

	void SetActra(AActra* InMember);

	void ConnectPlayer(APC* InPC);
	void DisconnectPlayer();
	void ConnectSpectator(APC* InPC);

	bool IsEmpty();
	bool IsAvailableForPlayer();



};



UCLASS()
class ONE_API AParty : public AInfo
{
	GENERATED_BODY()


public:

	AParty();

	UPROPERTY(VisibleAnywhere)
	TArray<UPartyMember*> PartyMembers;

	UPartyMember* GetPartyMember(int Index);

	void ConnectToParty(APC* PC);

	void NextMember(APC* PC, bool bReverse);

};
