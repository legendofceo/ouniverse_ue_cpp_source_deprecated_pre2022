// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUi.h"
#include "AppController.h"
#include "Components/PanelWidget.h"



void UBaseUi::DoOpen()
{
    FDelBasic OnOpenComplete;
    OnOpenComplete.BindLambda([&]()
        {

        });
    Open(OnOpenComplete);
}

void UBaseUi::DoOpenCB(const FDelDynamic& Event)
{
    FDelBasic OnOpenComplete;
    OnOpenComplete.BindLambda([&]()
        {
            Event.Execute();
        });
    Open(OnOpenComplete);
}

void UBaseUi::Open(FDelBasic OnOpenComplete)
{
    OpenCompleteCB = OnOpenComplete;
    BeginOpen();
}

void UBaseUi::BeginOpen_Implementation()
{
    OpenComplete();
}

void UBaseUi::OpenComplete()
{
    OpenCompleteCB.ExecuteIfBound();
}


void UBaseUi::DoClose(const FDelDynamic& Event)
{
    FDelBasic OnCloseComplete;
    OnCloseComplete.BindLambda([&]()
        {
            Event.Execute();
        });
    Close(OnCloseComplete);
}

void UBaseUi::Close(FDelBasic OnCloseComplete)
{
    CloseCompleteCB = OnCloseComplete;
    BeginClose();
}

void UBaseUi::BeginClose_Implementation()
{
    CloseComplete();
}

void UBaseUi::CloseComplete()
{
    CloseCompleteCB.ExecuteIfBound();
}