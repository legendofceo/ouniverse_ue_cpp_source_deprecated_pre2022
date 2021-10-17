// Fill out your copyright notice in the Description page of Project Settings.


#include "VideoPlayer.h"
#include "MediaTexture.h"
#include "MediaPlayer.h"

#include "AppInstance.h"

void UVideoPlayer::CreateBP(UVideoPlayer*& Param, UMaterialInterface* Mat, UObject* WorldContextObject, UVideoPlayer*& VideoPlayer)
{
	VideoPlayer = NewObject<UVideoPlayer>(WorldContextObject, UVideoPlayer::StaticClass());
	VideoPlayer->Init();
	VideoPlayer->SetMatBase(Mat);
	Param = VideoPlayer;
}

void UVideoPlayer::Init()
{
	MediaPlayer = NewObject<UMediaPlayer>(this, UMediaPlayer::StaticClass());
	MediaTexture = NewObject<UMediaTexture>(this, UMediaTexture::StaticClass());
	MediaTexture->ClearColor = FLinearColor(0,0,0,0);
	MediaTexture->AutoClear = true;
	MediaTexture->SetMediaPlayer(MediaPlayer);
	MediaTexture->UpdateResource();
}

void UVideoPlayer::SetMatBase(UMaterialInterface* NewMatBase)
{
	MatBase = NewMatBase;
	MatDynamic = UMaterialInstanceDynamic::Create(MatBase, this);
	MatDynamic->SetTextureParameterValue("mediatexture", MediaTexture);
}