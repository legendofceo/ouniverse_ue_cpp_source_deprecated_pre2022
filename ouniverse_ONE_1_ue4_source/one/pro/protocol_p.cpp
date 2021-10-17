// Fill out your copyright notice in the Description page of Project Settings.

#include "protocol_p.h"
#include "cosmos_p.h"
#include "../sys/level_streamed.h"


AProtocol_P::AProtocol_P()
{	
}

AProtocol_P* AProtocol_P::CreateProtocol(TSubclassOf<AProtocol_P> InClass, FName InID, AProtocol_P* InOwningProtocol)
{
	AProtocol_P* N = InOwningProtocol->GetWorld()->SpawnActor<AProtocol_P>(InClass.Get(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	N->ID = InID;
	N->OwningProtocol = InOwningProtocol;
	N->OwningProtocol->Attach(N);
	N->Cosmos = ACosmos_P::Get();
	N->Constructor();
	return N;
}

AProtocol_P* AProtocol_P::CreatePrimalProtocol(TSubclassOf<AProtocol_P> InClass, FName InID, UObject* WorldCTX)
{
	AProtocol_P* N = GEngine->GetWorldFromContextObjectChecked(WorldCTX)->SpawnActor<AProtocol_P>(InClass.Get(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	N->ID = InID;
	N->OwningProtocol = nullptr;
	N->Constructor();
	return N;
}

void AProtocol_P::Constructor()
{
	OnConstructor();
}

void AProtocol_P::Activate()
{
	OnActivate();
}

void AProtocol_P::OnActivate_Implementation()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Massive Error: There is no Activation for this protocol!"));
	ActivateComplete();
}

void AProtocol_P::ActivateComplete()
{
	OnActivateComplete();
}

void AProtocol_P::OnActivateComplete_Implementation()
{

}

void AProtocol_P::Deactivate()
{
	OnDeactivate();
}


void AProtocol_P::OnDeactivate_Implementation()
{
	DeactivateComplete();
}


void AProtocol_P::DeactivateComplete()
{
	OnDeactivateComplete();
}


void AProtocol_P::OnDeactivateComplete_Implementation()
{

}

void AProtocol_P::Command(FName InCommand)
{
	OnCommand(InCommand);
}

void AProtocol_P::OnCommand_Implementation(FName InCommand)
{

}