// Fill out your copyright notice in the Description page of Project Settings.


#include "Statics.h"
#include "APC.h"
#include "Kismet/GameplayStatics.h"

TArray<AActor*> UStatics::GetAllActorsOnScreenInRadius(UObject* WorldContextObject, FVector Epicenter, float MaxRange, TArray<TEnumAsByte<EObjectTypeQuery>> CollisionQuery, UClass* FilteredClass, TArray<AActor*> IgnoreActors)
{

	TArray<AActor*> Output;

	TArray<TEnumAsByte<EObjectTypeQuery>> Collisions;
	TArray<AActor*> Actors;
	//Collisions.Add(EObjectTypeQuery::ObjectTypeQuery7);
	APC* PC = APC::GetPC();

	bool bHit = UKismetSystemLibrary::SphereOverlapActors(WorldContextObject, Epicenter, MaxRange, CollisionQuery, FilteredClass, IgnoreActors, Actors);


	if (bHit)
	{
		TArray<FActorAndScreenX> ValidActors;
		FVector2D ViewportSize;
		GEngine->GameViewport->GetViewportSize(ViewportSize);

		int L = Actors.Num();
		for (int i = 0; i < L; i++)
		{
			if (Actors[i]->WasRecentlyRendered())
			{
				FVector2D ScreenPosition;
				UGameplayStatics::ProjectWorldToScreen(APC::GetPC(), Actors[i]->GetActorLocation(), ScreenPosition, false);

				if (ScreenPosition.X < ViewportSize.X && ScreenPosition.Y < ViewportSize.Y && ScreenPosition.X >= 0 && ScreenPosition.Y >= 0)
				{
					ValidActors.Add(FActorAndScreenX(ScreenPosition.X, Actors[i]));
					//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hit Occured!"));
				}

			}

		}

		int L2 = ValidActors.Num();
		ValidActors.Sort(FSortActorAndScreenX());

		
		for (int i = 0; i < L2; i++)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::SanitizeFloat(ValidActors[i].X));
			Output.Add(ValidActors[i].Actor);
		}
	}

	return Output;
}