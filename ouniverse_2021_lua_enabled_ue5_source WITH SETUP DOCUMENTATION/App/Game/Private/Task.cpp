// Fill out your copyright notice in the Description page of Project Settings.


#include "Task.h"

UTask::UTask()
{
    TaskKey = "TaskAbstract";
}

void UTask::RunTask(FName Context)
{
    TaskContext = Context;
    RunTaskOverride();
}

void UTask::RunTaskOverride()
{
    Complete();
    //Must be called for task to complete, always include this in override;
}

void UTask::Complete()
{
	Completed = true;
	OnComplete.Broadcast(this);
	OnComplete.RemoveAll(this);
}







UTaskMulti::UTaskMulti()
{
    TaskKey = "TaskMulti";
}

UTaskMulti* UTaskMulti::New(UObject* Outer)
{
    return NewObject<UTaskMulti>(Outer, UTaskMulti::StaticClass());
}

void UTaskMulti::Add(UTask* AddTask)
{
	Tasks.Add(AddTask);
}

void UTaskMulti::RunTaskOverride()
{
    if (Tasks.Num() == 0)
    {
        Complete();
    }
    for (auto& Task : Tasks)
    {
        Task->OnComplete.AddDynamic(this, &UTaskMulti::ReportCompleted);
        Task->RunTask(TaskContext);
    }
}

void UTaskMulti::ReportCompleted(UTask* CompletedTask)
{
    Tasks.Remove(CompletedTask);

    if (Tasks.Num() == 0)
    {
        Complete();
    }
}

