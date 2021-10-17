// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CommandsMenu.h"
#include "CommandMenuInterface.generated.h"


class UBT;

UCLASS()
class UCommandMenuInterfaceStatics : public UObject
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "@Menu: ApplyBT", DefaultToSelf = "Interface"))
	static void ApplyBT(UBT* BT, UObject* Interface);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "@Menu: ApplyCommand",DefaultToSelf="Interface"))
	static void ApplyCommand(CommandMenu Command, UBT* BT, UObject* Interface);

	static void CommandToInterface(CommandMenu Command, UBT* BT, UObject* Interface);

};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCommandMenuInterface : public UInterface
{
	GENERATED_BODY()



};

/**
 *
 */
class APP_API ICommandMenuInterface
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Any"))
	void CommandMenuAny(CommandMenu Command, UBT* BT);
	virtual void CommandMenuAny_Implementation(CommandMenu Command, UBT* BT);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Up"))
	void CommandMenuUp(UBT* BT);
	virtual void CommandMenuUp_Implementation(UBT* BT);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Down"))
	void CommandMenuDown(UBT* BT);
	virtual void CommandMenuDown_Implementation(UBT* BT);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Left"))
	void CommandMenuLeft(UBT* BT);
	virtual void CommandMenuLeft_Implementation(UBT* BT);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Right"))
	void CommandMenuRight(UBT* BT);
	virtual void CommandMenuRight_Implementation(UBT* BT);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Accept"))
	void CommandMenuAccept(UBT* BT);
	virtual void CommandMenuAccept_Implementation(UBT* BT);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Menu: Cancel"))
	void CommandMenuCancel(UBT* BT);
	virtual void CommandMenuCancel_Implementation(UBT* BT);

};