//Copyright 2015-2019, All Rights Reserved.

/**

## Data
> **Singleton Service: Created once only by the boot process.**

Data is a singleton which loads all the atlas style game data.

#### Tasks
* Creates and triggers a PayloadC which unpacks the entire atlas folder.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "System/DuetUID.h"

class FormF;

class OUNIVERSE_API DataC
{

public:

	DataC(int Atlas, int Form);
	DataC(DuetUID InDuet);

	bool Found();
	FormF* Form();
	int Error();

private:

	bool Found_;
	FormF* Form_;
	int Error_;
};