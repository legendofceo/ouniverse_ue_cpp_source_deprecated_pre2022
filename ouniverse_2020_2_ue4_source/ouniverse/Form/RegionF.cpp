//Copyright 2015-2019, All Rights Reserved.

#include "Form/RegionF.h"
#include "Form/RegionA.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int RegionF::Type()
{
	return FormTypesC::Types::Region;
}

URegionA* RegionF::CreateActual()
{
	return URegionA::Create(this);
}

RegionF::RegionF()
{

}

FormF* RegionF::Create(JsonS& InJ)
{ 
	FormF* Obj = new RegionF();
	Obj->Setup(InJ);
	return Obj;
}

void RegionF::Demarshal()
{
	FormF::Demarshal();
}
