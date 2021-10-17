// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegate.h"
#include "PartyMng.generated.h"

class APlaythrough;
class ACompanion;
class UCompanionMng;
class UTasks;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UPartyMng : public UActorComponent
{
	GENERATED_BODY()

public:

	UPartyMng();

protected:

	virtual void BeginPlay() override;

public:

	void Init();

	void InitII(APlaythrough* InPlaythrough, UCompanionMng* InCompanionMng);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Loaded = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool LoadInProgress = false;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	APlaythrough* Playthrough = NULL;

	UPROPERTY(BlueprintReadOnly)
	UCompanionMng* CompanionMng = NULL;

	void PlacePartyAtRef();

	void Load();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTasks* PartyLoadTask = NULL;

	UFUNCTION()
	void LoadComplete(UTask* Task);

	void Unload();

	UPROPERTY(BlueprintAssignable)
	FDelegate OnLoaded;

	UPROPERTY(BlueprintAssignable)
	FDelegate OnUnLoaded;
};
