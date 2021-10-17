// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Remote.h"
#include "MythRemote.generated.h"


class UMythPro;
class UOnwardRemote;

UCLASS(BlueprintType, Blueprintable)
class APP_API UMythRemote : public URemote
{
	GENERATED_BODY()

	static const FName SYS;

public:

	UMythRemote();

	void Init(AAppController* AP);

	virtual void BeginPlay() override;

	void Engage();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UOnwardRemote* OnwardRemote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMythPro* MythPro;

};
