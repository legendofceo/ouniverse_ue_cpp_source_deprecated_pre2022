//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriMenuP;

class UWriData;
class FocusUiRackC;

class AtlasLibC;

class WriDataSearchP;
class WriDataEditP;

class FocusUiC;
class FocusDockC;
class FocusRackC;

class FormDataC;

class OUNIVERSE_API WriDataP : public ProtocolC, public InputC
{

public: 

	WriDataP(int InID, WriMenuP* InPro, AtlasLibC* InAtlasLi);

	UWriData* View_;

	WriMenuP* Pro_;

	AtlasLibC* AtlasLib_;

	WriDataSearchP* WriDataSearch0_;
	WriDataSearchP* WriDataSearch1_;
	WriDataSearchP* WriDataSearch2_;

	WriDataEditP* WriDataEdit_;

	FocusRackC* FocusRack_;
	FocusDockC* FocusSearchDock_;
	FocusDockC* FocusEditDock_;
	

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriData* InView);

	bool InputCommand(KeyS InKey) override;

	WriDataSearchP* ActiveSearchView_;
	void ChangeSearchView(int Index);

	void OpenData(FormDataC* FormData_);

	static enum Dock {
		DSearch,
		DEdit,
	};

	static enum Pro {
		PDataSearch0,
		PDataSearch1,
		PDataSearch2,
		PDataEdit,
	};

	static enum Focus {
		FSearch,
		FEdit,
		FRack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;


};