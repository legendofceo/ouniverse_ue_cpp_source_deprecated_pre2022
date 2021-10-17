// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AGS.generated.h"

/**
 * 
 */

class UDataTable;
class UReg;
class AParty;

UCLASS()
class ONE_API AGS : public AGameStateBase
{
	GENERATED_BODY()

	AGS();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AParty* Party;

	UFUNCTION(BlueprintCallable,BlueprintPure)
	static AGS* GetGS();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UReg> RegClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UReg* Reg;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* ItemTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* ActraTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* BodyHumanTable;
};
