// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"

class Spawn_F;

class Manifest_F : public Form_F
{

public:

	Manifest_F() {};
	virtual int FormType() override { return UFormType::Manifest; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* JSon) override;

	ArrayC<Spawn_F> Spawns;

};