//Copyright 2015-2019, All Rights Reserved.

/**
Object Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class ObjF : public FormF
{

public:

	ObjF();
	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

};