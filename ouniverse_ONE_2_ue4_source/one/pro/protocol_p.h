// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../sys/base.h"
#include "protocol_p.generated.h"

class ALevelStreamed;
class ACosmos_P;
class AControlUE;
class UControlLink;


UCLASS()
class AProtocol_P : public ABase
{

	GENERATED_BODY()


public:

	AProtocol_P();
	
	UFUNCTION(BlueprintCallable)
	static AProtocol_P* CreateProtocol(TSubclassOf<AProtocol_P> InClass, FName InID, AProtocol_P* InOwningProtocol);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldCTX", ShowWorldContextPin))
	static AProtocol_P* CreatePrimalProtocol(TSubclassOf<AProtocol_P> InClass, FName InID, UObject* WorldCTX);

	virtual void Constructor();

	UFUNCTION(BlueprintImplementableEvent)
	void OnConstructor();
	void OnConstructor_Implementation() {};

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	FName ID;
	
	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	ACosmos_P* Cosmos;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	AProtocol_P* OwningProtocol;

	UFUNCTION(BlueprintCallable)
	AControlUE* GetControl();

	UFUNCTION(BlueprintCallable)
	virtual void Activate();
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OnActivate();
	void OnActivate_Implementation();

	UFUNCTION(BlueprintCallable)
	void ActivateComplete();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnActivateComplete();
	void OnActivateComplete_Implementation();

	UFUNCTION(BlueprintCallable)
	void Deactivate();
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OnDeactivate();
	void OnDeactivate_Implementation();

	UFUNCTION(BlueprintCallable)
	void DeactivateComplete();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeactivateComplete();
	void OnDeactivateComplete_Implementation();

	UFUNCTION(BlueprintCallable)
	void Command(FName Command);
	UFUNCTION(BlueprintImplementableEvent)
	void OnCommand(FName Command);
	void OnCommand_Implementation(FName Command);

};