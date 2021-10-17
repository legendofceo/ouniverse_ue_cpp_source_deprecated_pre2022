// Fill out your copyright notice in the Description page of Project Settings.

#include "skeleton_f.h"


int  Skeleton_F::FromJson(JsonS* J, FLogger* Log)
{
	SkeletalMesh.FromJson(this,J,DataKeys::Skeleton::SkeletalMesh);
	return DataReport_D::Approved;
}

JsonS* Skeleton_F::ToJson(JsonS* J)
{
	Form_F::ToJson(J);
	J->Add(DataKeys::Skeleton::SkeletalMesh, SkeletalMesh.ToString());
	return J;
}