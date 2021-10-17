// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlUE.h"
#include "Stroke.h"
#include "Exec.h"

#define PYLON(FUNC,PUSH)FUNC(GetInputAction(PUSH));


AControlUE::AControlUE()
{
	//PlayerCameraManagerClass = ACameraManagerUE::StaticClass();
}


void AControlUE::Init(UExec* InExec)
{
	LastInputSource_ = 0;
	Exec_ = InExec;

	ForwardsPressed_ = false;
	BackwardsPressed_ = false;
	LeftPressed_ = false;
	RightPressed_ = false;

	CTR_ = false;
	ALT_ = false;
	SHIFT_ = false;
	HELP_ = false;

	InputComponent->BindKey(FKey("Gamepad_Special_Right"), IE_Pressed, this, &AControlUE::JOY_StartD);
	InputComponent->BindKey(FKey("Gamepad_Special_Right"), IE_Released, this, &AControlUE::JOY_StartU);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Up"), IE_Pressed, this, &AControlUE::JOY_LookUD);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Up"), IE_Released, this, &AControlUE::JOY_LookUU);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Down"), IE_Pressed, this, &AControlUE::JOY_LookDD);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Down"), IE_Released, this, &AControlUE::JOY_LookDU);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Left"), IE_Pressed, this, &AControlUE::JOY_LookLD);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Left"), IE_Released, this, &AControlUE::JOY_LookLU);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Right"), IE_Pressed, this, &AControlUE::JOY_LookRD);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Right"), IE_Released, this, &AControlUE::JOY_LookRU);



	InputComponent->BindKey(FKey("Gamepad_LeftStick_Up"), IE_Pressed, this, &AControlUE::JOY_MoveUD);
	InputComponent->BindKey(FKey("Gamepad_LeftStick_Up"), IE_Released, this, &AControlUE::JOY_MoveUU);

	InputComponent->BindKey(FKey("Gamepad_LeftStick_Down"), IE_Pressed, this, &AControlUE::JOY_MoveDD);
	InputComponent->BindKey(FKey("Gamepad_LeftStick_Down"), IE_Released, this, &AControlUE::JOY_LookDU);

	InputComponent->BindKey(FKey("Gamepad_LeftStick_Left"), IE_Pressed, this, &AControlUE::JOY_MoveLD);
	InputComponent->BindKey(FKey("Gamepad_LeftStick_Left"), IE_Released, this, &AControlUE::JOY_MoveLU);

	InputComponent->BindKey(FKey("Gamepad_LeftStick_Right"), IE_Pressed, this, &AControlUE::JOY_MoveRD);
	InputComponent->BindKey(FKey("Gamepad_LeftStick_Right"), IE_Released, this, &AControlUE::JOY_MoveRU);


	InputComponent->BindKey(FKey("Gamepad_DPad_Up"), IE_Pressed, this, &AControlUE::JOY_MoveUD);
	InputComponent->BindKey(FKey("Gamepad_DPad_Up"), IE_Released, this, &AControlUE::JOY_MoveUU);

	InputComponent->BindKey(FKey("Gamepad_DPad_Down"), IE_Pressed, this, &AControlUE::JOY_MoveDD);
	InputComponent->BindKey(FKey("Gamepad_DPad_Down"), IE_Released, this, &AControlUE::JOY_LookDU);

	InputComponent->BindKey(FKey("Gamepad_DPad_Left"), IE_Pressed, this, &AControlUE::JOY_MoveLD);
	InputComponent->BindKey(FKey("Gamepad_DPad_Left"), IE_Released, this, &AControlUE::JOY_MoveLU);

	InputComponent->BindKey(FKey("Gamepad_DPad_Right"), IE_Pressed, this, &AControlUE::JOY_MoveRD);
	InputComponent->BindKey(FKey("Gamepad_DPad_Right"), IE_Released, this, &AControlUE::JOY_MoveRU);


	InputComponent->BindKey(FKey("Gamepad_FaceButton_Top"), IE_Pressed, this, &AControlUE::JOY_YD);
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Top"), IE_Released, this, &AControlUE::JOY_YU);

	InputComponent->BindKey(FKey("Gamepad_FaceButton_Bottom"), IE_Pressed, this, &AControlUE::JOY_AD);
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Bottom"), IE_Released, this, &AControlUE::JOY_AU);
	
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Left"), IE_Pressed, this, &AControlUE::JOY_XD);
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Left"), IE_Released, this, &AControlUE::JOY_XU);

	InputComponent->BindKey(FKey("Gamepad_FaceButton_Right"), IE_Pressed, this, &AControlUE::JOY_BD);
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Right"), IE_Released, this, &AControlUE::JOY_BU);

	InputComponent->BindKey(FKey("W"), IE_Pressed, this, &AControlUE::MAK_MoveUD);
	InputComponent->BindKey(FKey("W"), IE_Released, this, &AControlUE::MAK_MoveUU);

	InputComponent->BindKey(FKey("S"), IE_Pressed, this, &AControlUE::MAK_MoveDD);
	InputComponent->BindKey(FKey("S"), IE_Released, this, &AControlUE::MAK_MoveDU);

	InputComponent->BindKey(FKey("A"), IE_Pressed, this, &AControlUE::MAK_MoveLD);
	InputComponent->BindKey(FKey("A"), IE_Released, this, &AControlUE::MAK_MoveLU);
	
	InputComponent->BindKey(FKey("D"), IE_Pressed, this, &AControlUE::MAK_MoveRD);
	InputComponent->BindKey(FKey("D"), IE_Released, this, &AControlUE::MAK_MoveRU);

	InputComponent->BindKey(FKey("Up"), IE_Pressed, this, &AControlUE::MAK_DirUD);
	InputComponent->BindKey(FKey("Up"), IE_Released, this, &AControlUE::MAK_DirUU);

	InputComponent->BindKey(FKey("Down"), IE_Pressed, this, &AControlUE::MAK_DirDD);
	InputComponent->BindKey(FKey("Down"), IE_Released, this, &AControlUE::MAK_DirDU);

	InputComponent->BindKey(FKey("Left"), IE_Pressed, this, &AControlUE::MAK_DirLD);
	InputComponent->BindKey(FKey("Left"), IE_Released, this, &AControlUE::MAK_DirLU);

	InputComponent->BindKey(FKey("Right"), IE_Pressed, this, &AControlUE::MAK_DirRD);
	InputComponent->BindKey(FKey("Right"), IE_Released, this, &AControlUE::MAK_DirRU);


	InputComponent->BindKey(FKey("SpaceBar"), IE_Pressed, this, &AControlUE::MAK_SpaceD);
	InputComponent->BindKey(FKey("SpaceBar"), IE_Released, this, &AControlUE::MAK_SpaceU);

	InputComponent->BindKey(FKey("Enter"), IE_Pressed, this, &AControlUE::MAK_EnterD);
	InputComponent->BindKey(FKey("Enter"), IE_Released, this, &AControlUE::MAK_EnterU);

	/**
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Bottom"), IE_Pressed, this, &AControlUE::GPAD_A_D);
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Right"), IE_Pressed, this, &AControlUE::GPAD_B_D);

	InputComponent->BindKey(FKey("Home"), IE_Pressed, this, &AControlUE::Stroke_Console_D);
	InputComponent->BindKey(FKey("Home"), IE_Released, this, &AControlUE::Stroke_Console_U);

	InputComponent->BindKey(FKey("one"), IE_Pressed, this, &AControlUE::Test);
	InputComponent->BindKey(FKey("one"), IE_Released, this, &AControlUE::Test);

	InputComponent->BindKey(FKey("F"), IE_Pressed, this, &AControlUE::Interact_D);
	InputComponent->BindKey(FKey("F"), IE_Released, this, &AControlUE::Interact_U);


	InputComponent->BindKey(FKey("W"), IE_Pressed, this, &AControlUE::KB_LUP_D);
	InputComponent->BindKey(FKey("W"), IE_Released, this, &AControlUE::KB_LUP_U);

	InputComponent->BindKey(FKey("S"), IE_Pressed, this, &AControlUE::StrokeID_Down_D);
	InputComponent->BindKey(FKey("S"), IE_Released, this, &AControlUE::StrokeID_Down_U);

	InputComponent->BindKey(FKey("A"), IE_Pressed, this, &AControlUE::StrokeID_Left_D);
	InputComponent->BindKey(FKey("A"), IE_Released, this, &AControlUE::StrokeID_Left_U);

	InputComponent->BindKey(FKey("D"), IE_Pressed, this, &AControlUE::StrokeID_Right_D);
	InputComponent->BindKey(FKey("D"), IE_Released, this, &AControlUE::StrokeID_Right_U);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Up"), IE_Pressed, this, &AControlUE::JOY_Up_D);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Up"), IE_Released, this, &AControlUE::JOY_Up_U);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Down"), IE_Pressed, this, &AControlUE::JOY_Down_D);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Down"), IE_Released, this, &AControlUE::JOY_Down_U);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Left"), IE_Pressed, this, &AControlUE::JOY_Left_D);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Left"), IE_Released, this, &AControlUE::JOY_Left_U);

	InputComponent->BindKey(FKey("Gamepad_RightStick_Right"), IE_Pressed, this, &AControlUE::JOY_Right_D);
	InputComponent->BindKey(FKey("Gamepad_RightStick_Right"), IE_Released, this, &AControlUE::JOY_Right_U);

	InputComponent->BindKey(FKey("F1"), IE_Pressed, this, &AControlUE::Member1);
	InputComponent->BindKey(FKey("F2"), IE_Pressed, this, &AControlUE::Member2);
	InputComponent->BindKey(FKey("F3"), IE_Pressed, this, &AControlUE::Member3);

	InputComponent->BindKey(FKey("Enter"), IE_Pressed, this, &AControlUE::StrokeID_Accept_D);

	InputComponent->BindAxisKey(FKey("MouseY"), this, &AControlUE::AxisRX);
	InputComponent->BindAxisKey(FKey("MouseX"), this, &AControlUE::AxisRY);

	InputComponent->BindKey(FKey("LeftMouseButton"), IE_Pressed, this, &AControlUE::MouseL_D);
	InputComponent->BindKey(FKey("LeftMouseButton"), IE_Released, this, &AControlUE::MouseL_U);
	InputComponent->BindKey(FKey("RightMouseButton"), IE_Pressed, this, &AControlUE::MouseR_D);
	InputComponent->BindKey(FKey("RightMouseButton"), IE_Released, this, &AControlUE::MouseR_U);
	InputComponent->BindKey(FKey("MiddleMouseButton"), IE_Pressed, this, &AControlUE::MouseM_D);
	InputComponent->BindKey(FKey("MiddleMouseButton"), IE_Released, this, &AControlUE::MouseM_U);
	*/
}



void AControlUE::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("WheelDown", IE_Released, this, &AControlUE::Wheel_D);
	InputComponent->BindAction("WheelUp", IE_Released, this, &AControlUE::Wheel_U);

}

void AControlUE::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	float AXIS = 0.0f;

	if (ForwardsPressed_ && BackwardsPressed_)
	{
		AXIS = 0.0f;
	}
	else if (ForwardsPressed_)
	{
		AXIS = 1.0f;
	}
	else if (BackwardsPressed_)
	{
		AXIS = -1.0f;
	}

	//AxisLX(Axis);
	AXIS = 0.0f;

	if (LeftPressed_ && RightPressed_)
	{
		AXIS = 0.0f;
	}
	else if (LeftPressed_)
	{
		AXIS = -1.0f;
	}
	else if (RightPressed_)
	{
		AXIS = 1.0f;
	}

	//AxisLY(Axis);
}


void AControlUE::SetLastInputSource(int InEStrokeSource)
{
	LastInputSource_ = InEStrokeSource;
}

void AControlUE::Test()
{

}





int AControlUE::GetMode()
{
	return ControlMode_;
}

void AControlUE::SendBTN(int InCode, int InSource)
{
	SetLastInputSource(StrokeC::Source::JOY);
	StrokeC* SE = new StrokeC(InCode, InSource, StrokeC::Type::BTN, GetMode());
	Exec_->BTN(SE);
	delete SE;
}

void AControlUE::SendAXIS(int InCode, float InValue, int InSource)
{
	SetLastInputSource(StrokeC::Source::JOY);
	StrokeC* SE = new StrokeC(InCode, InValue, InSource, StrokeC::Type::AXIS, GetMode());
	Exec_->AXIS(SE);
	delete SE;
}















void AControlUE::MAK_MoveUD()
{
	SendBTN(StrokeC::Code::MAK_MoveUD, StrokeC::Source::MAK);
}
void AControlUE::MAK_MoveUU()
{
	SendBTN(StrokeC::Code::MAK_MoveUU, StrokeC::Source::MAK);
}

void AControlUE::MAK_MoveDD()
{
	SendBTN(StrokeC::Code::MAK_MoveDD, StrokeC::Source::MAK);
}

void AControlUE::MAK_MoveDU()
{
	SendBTN(StrokeC::Code::MAK_MoveDU, StrokeC::Source::MAK);
}

void AControlUE::MAK_MoveLD()
{
	SendBTN(StrokeC::Code::MAK_MoveLD, StrokeC::Source::MAK);
}
void AControlUE::MAK_MoveLU()
{
	SendBTN(StrokeC::Code::MAK_MoveLU, StrokeC::Source::MAK);
}

void AControlUE::MAK_MoveRD()
{
	SendBTN(StrokeC::Code::MAK_MoveRD, StrokeC::Source::MAK);
}

void AControlUE::MAK_MoveRU()
{
	SendBTN(StrokeC::Code::MAK_MoveRU, StrokeC::Source::MAK);
}


void AControlUE::MAK_DirUD()
{
	SendBTN(StrokeC::Code::MAK_DirUD, StrokeC::Source::MAK);
}
void AControlUE::MAK_DirUU()
{
	SendBTN(StrokeC::Code::MAK_DirUU, StrokeC::Source::MAK);
}

void AControlUE::MAK_DirDD()
{
	SendBTN(StrokeC::Code::MAK_DirDD, StrokeC::Source::MAK);
}

void AControlUE::MAK_DirDU()
{
	SendBTN(StrokeC::Code::MAK_DirDU, StrokeC::Source::MAK);
}

void AControlUE::MAK_DirLD()
{
	SendBTN(StrokeC::Code::MAK_DirLD, StrokeC::Source::MAK);
}
void AControlUE::MAK_DirLU()
{
	SendBTN(StrokeC::Code::MAK_DirLU, StrokeC::Source::MAK);
}

void AControlUE::MAK_DirRD()
{
	SendBTN(StrokeC::Code::MAK_DirRD, StrokeC::Source::MAK);
}

void AControlUE::MAK_DirRU()
{
	SendBTN(StrokeC::Code::MAK_DirRU, StrokeC::Source::MAK);
}

void AControlUE::MAK_EnterD()
{
	SendBTN(StrokeC::Code::MAK_EnterD, StrokeC::Source::MAK);
}

void AControlUE::MAK_EnterU()
{
	SendBTN(StrokeC::Code::MAK_EnterU, StrokeC::Source::MAK);
}

void AControlUE::MAK_SpaceD()
{
	SendBTN(StrokeC::Code::MAK_SpaceBarD, StrokeC::Source::MAK);
}

void AControlUE::MAK_SpaceU()
{
	SendBTN(StrokeC::Code::MAK_SpaceBarU, StrokeC::Source::MAK);
}

//JOYLOOK

void AControlUE::JOY_LookUD() 
{	
	SendBTN(StrokeC::Code::JOY_LookUD, StrokeC::Source::JOY);
}

void AControlUE::JOY_LookUU()
{
	SendBTN(StrokeC::Code::JOY_LookUU, StrokeC::Source::JOY);
}

void AControlUE::JOY_LookDD()
{
	SendBTN(StrokeC::Code::JOY_LookDD, StrokeC::Source::JOY);
}

void AControlUE::JOY_LookDU()
{
	SendBTN(StrokeC::Code::JOY_LookDU, StrokeC::Source::JOY);
}

void AControlUE::JOY_LookLD()
{
	SendBTN(StrokeC::Code::JOY_LookLD, StrokeC::Source::JOY);
}
void AControlUE::JOY_LookLU()
{
	SendBTN(StrokeC::Code::JOY_LookLU, StrokeC::Source::JOY);
}

void AControlUE::JOY_LookRD()
{
	SendBTN(StrokeC::Code::JOY_LookRD, StrokeC::Source::JOY);
}

void AControlUE::JOY_LookRU()
{
	SendBTN(StrokeC::Code::JOY_LookRU, StrokeC::Source::JOY);
}

//JOYMOVE

void AControlUE::JOY_MoveUD()
{
	SendBTN(StrokeC::Code::JOY_MoveUD, StrokeC::Source::JOY);
}

void AControlUE::JOY_MoveUU()
{
	SendBTN(StrokeC::Code::JOY_MoveUU, StrokeC::Source::JOY);
}

void AControlUE::JOY_MoveDD()
{
	SendBTN(StrokeC::Code::JOY_MoveDD, StrokeC::Source::JOY);
}

void AControlUE::JOY_MoveDU()
{
	SendBTN(StrokeC::Code::JOY_MoveDU, StrokeC::Source::JOY);
}

void AControlUE::JOY_MoveLD()
{
	SendBTN(StrokeC::Code::JOY_MoveLD, StrokeC::Source::JOY);
}
void AControlUE::JOY_MoveLU()
{
	SendBTN(StrokeC::Code::JOY_MoveLU, StrokeC::Source::JOY);
}

void AControlUE::JOY_MoveRD()
{
	SendBTN(StrokeC::Code::JOY_MoveRD, StrokeC::Source::JOY);
}

void AControlUE::JOY_MoveRU()
{
	SendBTN(StrokeC::Code::JOY_MoveRU, StrokeC::Source::JOY);
}

//JOYDIR

void AControlUE::JOY_DirUD()
{
	SendBTN(StrokeC::Code::JOY_DirUD, StrokeC::Source::JOY);
}

void AControlUE::JOY_DirUU()
{
	SendBTN(StrokeC::Code::JOY_DirUU, StrokeC::Source::JOY);
}

void AControlUE::JOY_DirDD()
{
	SendBTN(StrokeC::Code::JOY_DirDD, StrokeC::Source::JOY);
}

void AControlUE::JOY_DirDU()
{
	SendBTN(StrokeC::Code::JOY_DirDU, StrokeC::Source::JOY);
}

void AControlUE::JOY_DirLD()
{
	SendBTN(StrokeC::Code::JOY_DirLD, StrokeC::Source::JOY);
}
void AControlUE::JOY_DirLU()
{
	SendBTN(StrokeC::Code::JOY_DirLU, StrokeC::Source::JOY);
}

void AControlUE::JOY_DirRD()
{
	SendBTN(StrokeC::Code::JOY_DirRD, StrokeC::Source::JOY);
}

void AControlUE::JOY_DirRU()
{
	SendBTN(StrokeC::Code::JOY_DirRU, StrokeC::Source::JOY);
}

//JOYBT

void AControlUE::JOY_YD()
{
	SendBTN(StrokeC::Code::JOY_YD, StrokeC::Source::JOY);
}

void AControlUE::JOY_YU()
{
	SendBTN(StrokeC::Code::JOY_YU, StrokeC::Source::JOY);
}

void AControlUE::JOY_AD()
{
	SendBTN(StrokeC::Code::JOY_AD, StrokeC::Source::JOY);
}

void AControlUE::JOY_AU()
{
	SendBTN(StrokeC::Code::JOY_AU, StrokeC::Source::JOY);
}

void AControlUE::JOY_XD()
{
	SendBTN(StrokeC::Code::JOY_XD, StrokeC::Source::JOY);
}

void AControlUE::JOY_XU()
{
	SendBTN(StrokeC::Code::JOY_XU, StrokeC::Source::JOY);
}

void AControlUE::JOY_BD()
{
	SendBTN(StrokeC::Code::JOY_BD, StrokeC::Source::JOY);
}

void AControlUE::JOY_BU()
{
	SendBTN(StrokeC::Code::JOY_BU, StrokeC::Source::JOY);
}


void AControlUE::JOY_StartD()
{
	SendBTN(StrokeC::Code::JOY_StartD, StrokeC::Source::JOY);
}

void AControlUE::JOY_StartU()
{
	SendBTN(StrokeC::Code::JOY_StartU, StrokeC::Source::JOY);
}

//JOYTOP





















void AControlUE::KB_LUP_D()
{
	ForwardsPressed_ = true;
	SetLastInputSource(StrokeC::Source::MAK);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("UP"));
	//Maestro_->InputCommand(KeyS(InputID::Up_D, EStrokeSource::Keyboard));
}

void AControlUE::KB_LUP_U()
{
	ForwardsPressed_ = false;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Up_U, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Down_D()
{
	BackwardsPressed_ = true;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Down_D, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Down_U()
{
	BackwardsPressed_ = false;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Down_U, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Left_D()
{
	LeftPressed_ = true;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Left_D, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Left_U()
{
	LeftPressed_ = false;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Left_U, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Right_D()
{
	RightPressed_ = true;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Right_D, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Right_U()
{
	RightPressed_ = false;
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Right_U, EStrokeSource::Keyboard));
}



void AControlUE::JOY_Down_D()
{
	SetLastInputSource(StrokeC::Source::JOY);
	//Maestro_->InputCommand(KeyS(InputID::Down_D, EStrokeSource::Controller));
}

void AControlUE::JOY_Down_U()
{
	SetLastInputSource(StrokeC::Source::JOY);
	//Maestro_->InputCommand(KeyS(InputID::Down_U, EStrokeSource::Controller));
}

void AControlUE::JOY_Left_D()
{
	SetLastInputSource(StrokeC::Source::JOY);
	//Maestro_->InputCommand(KeyS(InputID::Left_D, EStrokeSource::Controller));
}

void AControlUE::JOY_Left_U()
{
	SetLastInputSource(StrokeC::Source::JOY);
	//Maestro_->InputCommand(KeyS(InputID::Left_U, EStrokeSource::Controller));
}

void AControlUE::JOY_Right_D()
{
	SetLastInputSource(StrokeC::Source::JOY);
	//Maestro_->InputCommand(KeyS(InputID::Right_D, EStrokeSource::Controller));
}

void AControlUE::JOY_Right_U()
{
	SetLastInputSource(StrokeC::Source::JOY);
	//Exec_->StrokeCTR(FStroke(EStrokeID::StrokeID_Right_U, EStrokeSource::EStrokeSourceController));
}


void AControlUE::StrokeID_Accept_D()
{
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Accept_D, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Accept_U()
{
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Accept_U, EStrokeSource::Keyboard));
}

void AControlUE::StrokeID_Cancel_D()
{
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Cancel_D, EStrokeSource::Keyboard));
}

void AControlUE::EStrokeID_Cancel_U()
{
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Cancel_U, EStrokeSource::Keyboard));
}

void AControlUE::Stroke_Console_D()
{
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Console_D, EStrokeSource::Keyboard));
}

void AControlUE::Stroke_Console_U()
{
	SetLastInputSource(StrokeC::Source::MAK);
	//Maestro_->InputCommand(KeyS(InputID::Console_U, EStrokeSource::Keyboard));
}

void AControlUE::Wheel_D()
{
	//Maestro_->WheelDown(true);
}

void AControlUE::Wheel_U()
{
	//Maestro_->WheelUp(true);
}

void AControlUE::Interact_D()
{
	//Maestro_->Interact(true);
}

void AControlUE::Interact_U()
{
	//Maestro_->Interact(false);
}

void AControlUE::Member1()
{

}

void AControlUE::Member2()
{

}

void AControlUE::Member3()
{

}

void AControlUE::AxisLX(float AxisValue) {	}
void AControlUE::AxisLY(float AxisValue) {	}
void AControlUE::AxisRX(float AxisValue) {	}
void AControlUE::AxisRY(float AxisValue) {	}


void AControlUE::MouseL_D()
{
	//Maestro_->MouseL(true);
}

void AControlUE::MouseL_U()
{
	//Maestro_->MouseL(false);
}

void AControlUE::MouseR_D()
{
	//Maestro_->MouseR(true);
}

void AControlUE::MouseR_U()
{
	//Maestro_->MouseL(false);
}

void AControlUE::MouseM_D()
{
	//Maestro_->MouseM(true);
}

void AControlUE::MouseM_U()
{
	//Maestro_->MouseM(false);
}
