// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RemoteActraHuman.generated.h"

class AActra3d;
class UAX;

UCLASS(BlueprintType,Blueprintable)
class APP_API URemoteActraHuman : public UObject
{
	GENERATED_BODY()

	static const FName SYS;

public:

	URemoteActraHuman() {};

	void Init();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit;
	
	void TurnAtRate(float Rate);
	void TurnAtRateAX(UAX* AX);


	void LookUpAtRate(float Rate);
	void LookUpAtRateAX(UAX* AX);

	void MoveForward(float Value);
	void MoveForwardAX(UAX* AX);

	void MoveRight(float Value);
	void MoveRightAX(UAX* AX);



	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

};