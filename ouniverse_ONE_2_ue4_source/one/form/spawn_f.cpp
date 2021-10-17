// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawn_f.h"

int Spawn_F::FromJson(JsonS* J, UAtlas* Atlas, FLogger* Log)
{
	Position = FVector(0.0, 0.0, 0.0);
	Rotation = FRotator(0.0, 0.0,0.0);
	Scale = FVector(1.0, 1.0, 1.0);
	
	J->TryInt(UID,DataKeys::UniversalNumber);
	int AtlasFA;
	int FormFA;
	
	
	JsonS JD;
	if(J->Try(JD,DataKeys::DataAddress))
	{
		AtlasFA = JD[0].Int();
		FormFA = JD[1].Int();
		DataAddress = FDataAddress(J->Key(DataKeys::DataAddress)[0].Int(), J->Key(DataKeys::DataAddress)[1].Int());
	}
	

	if(J->Has(DataKeys::XForm::Position))
	{
		JsonS PosJ = J->Key(DataKeys::XForm::Position);
		Position = FVector(PosJ[0].Float(), PosJ[1].Float(), PosJ[2].Float());
	}
	if(J->Has(DataKeys::XForm::Rotation))
	{
		if (J->IsNumber(DataKeys::XForm::Rotation))
		{
			float RotVal = J->Key(DataKeys::XForm::Rotation).Float();
			Rotation = FRotator(RotVal, 0, 0);
		}
		else
		{
			JsonS RotJ = J->Key(DataKeys::XForm::Rotation);
			Rotation = FRotator(RotJ[0].Float(), RotJ[1].Float(), RotJ[2].Float());
		}
	}
	if (J->Has(DataKeys::XForm::Scale))
	{
		if (J->IsNumber(DataKeys::XForm::Scale))
		{
			float ScaleVal = J->Key(DataKeys::XForm::Scale).Float();
			Scale = FVector(ScaleVal, ScaleVal, ScaleVal);
		}
		else
		{
			JsonS ScaleJ = J->Key(DataKeys::XForm::Scale);
			Scale = FVector(ScaleJ[0].Float(), ScaleJ[1].Float(), ScaleJ[2].Float());
		}
	}
	else
	{
		Scale = FVector(1.0, 1.0, 1.0);
	}

	return DataReport_D::Approved;
}

JsonS Spawn_F::ToJson()
{
	JsonS J = JsonS();
	ArrayC<JsonS> PosArr;
	PosArr.Add(Position.X);
	PosArr.Add(Position.Y);
	PosArr.Add(Position.Z);
	ArrayC<JsonS> RotArr;
	RotArr.Add(Rotation.Pitch);
	RotArr.Add(Rotation.Yaw);
	RotArr.Add(Rotation.Roll);
	ArrayC<JsonS> ScaleArr;
	ScaleArr.Add(Scale.X);
	ScaleArr.Add(Scale.Y);
	ScaleArr.Add(Scale.Z);

	J.Add(DataKeys::XForm::Position, PosArr);
	J.Add(DataKeys::XForm::Rotation, RotArr);
	J.Add(DataKeys::XForm::Scale, ScaleArr);
	
	return J;
}