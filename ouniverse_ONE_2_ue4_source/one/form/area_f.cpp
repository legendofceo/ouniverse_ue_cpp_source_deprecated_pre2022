// Fill out your copyright notice in the Description page of Project Settings.

#include "Area_F.h"
#include "Cell_F.h"
#include "common/form_link.h"


int Area_F::FromJson(JsonS* J, FLogger* Log)
{
	/**
	FormLinkS<Cell_F*> DataLinker;
	if (!DataLinker.FromJson(DefaultCell, DataKeys::Area::Cell, J, Atlas))
		Log->Write(PrintError("DefaultCell"), ELogStatus::RequiredData);
	*/
	//if (!DefaultCell.FromJson(this, J, DataKeys::Bodyshape::NudeLegs))
	//	Log->Write(PrintError("NudeLegs"), ELogStatus::RequiredData);

	return DataReport_D::Approved;
}

JsonS* Area_F::ToJson(JsonS* J)
{
	Form_F::ToJson(J);
	return J;
}