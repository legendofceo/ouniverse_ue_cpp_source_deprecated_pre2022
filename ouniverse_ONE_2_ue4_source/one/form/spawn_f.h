// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"


class Spawn_F
{

public:

	Spawn_F() {};
	virtual int FormType() { return UFormType::Spawn; };
	int FromJson(JsonS* J, UAtlas* Atlas, FLogger* Log);
	JsonS ToJson();

	int UID;
	FVector Position;
	FRotator Rotation;
	FVector Scale;
	FDataAddress DataAddress;
	bool bRandomizeRotationX = false;

};