// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/Pro.h"


ProDockS::ProDockS()
{
	Pending_ = NULL;
	Active_ = NULL;
}

void ProDockS::Go(UPro* InPro)
{
	Pending_ = InPro;

	if (Active_ == NULL)
	{
		Active_ = Pending_;
		Pending_ = NULL;
		Active_->OpenPro(this);
	}
}