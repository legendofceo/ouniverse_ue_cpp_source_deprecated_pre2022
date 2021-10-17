// Fill out your copyright notice in the Description page of Project Settings.


#include "Stroke.h"

bool StrokeC::ToCodeLite()
{
	switch (Code_) {
	case StrokeC::Code::MAK_MoveUD:
		Code_ = CodeLite::Up;
		break;
	case StrokeC::Code::MAK_DirUD:
		Code_ = CodeLite::Up;
		break;
	case StrokeC::Code::JOY_LookUD:
		Code_ = CodeLite::Up;
		break;
	case StrokeC::Code::JOY_DirUD:
		Code_ = CodeLite::Up;
		break;
	case StrokeC::Code::JOY_MoveUD:
		Code_ = CodeLite::Up;
		break;
	case StrokeC::Code::MAK_MoveDD:
		Code_ = CodeLite::Down;
		break;
	case StrokeC::Code::MAK_DirDD:
		Code_ = CodeLite::Down;
		break;
	case StrokeC::Code::JOY_LookDD:
		Code_ = CodeLite::Down;
		break;
	case StrokeC::Code::JOY_DirDD:
		Code_ = CodeLite::Down;
		break;
	case StrokeC::Code::JOY_MoveDD:
		Code_ = CodeLite::Down;
		break;
	case StrokeC::Code::JOY_AD:
		Code_ = CodeLite::Accept;
		break;
	case StrokeC::Code::MAK_EnterD:
		Code_ = CodeLite::Accept;
		break;
	default:
		return false;
	}

	return true;
	
}