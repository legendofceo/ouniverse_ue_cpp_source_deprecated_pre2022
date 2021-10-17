// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/Tasks.h"

void UTasks::Add(UTask* AddTask)
{
	Tasks.Add(AddTask);
}

void UTasks::Go()
{
    if (Tasks.Num() == 0)
    {
        Complete();
    }
    for (auto& Task : Tasks)
    {
        Task->OnComplete.AddDynamic(this, &UTasks::ReportCompleted);
        Task->Go();
    }
}

void UTasks::ReportCompleted(UTask* CompletedTask)
{
    Tasks.Remove(CompletedTask);

    if (Tasks.Num() == 0)
    {
        Complete();
    }
}