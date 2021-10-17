// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


class StrokeC;

class InputC
{

public:

	InputC() {};

	int InputID;

	virtual void AXIS(StrokeC* InStroke) {};
	virtual void BTN(StrokeC* InStroke) {};
};

/**
class InputArrayC : public InputC
{

public:

	void AXIS(StrokeC* InStroke) override {};
	void KEY(StrokeC* InStroke) override {};

private:

	ArrayC<InputC*> Array_;

};

class InputMapC : public InputC
{

public:

	void AXIS(StrokeC* InStroke) override {};
	void KEY(StrokeC* InStroke) override {};

private:

	MapC<int,InputC*> Map_;

};

class InputSwitchC : public InputC
{
	
public:

	virtual bool Inputlay() {return false;};

	void AXIS(StrokeC* InStroke) override {};
	void KEY(StrokeC* InStroke) override {};

private:

	InputC* Switch_;

};

*/