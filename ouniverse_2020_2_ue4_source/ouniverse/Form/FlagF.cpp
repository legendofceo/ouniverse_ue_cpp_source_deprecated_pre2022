//Copyright 2015-2019, All Rights Reserved.

#include "Form/FlagF.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int FlagF::Type()
{
	return FormTypesC::Types::Area;
}


FlagF::FlagF()
{

}

FormF* FlagF::Create(JsonS& InJ)
{
	FormF* Obj = new FlagF();
	Obj->Setup(InJ);
	return Obj;
}

void FlagF::Demarshal()
{
	FormF::Demarshal();
}
