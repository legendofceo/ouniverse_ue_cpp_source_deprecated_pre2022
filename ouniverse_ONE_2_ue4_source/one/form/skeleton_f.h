// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "common/softpath_link.h"

class Skeleton_F : public Form_F
{

public:

	Skeleton_F() {};
	virtual int FormType() override { return UFormType::Skeleton; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* JSon) override;
	SoftObjectPathLinkS<USkeletalMesh*> SkeletalMesh;

};