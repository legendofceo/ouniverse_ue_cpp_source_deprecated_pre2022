// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractorComponent.h"
#include "Log.h"

#include "Kismet/GameplayStatics.h"
#include "InteractiveManager.h"
#include "InteractiveComponent.h"

#include "AnythingUi.h"

const FName UInteractorComponent::SYS = "Interactor";

UInteractorComponent::UInteractorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractorComponent::Init()
{
	/**
	Actra3d = InActra3d;
	*/
}

void UInteractorComponent::On()
{

}

void UInteractorComponent::Off()
{
	ClearTarget(true);
}


/**
bool UInteractorComponent::TryButtonKB(UButtonKB* BT)
{
	return false;
}


bool UInteractorComponent::TryButtonGP(UButtonGP* BT)
{

	switch (BT->GetCommand()) {
	case InputCommandsGP::DPadLeft:
		TryTargetAxis(BT, true);
		break;
	case InputCommandsGP::DPadRight:
		TryTargetAxis(BT, false);
		break;
	}


	return false;
}

void UInteractorComponent::TryTargetAxis(UBT* BT, bool bLeft)
{
	if (InputRepeater.Update(BT))
	{
		TabTarget(bLeft);
	}
}
*/

void UInteractorComponent::TabTarget(bool bLeft)
{
    TArray<UInteractiveComponent*> InteractiveComponents = UInteractiveManager::Get()->GetRelevantInteractiveComponents();

    TArray<UInteractiveComponent*> OnScreenComponents;
    UInteractiveComponent::FilterOnScreenInteractivesAndSortByScreenX(InteractiveComponents, OnScreenComponents);

	TArray<UInteractiveComponent*> FinalResult;

    for (UInteractiveComponent* IC : OnScreenComponents)
    {
		FinalResult.Add(IC);
    }



	int Num = FinalResult.Num();

	if (Num > 0)
	{
		if (Num == 1)
		{
			SetTarget(FinalResult[0]);
		}
		else if (Target == NULL)
		{
			//Change to SelectNearest or Highest Priority;
			SetTarget(FinalResult[0]);
		}
		else
		{

			int Found = FinalResult.Find(Target);

			if (Found == INDEX_NONE)
			{
				//Change to SelectNearest or Highest Priority;
				SetTarget(FinalResult[0]);
			}
			else
			{
				int Result;

				if (bLeft)
				{

					Result = Found - 1;
					if (Result < 0)
					{
						Result = Num - 1;
					}
				}
				else
				{
					Result = Found + 1;
					if (Result >= Num)
					{
						Result = 0;
					}
				}

				SetTarget(FinalResult[Result]);
			}
		}
	}
	else
	{
		ClearTarget(true);
	}
}

void UInteractorComponent::SetTarget(UInteractiveComponent* InteractiveComponent)
{
	Target = InteractiveComponent;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Target->GetInteractiveName().ToString());

	FAnythingUiFetch Fetch = FAnythingUiFetch();

	Fetch.Func.BindLambda([&](FAnythingUiFetch& Fetch)
		{
			ClearTarget(false);

			if (Fetch.AnythingUi)
			{
				ActiveUi = Fetch.AnythingUi;
				ActiveUi->AddToViewport(9001);
			}

			

		});

	Target->GetUi(Fetch);

}

void UInteractorComponent::ClearTarget(bool bEmpty)
{
	if (ActiveUi)
	{
		ActiveUi->RemoveFromParent();
		ActiveUi = nullptr;
	}

}