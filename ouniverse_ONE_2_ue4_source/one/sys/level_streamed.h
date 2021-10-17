// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "level_streamed.generated.h"

class AProtocol_P;
class ULevelHandle;

UCLASS()
class ALevelStreamed : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Category = "0 Editable", EditAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(Category = "1 Details", VisibleAnywhere,BlueprintReadOnly)
	AProtocol_P* Protocol;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	ULevelHandle* Proxy;

	UFUNCTION(BlueprintCallable)
	void Command(FName Command, FName Relay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCommand(FName Command, FName Relay);


};