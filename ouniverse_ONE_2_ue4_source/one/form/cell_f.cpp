// Fill out your copyright notice in the Description page of Project Settings.

#include "Cell_f.h"

int Cell_F::FromJson(JsonS* J, FLogger* Log)
{	
	MapLink.FromJson(this,J, DataKeys::Cell::Map);
	return DataReport_D::Approved;
}

JsonS* Cell_F::ToJson(JsonS* J)
{
	Form_F::ToJson(J);
	J->Add(DataKeys::Cell::Map, MapLink.ToString());
	return J;
}