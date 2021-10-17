// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandMenuInterface.h"
#include "AppController.h"

void UCommandMenuInterfaceStatics::ApplyBT(UBT* BT, UObject* Interface)
{

#if (!UE_BUILD_SHIPPING)
    if (!Interface->GetClass()->ImplementsInterface(UCommandMenuInterface::StaticClass()))
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("CommandMenuInterfaceStatics: Interface is not correctly set"));
        return;
    }
#endif

    CommandToInterface(AAppController::Get()->GetCommand(BT), BT, Interface);
}

void UCommandMenuInterfaceStatics::ApplyCommand(CommandMenu Command, UBT* BT, UObject* Interface)
{


#if (!UE_BUILD_SHIPPING)
    if (!Interface->GetClass()->ImplementsInterface(UCommandMenuInterface::StaticClass()))
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("CommandMenuInterfaceStatics: Interface is not correctly set"));
        return;
    }
#endif
    
    CommandToInterface(Command, BT, Interface);
}

void UCommandMenuInterfaceStatics::CommandToInterface(CommandMenu Command, UBT* BT, UObject* Interface)
{

    ICommandMenuInterface::Execute_CommandMenuAny(Interface, Command, BT);

    switch (Command) {
    case CommandMenu::Up:
        ICommandMenuInterface::Execute_CommandMenuUp(Interface, BT);
        break;
    case CommandMenu::Down:
        ICommandMenuInterface::Execute_CommandMenuDown(Interface, BT);
        break;
    case CommandMenu::Left:
        ICommandMenuInterface::Execute_CommandMenuLeft(Interface, BT);
        break;
    case CommandMenu::Right:
        ICommandMenuInterface::Execute_CommandMenuRight(Interface, BT);
        break;
    case CommandMenu::Accept:
        ICommandMenuInterface::Execute_CommandMenuAccept(Interface, BT);
        break;
    case CommandMenu::Cancel:
        ICommandMenuInterface::Execute_CommandMenuCancel(Interface, BT);
        break;
    }
}

void ICommandMenuInterface::CommandMenuAny_Implementation(CommandMenu Command, UBT* BT)
{
	
}

void ICommandMenuInterface::CommandMenuUp_Implementation(UBT* BT)
{

}

void ICommandMenuInterface::CommandMenuDown_Implementation(UBT* BT)
{

}

void ICommandMenuInterface::CommandMenuLeft_Implementation(UBT* BT)
{

}

void ICommandMenuInterface::CommandMenuRight_Implementation(UBT* BT)
{

}

void ICommandMenuInterface::CommandMenuAccept_Implementation(UBT* BT)
{

}

void ICommandMenuInterface::CommandMenuCancel_Implementation(UBT* BT)
{

}