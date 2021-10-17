// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
Mouse and Keyboard (MAK)
Controller (JOY)
*/

class StrokeC
{

public:

	StrokeC(int InCode, int InSource, int InType, int InMode)
	{
		Source_ = InSource;
		Type_ = InType;
		Mode_ = InMode;
		Code_ = InCode;

		Value_ = 0.0f;
		Handled_ = false;
	};

	StrokeC(int InCode, float InValue, int InSource, int InType, int InMode)
	{
		Source_ = InSource;
		Type_ = InType;
		Mode_ = InMode;
		Code_ = InCode;

		Value_ = InValue;
		Handled_ = false;
	};

	enum Source
	{
		SOURCE_NULL,
		MAK,
		JOY,
		ORT,
		SIM,
		SOURCE_MAX,
	};

	enum Type
	{
		TYPE_NULL,
		BTN,
		AXIS,
		TYPE_MAX,
	};

	enum Mode
	{
		MODE_NULL,
		MODE_MAK,
		MODE_JOY,
		MODE_MAX,
	};


	enum Code
	{
		CODE_NULL,
		MAK_MoveUD,
		MAK_MoveUU,
		MAK_MoveDD,
		MAK_MoveDU,
		MAK_MoveLD,
		MAK_MoveLU,
		MAK_MoveRD,
		MAK_MoveRU,

		MAK_DirUD,
		MAK_DirUU,
		MAK_DirDD,
		MAK_DirDU,
		MAK_DirLD,
		MAK_DirLU,
		MAK_DirRD,
		MAK_DirRU,

		MAK_SpaceBarD,
		MAK_SpaceBarU,

		MAK_EnterD,
		MAK_EnterU,

		JOY_LookUD,
		JOY_LookUU,
		JOY_LookDD,
		JOY_LookDU,
		JOY_LookLD,
		JOY_LookLU,
		JOY_LookRD,
		JOY_LookRU,

		JOY_MoveUD,
		JOY_MoveUU,
		JOY_MoveDD,
		JOY_MoveDU,
		JOY_MoveLD,
		JOY_MoveLU,
		JOY_MoveRD,
		JOY_MoveRU,

		JOY_DirUD,
		JOY_DirUU,
		JOY_DirDD,
		JOY_DirDU,
		JOY_DirLD,
		JOY_DirLU,
		JOY_DirRD,
		JOY_DirRU,

		JOY_YD,
		JOY_YU,

		JOY_AD,
		JOY_AU,

		JOY_XD,
		JOY_XU,

		JOY_BD,
		JOY_BU,

		JOY_StartD,
		JOY_StartU,

		CODE_MAX,
	};

	enum CodeLite
	{
		CODEJR_NULL,
		Up,
		Down,
		Left,
		Right,
		Accept,
		Cancel,
		Tog,
		Opt,
		TabR,
		TabL,
		CODEJR_MAX
	};

	int GetSource() { return Source_; };
	int GetType() { return Type_; };
	int GetCode() { return Code_; };
	int GetMode() { return Mode_; };
	float GetValue() { return Value_; };
	bool IsUnhandled() { return !Handled_; };

	bool ToCodeLite();

private:

	int Source_;
	int Type_;
	int Code_;
	int Mode_;

	float Value_;
	bool Handled_;


};