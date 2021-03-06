//Copyright 2015-2019, All Rights Reserved.

#include "System/FormQuery.h"
#include "Form/FormF.h"


bool FormQueryBooleanS::Valid(FormWrapS InForm)
{
	return false;
}

FormQueryBooleanS::~FormQueryBooleanS()
{

}

FQB_ID_CaseInsensitiveS::FQB_ID_CaseInsensitiveS(StringC InQueryID)
{
	QueryID_ = InQueryID.ToLower();
}

bool FQB_ID_CaseInsensitiveS::Valid(FormWrapS InForm)
{
	
	if (InForm.Form()->ID().ToLower().Contains(QueryID_))
	{
		return true;
	}
	
	return false;

}


FormQueryS::FormQueryS(StringC InQuery, ArrayC<FormWrapS>* InFormArr)
{

	ValidForms_ = InFormArr;

	BooleanLen_ = 0;

	if (InQuery != "")
	{
		FQB_ID_CaseInsensitiveS* Check = new FQB_ID_CaseInsensitiveS(InQuery);
		AddBoolean(Check);
	}
}

FormQueryS::~FormQueryS()
{

		for (int i = 0; i < BooleanLen(); i++)
		{
			delete Booleans_[i];
		}
}


void FormQueryS::AddBoolean(FormQueryBooleanS* InBoolean)
{
	BooleanLen_++;
	Booleans_.Add(InBoolean);
}

int FormQueryS::BooleanLen()
{
	return BooleanLen_;
}
void FormQueryS::Scan(FormWrapS InForm)
{

	bool isValid = true;
	for (int i = 0; i < BooleanLen(); i++)
	{
		if (!Booleans_[i]->Valid(InForm))
		{
			isValid = false;
			break;
		}
	}

	if (isValid)
	{
		ValidForms_->Add(InForm);
	}
}