// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveComponent.h"
#include "Log.h"
#include "InteractiveManager.h"
#include "InteractiveMutual.h"
#include "Kismet/GameplayStatics.h"
#include "AppController.h"

const FName UInteractiveComponent::SYS = "InteractiveComponent";

// Sets default values for this component's properties
UInteractiveComponent::UInteractiveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UInteractiveComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UInteractiveComponent::SetInteractiveMutual(UObject* InMutual)
{
	if (InMutual->GetClass()->ImplementsInterface(UInteractiveMutual::StaticClass()))
	{
		InteractiveMutual = InMutual;
	}
	else
	{
		LOG.S(SYS).T(TCRIT).W("An object without InteractiveMutual was set").DebugM();
	}
}

void UInteractiveComponent::On()
{	
	UInteractiveManager::Get()->AddInteractiveComponent(this);
}

void UInteractiveComponent::Off()
{
	UInteractiveManager::Get()->RemoveInteractiveComponent(this);
}

FText UInteractiveComponent::GetInteractiveName()
{
	return IInteractiveMutual::Execute_GetInteractiveName(InteractiveMutual);
}

FText UInteractiveComponent::GetInteractiveNameBP()
{
	return GetInteractiveName();
}


void UInteractiveComponent::GetUi(FAnythingUiFetch& Fetch)
{
	IInteractiveMutual::Execute_GetInteractiveUi(InteractiveMutual,Fetch);
}


void UInteractiveComponent::FilterOnScreenInteractivesAndSortByScreenX(TArray<UInteractiveComponent*>& InteractiveComponents, TArray<UInteractiveComponent*>& Output)
{
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);

	int L = InteractiveComponents.Num();

	TArray<FInteractiveComponentAndScreenX> ScreenStructs;

	UInteractiveComponent* IC;
	for (int i = 0; i < L; i++)
	{
		IC = InteractiveComponents[i];

		if (IC->GetOwner()->WasRecentlyRendered())
		{
			FVector2D ScreenPosition;
			UGameplayStatics::ProjectWorldToScreen(AAppController::Get(), IC->GetComponentLocation(), ScreenPosition, false);
			ScreenStructs.Add(FInteractiveComponentAndScreenX(ScreenPosition.X, IC));
		}
	}

	ScreenStructs.Sort(FSortInteractiveComponentAndScreenX());

	for (FInteractiveComponentAndScreenX& Struct : ScreenStructs)
	{
		Output.Add(Struct.InteractiveComponent);
	}
}