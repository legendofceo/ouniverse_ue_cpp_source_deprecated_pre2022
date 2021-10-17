// Fill out your copyright notice in the Description page of Project Settings.


#include "App/Application.h"
#include "Engine/World.h"
#include "App/Major.h"
#include "App/Control.h"
#include "App/Mode.h"
#include "App/Reg.h"
#include "App/Scope.h"
#include "App/Server.h"
#include "Pro/Maestro.h"
#include "Ui/Ui.h"

#include "Kismet/GameplayStatics.h"

namespace GlobalApp
{
	UApp* Object;
}


UApp* UApp::Get()
{
	return GlobalApp::Object;
}

void UApp::BootOUniverse(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	GlobalApp::Object = this;

	switch (InBootMethod) {
	case EBootMethod::Standard:
		Standard(WorldContextObject);
		break;
	}
}


void UApp::Standard(UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return;
	}

	UWorld* World_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	
	ScopeC::Initialize(WorldContextObject, World_);
	
	
	Major_ = UMajor::Create();

	/**
	bool bModeFail = false;
	if (UGameplayStatics::GetGameMode(WorldContextObject)->GetClass() != AMode::StaticClass())
	{
		bModeFail = true;
		return;
	}
	*/

	Major_->Control_ = Cast<AControl>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));

	

	Major_->Reg_ = UReg::Create();
	Major_->Ui_ = UUi::Create();
	Major_->Server_ = World_->SpawnActor<AServer>(UReg::Get()->ServerClass, FVector(0.0f,0.0f,0.0f), FRotator(0.0f,0.0f,0.0f));
	Major_->Maestro_ = UMaestro::Create(Major_->Control(), Major_->Ui());
	Major_->Control()->Init(Major_->Maestro());
	Major_->Maestro_->Start();
}