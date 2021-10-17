// Fill out your copyright notice in the Description page of Project Settings.


#include "Behavior.h"
#include "Reg.h"
#include "Actra.h"
#include "APC.h"
#include "AGS.h"
#include "Schema.h"
#include "Interactive.h"

// Sets default values for this component's properties
UBehavior::UBehavior()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UBehavior::BeginPlay()
{
	Super::BeginPlay();

	Actra = Cast<AActra>(GetOwner());
	//State = NewObject<UActraState>(this,AGS::GetGS()->ActraStateDefaultClass.Get(),"ActraState");
	//State->Setup(this,Actra);

	//BaseBehavior = NewObject<USchema>(this, AGS::GetGS()->Reg->BehaviorTest.Get(),"BaseBehavior");
	//BaseBehavior->RegisterComponent();
}


void UBehavior::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UBehavior::Pilot()
{	
	Actra->AddInteractor();
	APC::GetPC()->SetInputInterface(this);
}


void UBehavior::Command_Implementation(UCommand* InCommand)
{
	InputCommand(InCommand);
}


void UBehavior::CommandAxis_Implementation(UCommandAxis* InCommandAxis)
{
	InputCommandAxis(InCommandAxis);
}
