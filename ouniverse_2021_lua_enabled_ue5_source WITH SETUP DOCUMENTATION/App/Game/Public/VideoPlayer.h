// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VideoPlayer.generated.h"


class UMediaTexture;
class UMediaPlayer;
class UMaterialInterface;

UENUM(BlueprintType)
enum class VideoPlayerMatTypes : uint8
{
	None,
	UiOpaque,
	UiTransparent,
};

UCLASS(Blueprintable, BlueprintType)
class APP_API UVideoPlayer : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Create VideoPlayer", WorldContext = "WorldContextObject"))
	static void CreateBP(UPARAM(ref) UVideoPlayer*& Param, UMaterialInterface* Mat, UObject* WorldContextObject, UVideoPlayer*& VideoPlayer);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UMediaTexture* MediaTexture;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UMediaPlayer* MediaPlayer;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* MatBase;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UMaterialInstanceDynamic* MatDynamic;

	void Init();

	void SetMatBase(UMaterialInterface* NewMatBase);

};
