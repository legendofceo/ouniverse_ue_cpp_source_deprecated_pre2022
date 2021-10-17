// Fill out your copyright notice in the Description page of Project Settings.


#include "KitRove.h"
#include "InputRaw.h"
#include "ActraExHuman.h"

void UKitRove::Init(AActraExHuman* InActraExHuman)
{
    ActraExHuman = InActraExHuman;

}


void UKitRove::Connect()
{
   /**
    FInputButtonEventBinding MainMenu;
    MainMenu.BindDynamic(this,&UKitRove::MainMenu);
    UInputMap::Get()->GamepadStart->BindButtonEvent(InputToken, MainMenu);

    FInputButtonEventBinding PartyUpGamepad;
    PartyUpGamepad.BindDynamic(this, &UKitRove::PartyUp);
    UInputMap::Get()->GamepadDpadUp->BindButtonEvent(InputToken, PartyUpGamepad);

    FInputButtonEventBinding PartyDownGamepad;
    PartyDownGamepad.BindDynamic(this, &UKitRove::PartyDown);
    UInputMap::Get()->GamepadDpadDown->BindButtonEvent(InputToken, PartyDownGamepad);


    FInputAxisEventBinding MoveForwardGamepad;
    MoveForwardGamepad.BindDynamic(this, &UKitRove::MoveForwardGamepad);
    UInputMap::Get()->GamepadAxisJoyLeftY->BindAxisEvent(InputToken, MoveForwardGamepad);

    FInputAxisEventBinding MoveRightGamepad;
    MoveRightGamepad.BindDynamic(this, &UKitRove::MoveRightGamepad);
    UInputMap::Get()->GamepadAxisJoyLeftX->BindAxisEvent(InputToken, MoveRightGamepad);

    FInputAxisEventBinding TurnAtRateGamepad;
    TurnAtRateGamepad.BindDynamic(this, &UKitRove::TurnAtRate);
    UInputMap::Get()->GamepadAxisJoyRightX->BindAxisEvent(InputToken, TurnAtRateGamepad);

    FInputAxisEventBinding LookUpAtRateGamepad;
    LookUpAtRateGamepad.BindDynamic(this, &UKitRove::LookUpAtRate);
    UInputMap::Get()->GamepadAxisJoyRightY->BindAxisEvent(InputToken, LookUpAtRateGamepad);
    */
}



void UKitRove::Disconnect()
{

}



void UKitRove::MainMenu(UBT* BT)
{
    //UOnwardPro::Get()->EngageOnwardMenu();
}

void UKitRove::PartyUp(UBT* BT)
{
    if (BT->IsClick())
    {
        //UOnwardPro::Get()->ShiftPartyPlayerIndexUp();
    }
}

void UKitRove::PartyDown(UBT* BT)
{
    if (BT->IsClick())
    {
        //UOnwardPro::Get()->ShiftPartyPlayerIndexDown();
    }
}

void UKitRove::MoveForwardGamepad(UAX* AX)
{
    
    float Power = AX->GetPower();
    if ((ActraExHuman->Controller != nullptr) && (Power != 0.0f))
    {
        // find out which way is forward
        const FRotator Rotation = ActraExHuman->Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        ActraExHuman->AddMovementInput(Direction, Power);
    }

}

void UKitRove::MoveRightGamepad(UAX* AX)
{

    float Power = AX->GetPower();
    if ((ActraExHuman->Controller != nullptr) && (Power != 0.0f))
    {
        // find out which way is right
        const FRotator Rotation = ActraExHuman->Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // get right vector 
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        // add movement in that direction
        ActraExHuman->AddMovementInput(Direction, Power);
    }

}

void UKitRove::TurnAtRate(UAX* AX)
{
    // calculate delta for this frame from the rate information
    float Power = AX->GetPower();
    ActraExHuman->AddControllerYawInput(Power * BaseTurnRate * ActraExHuman->GetWorld()->GetDeltaSeconds());

}

void UKitRove::LookUpAtRate(UAX* AX)
{

    // calculate delta for this frame from the rate information
    float Power = AX->GetPower()*-1;
    ActraExHuman->AddControllerPitchInput(Power * BaseLookUpRate * ActraExHuman->GetWorld()->GetDeltaSeconds());

}