// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactive.h"
#include "CollisionTypes.h"
#include "AGS.h"
#include "APC.h"
#include "InterfaceInteractive.h"

UInteractor::UInteractor()
{
	
	SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SetCollisionResponseToChannel(COLLISION_INTERACTIVE, ECollisionResponse::ECR_Overlap);
	LineThickness = 4.0f;
	InitBoxExtent(FVector(110, 51, 100));
	SetRelativeLocation(FVector(110.0f, 0.0f, 10.0f));
	bHiddenInGame = false;
	//TickDelegate = FTickerDelegate::CreateUObject(this, &UInteractor::UpdateResults);
}

void UInteractor::BeginPlay()
{
	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UInteractor::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UInteractor::OnOverlapEnd);
	//TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);

	//When ready this will remove:
	//FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}

bool UInteractor::UpdateResults(float DeltaSeconds)
{
	return true;
}

void UInteractor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UInterfaceInteractive::StaticClass()))
	{
		InteractiveList.Add(OtherActor);
		Num++;
		Update();
		//IInterfaceInteractive::Execute_GainFocus(Focused,Actra);
	}
}

void UInteractor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->GetClass()->ImplementsInterface(UInterfaceInteractive::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Removed!"));
		InteractiveList.Remove(OtherActor);
		Num--;
		Update();
	}
}

void UInteractor::Update()
{

}