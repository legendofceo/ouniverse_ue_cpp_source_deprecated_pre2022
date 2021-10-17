// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePro.h"
#include "Blue.h"
#include "Log.h"
#include "AppPro.h"

const FName UTitlePro::SYS = "TitlePro";

namespace Pro
{
	UTitlePro* TitleMenu = nullptr;
}

UTitlePro::UTitlePro() : UProtocol()
{

}

UTitlePro* UTitlePro::Get()
{
	return Pro::TitleMenu;
}

void UTitlePro::GetBP(UTitlePro*& TitlePro)
{
	TitlePro = Pro::TitleMenu;
}

void UTitlePro::Init()
{
	Pro::TitleMenu = this;

#if (WITH_EDITOR)
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("EngagetBP");
	BEF.Go(this, "TitlePro");
#endif

	LOG.S(SYS).W("Init Complete()");
	InitComplete();
}

void UTitlePro::Engage()
{
	EngageBP();
}

void UTitlePro::OptionBeginBP()
{

}