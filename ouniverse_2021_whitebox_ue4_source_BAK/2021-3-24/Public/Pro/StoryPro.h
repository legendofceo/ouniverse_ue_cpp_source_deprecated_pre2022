// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pro.h"
#include "AreaAddress.h"
#include "StoryPro.generated.h"

/**
 * 
 */
class AAppPro;
class APartyPro;
class UStory;
class UInputButtonEvent;
class UArea;
class ACompanionActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStoryProDelegate);

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AStoryPro : public APro
{
	GENERATED_BODY()

public:

	static AStoryPro* Get();

	/** Static Getter of the StoryPro casting from UE5's GetGameMode to retreive it. */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "#StoryPro"))
	static void GetStoryProBP(AStoryPro*& StoryPro);

	void Init(AAppPro* InAppPro);

	UFUNCTION()
	void InitLL();

	UFUNCTION()
	void InitSO();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Initialized = false;

	UPROPERTY(BlueprintAssignable)
	FStoryProDelegate OnInitComplete;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AAppPro* AppPro;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APartyPro* PartyPro;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStory* Story;

	void LoadStory(UStory* InStory);	

	//~=============================================================================
	// Level Steaming

	/** AppMode does centralized handeling of all Level Streaming. */

	/** Address of pending Area stored during asynchronous loading. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress PendingAreaAddress;

	/** Current Area Address for debugging. */
	FAreaAddress AreaAddress;

	/** Current active Area. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArea* Area;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Change Area"))
	void DoChangeArea(FAreaAddress NextArea);

	UFUNCTION()
	void AreaUnloaded();

	UFUNCTION()
	void LoadNextArea();

	TArray<ACompanionActor*> GetPartyActors();

	UFUNCTION()
	void BufferPartyComplete();

	TArray<FSoftObjectPath> GetSoftClasses();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<APartyPro> PartyProClass = NULL;

//Input
public: 

	void RouteBT(UInputButtonEvent* BT) {};
	void RouteAX(UInputButtonEvent* AX) {};
	void RouteEV(UInputButtonEvent* EV) {};

};
