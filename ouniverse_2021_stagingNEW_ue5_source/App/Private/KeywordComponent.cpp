// Fill out your copyright notice in the Description page of Project Settings.


#include "KeywordComponent.h"

// Sets default values for this component's properties
UKeywordComponent::UKeywordComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UKeywordComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

int UKeywordComponent::AddKeyword(FKeyword Keyword, FName Source)
{
	FKeywordEntry Entry = FKeywordEntry();
	Entry.Keyword = Keyword;
	Entry.Source = Source;
	Entry.UID = Ticket;
	Ticket++;
	KeywordEntries.Add(Entry);
	return Entry.UID;
}