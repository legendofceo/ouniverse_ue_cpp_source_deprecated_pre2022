// Fill out your copyright notice in the Description page of Project Settings.


#include "App/DataPack.h"
#include "Interface/String.h"

#include "Interface/Json.h"

#include "Data/DataD.h"

#include <sstream>
#include <fstream>
#include <string>


DataPackC::DataPackC(const char* InPath)
{
	std::stringstream sstr;

	std::ifstream ifs(InPath);

	if (!ifs.is_open()) {

		return;
	}

	sstr << ifs.rdbuf();

	JsonS J = JsonS(StringC(sstr.str()));

	I_ = J.String("i");
	U_ = J.Int("u");

	
	JsonS Datra = J.Key("d");
	
	int L = Datra.Len();
	
	DataD* Neu;

	for(int i=0;i<L;i++)
	{
		Neu = new DataD();
		JsonS DataPTR = Datra.At(i);
		Neu->Load(&DataPTR);
		Lib_.Add(Neu->U(),Neu);
	}

	ifs.close();
}

int DataPackC::U()
{
	return U_;
}


StringC DataPackC::I()
{
	return I_;
}