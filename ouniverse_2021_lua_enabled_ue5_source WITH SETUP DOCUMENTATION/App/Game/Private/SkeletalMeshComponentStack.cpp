// Fill out your copyright notice in the Description page of Project Settings.


#include "SkeletalMeshComponentStack.h"


void FSkeletalMeshComponentStack::Reg(USkeletalMeshComponent** SMC)
{
	Stack.Add(SMC);
}

void FSkeletalMeshComponentStack::Add(USkeletalMeshComponent* SMC)
{
	USkeletalMeshComponent** Next  = NextAvailable();
	*Next = SMC;
}

USkeletalMeshComponent** FSkeletalMeshComponentStack::NextAvailable()
{
	int L = Stack.Len();
	for (int i = 0; i < L; i++)
	{
		if (*Stack[i]==nullptr)
		{
			return Stack[i];
		}
	}

	return nullptr;
}