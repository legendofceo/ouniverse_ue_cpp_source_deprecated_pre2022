// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro.h"



void UPro::DoEngage()
{
    Engage();
}

void UPro::Engage()
{
    BeginEngage();
}

void UPro::BeginEngage_Implementation()
{

}

void UPro::DoDisengage(const FDelDynamic& Event)
{
    FDelBasic OnDisengageComplete;
    OnDisengageComplete.BindLambda([&]()
        {
            Event.Execute();
        });
    Disengage(OnDisengageComplete);
}

void UPro::Disengage(FDelBasic OnDisengageComplete)
{
    DisengageCompleteCB = OnDisengageComplete;
    BeginDisengage();
}

void UPro::BeginDisengage_Implementation()
{
    DisengageComplete();
}

void UPro::DisengageComplete()
{
    DisengageCompleteCB.ExecuteIfBound();
}