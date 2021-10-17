// Fill out your copyright notice in the Description page of Project Settings.


#include "LogComponent.h"

// Sets default values for this component's properties
ULogComponent::ULogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULogComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULogComponent::Write(TEnumAsByte<ELogStatus> Status, TEnumAsByte<ELogVerb> Verbosity, uint8 Indent, bool DataList, FString Text)
{
	FLogEntry NewEntry = FLogEntry();
	NewEntry.Status = Status;
	NewEntry.Verbosity = Verbosity;
	NewEntry.Indent = Indent;
	NewEntry.Text = Text;
	NewEntry.DataList = DataList;
	NewEntry.Time = FPlatformTime::Seconds();
	Entries.Add(NewEntry);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Text);
}