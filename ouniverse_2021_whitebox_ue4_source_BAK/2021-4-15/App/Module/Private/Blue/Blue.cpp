// Fill out your copyright notice in the Description page of Project Settings.


#include "Blue.h"
#include "Log.h"
void FBlueEnsureImplementation::Add(FName Name)
{
    FunctionNames.Add(Name);
}

void FBlueEnsureImplementation::Go(UObject* Obj, FString ID)
{
    for (FName FN : FunctionNames)
    {
        UFunction* function = Obj->FindFunction(FN);

        if (function != NULL)
        {
            FString name = function->GetName();
            bool b = function->IsInBlueprint();
            if (!b)
            {
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Implementation of Function missing. ID: "+ID+"  FN: "+FN.ToString());
            }
        }
    }
}