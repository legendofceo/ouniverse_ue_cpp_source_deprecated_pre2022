// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegate.h"
#include "NotificationUi.generated.h"

class UBT;
class UCanvasPanel;


UCLASS(BlueprintablE,BlueprintType)
class APP_API UNotificationUi : public UUserWidget
{
	GENERATED_BODY()

public:

	void Open(const FDelBasic& Callback);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#BeginOpen"))
	void BeginOpen();

	UFUNCTION(BlueprintCallable,meta=(DisplayName="#Close"))
	void Close();

	UFUNCTION(BlueprintNativeEvent, meta = (DisplayName = "#BeginClose"))
	void BeginClose();
	virtual void BeginClose_Implementation();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#CloseComplete"))
	void CloseComplete();

	FDelBasic OnComplete;

	FTimerHandle Timer;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float DisplayTime = 2.0;

};

UCLASS(Abstract,Blueprintable, BlueprintType)
class APP_API UNotificationWin : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	bool bDisplayingNotification = false;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* NotificationPin;

	UPROPERTY(VisibleAnywhere)
	TArray<UNotificationUi*> Notifications;

	UFUNCTION(Blueprintcallable, meta = (DisplayName = "#AddNotification"))
	void AddNotification(TSoftClassPtr<UNotificationUi> NotificationSoft);
	
	void AddNotification_Stream(TSoftClassPtr<UNotificationUi> NotificationSoft);

	void AddToQue(UNotificationUi* Notification);

	void ShowNextNotification();
	void NotificationComplete();
};