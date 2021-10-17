// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "ControlUE.generated.h"

class UExec;
class StrokeC;

UCLASS()
class OUNIVERSE_API AControlUE : public APlayerController
{
	GENERATED_BODY()

	virtual void PlayerTick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

public:

	AControlUE();

	void Init(UExec* InExec);

	UExec* Exec_;


	int GetMode();

private:

	void SendBTN(int InCode, int InSource);
	void SendAXIS(int InCode, float InAxis, int InSource);

	int ControlMode_;

public:

	UFUNCTION()
	void JOY_LookUD();
	UFUNCTION()
	void JOY_LookUU();

	UFUNCTION()
	void JOY_LookDD();
	UFUNCTION()
	void JOY_LookDU();

	UFUNCTION()
	void JOY_LookLD();
	UFUNCTION()
	void JOY_LookLU();

	UFUNCTION()
	void JOY_LookRD();
	UFUNCTION()
	void JOY_LookRU();

	UFUNCTION()
	void JOY_MoveUD();
	UFUNCTION()
	void JOY_MoveUU();

	UFUNCTION()
	void JOY_MoveDD();
	UFUNCTION()
	void JOY_MoveDU();

	UFUNCTION()
	void JOY_MoveLD();
	UFUNCTION()
	void JOY_MoveLU();

	UFUNCTION()
	void JOY_MoveRD();
	UFUNCTION()
	void JOY_MoveRU();

	UFUNCTION()
	void JOY_DirUD();
	UFUNCTION()
	void JOY_DirUU();

	UFUNCTION()
	void JOY_DirDD();
	UFUNCTION()
	void JOY_DirDU();

	UFUNCTION()
	void JOY_DirLD();
	UFUNCTION()
	void JOY_DirLU();

	UFUNCTION()
	void JOY_DirRD();
	UFUNCTION()
	void JOY_DirRU();

	UFUNCTION()
	void JOY_YD();
	UFUNCTION()
	void JOY_YU();

	UFUNCTION()
	void JOY_AD();
	UFUNCTION()
	void JOY_AU();

	UFUNCTION()
	void JOY_XD();
	UFUNCTION()
	void JOY_XU();

	UFUNCTION()
	void JOY_BD();
	UFUNCTION()
	void JOY_BU();

	UFUNCTION()
	void JOY_StartD();
	UFUNCTION()
	void JOY_StartU();







	UFUNCTION()
	void MAK_MoveUD();
	UFUNCTION()
	void MAK_MoveUU();

	UFUNCTION()
	void MAK_MoveDD();
	UFUNCTION()
	void MAK_MoveDU();

	UFUNCTION()
	void MAK_MoveLD();
	UFUNCTION()
	void MAK_MoveLU();

	UFUNCTION()
	void MAK_MoveRD();
	UFUNCTION()
	void MAK_MoveRU();

	UFUNCTION()
	void MAK_DirUD();
	UFUNCTION()
	void MAK_DirUU();

	UFUNCTION()
	void MAK_DirDD();
	UFUNCTION()
	void MAK_DirDU();

	UFUNCTION()
	void MAK_DirLD();
	UFUNCTION()
	void MAK_DirLU();

	UFUNCTION()
	void MAK_DirRD();
	UFUNCTION()
	void MAK_DirRU();
	
	UFUNCTION()
	void MAK_SpaceU();
	UFUNCTION()
	void MAK_SpaceD();

	UFUNCTION()
	void MAK_EnterU();
	UFUNCTION()
	void MAK_EnterD();








	UFUNCTION()
	void Test();

	UFUNCTION()
	void Interact_U();

	UFUNCTION()
	void Interact_D();

	UFUNCTION()
	void Member1();

	UFUNCTION()
	void Member2();

	UFUNCTION()
	void Member3();

	UFUNCTION()
	void KB_LUP_D();
	UFUNCTION()
	void KB_LUP_U();

	UFUNCTION()
	void StrokeID_Down_D();
	UFUNCTION()
	void StrokeID_Down_U();

	UFUNCTION()
	void StrokeID_Left_D();
	UFUNCTION()
	void StrokeID_Left_U();

	UFUNCTION()
	void StrokeID_Right_D();
	UFUNCTION()
	void StrokeID_Right_U();




	UFUNCTION()
	void JOY_Down_D();
	UFUNCTION()
	void JOY_Down_U();

	UFUNCTION()
	void JOY_Left_D();
	UFUNCTION()
	void JOY_Left_U();

	UFUNCTION()
	void JOY_Right_D();
	UFUNCTION()
	void JOY_Right_U();


	UFUNCTION()
	void StrokeID_Accept_D();
	UFUNCTION()
	void StrokeID_Accept_U();

	UFUNCTION()
	void StrokeID_Cancel_D();
	UFUNCTION()
	void EStrokeID_Cancel_U();

	UFUNCTION()
	void Wheel_D();
	UFUNCTION()
	void Wheel_U();

	UFUNCTION()
	void AxisLX(float AxisValue);
	UFUNCTION()
	void AxisLY(float AxisValue);

	UFUNCTION()
	void AxisRX(float AxisValue);
	UFUNCTION()
	void AxisRY(float AxisValue);

	UFUNCTION()
	void MouseL_D();
	UFUNCTION()
	void MouseL_U();
	UFUNCTION()
	void MouseR_D();
	UFUNCTION()
	void MouseR_U();
	UFUNCTION()
	void MouseM_D();
	UFUNCTION()
	void MouseM_U();

	UFUNCTION()
	void Stroke_Console_D();
	UFUNCTION()
	void Stroke_Console_U();

private:

	int LastInputSource_;

	void SetLastInputSource(int InInputSource);

	bool CTR_;
	bool ALT_;
	bool SHIFT_;
	bool HELP_;

	bool ForwardsPressed_;
	bool BackwardsPressed_;
	bool LeftPressed_;
	bool RightPressed_;

	bool LeftDown_;
	
	//UPROPERTY()
	//ACameraManagerUE* CameraManager_;

};