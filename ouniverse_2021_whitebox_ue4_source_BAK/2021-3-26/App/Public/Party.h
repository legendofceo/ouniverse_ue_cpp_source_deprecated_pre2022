// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Party.generated.h"

/**
 * 
 */
struct FPartyMem;
class UPartyMember;
class UCompanion;

class ACompanionActor;
class UParty;

UENUM(BlueprintType)
enum class EPartyJoinExecs : uint8
{
	JoinedParty,
	PartyFull,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UParty : public UObject
{
	GENERATED_BODY()
	
public:

	UParty() {};

	void Init();

	FPartyMem* Mem;

	void SetMem(FPartyMem* PartyMem);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MembersMax = 4;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MembersNum = 0;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TArray<UPartyMember*> PartyMembers;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPartyMember* Leader = NULL;

	bool CanAddMember();

	void AddMember(UCompanion* Companion);

	bool AddPartyMember(UCompanion* Companion);

	void SetLeader(int MemberIndex);

	void Engage();

};
