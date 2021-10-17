// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Delegate.h"
#include "ActraEx.generated.h"


class UActraMem;
class UVizEx;


UCLASS(BlueprintType,Blueprintable)
class APP_API AActraEx : public ACharacter
{
	GENERATED_BODY()

	static const FName SYS;

public:

	AActraEx();

	virtual void BeginInit();

	void InitComplete();

	UPROPERTY(VisibleAnywhere)
	UActraMem* ActraMem;

	void Init(UActraMem* InActraMem, FDelBasic Callback);

	FDelBasic OnInitComplete;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* FollowCamera;


	virtual void Connect() {};

	void Pilot();
	void Unpilot();



	UPROPERTY(VisibleAnywhere)
	TArray<UVizEx*> VizExs;

};