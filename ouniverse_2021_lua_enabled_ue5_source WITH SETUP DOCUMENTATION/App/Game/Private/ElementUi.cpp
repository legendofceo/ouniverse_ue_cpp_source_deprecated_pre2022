// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementUi.h"
#include "AppController.h"
#include "Components/PanelWidget.h"


void UElementUi::DoEngage()
{
    FDelBasic OnEngageComplete;
    OnEngageComplete.BindLambda([&]()
        {

        });
    Engage(OnEngageComplete);
}

void UElementUi::DoEngageCB(const FDelDynamic& Event)
{
    FDelBasic OnEngageComplete;
    OnEngageComplete.BindLambda([&]()
        {
            Event.Execute();
        });
    Engage(OnEngageComplete);
}

void UElementUi::Engage(FDelBasic OnEngageComplete)
{
    EngageCompleteCB = OnEngageComplete;
    BeginEngage();
}

void UElementUi::BeginEngage_Implementation()
{
    EngageComplete();
}

void UElementUi::EngageComplete()
{
    EngageCompleteCB.ExecuteIfBound();
}


void UElementUi::DoDisengage(const FDelDynamic& Event)
{
    FDelBasic OnDisengageComplete;
    OnDisengageComplete.BindLambda([&]()
        {
            Event.Execute();
        });
    Disengage(OnDisengageComplete);
}

void UElementUi::Disengage(FDelBasic OnDisengageComplete)
{
    DisengageCompleteCB = OnDisengageComplete;
    BeginDisengage();
}

void UElementUi::BeginDisengage_Implementation()
{
    DisengageComplete();
}

void UElementUi::DisengageComplete()
{
   DisengageCompleteCB.ExecuteIfBound();
}

