// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/Task.h"

void UTask::Go()
{
	Complete();
}

void UTask::Complete()
{
	Completed = true;
	OnComplete.Broadcast(this);
	OnComplete.RemoveAll(this);
}