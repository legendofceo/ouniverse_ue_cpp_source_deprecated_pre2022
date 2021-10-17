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

class FormDataC;

class OUNIVERSE_API WriDataEditP : public ProtocolC, public InputC
{

public: 

	WriDataEditP(int InID, WriDataP* InPro);

	UWriDataEdit* View_;

	WriDataP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriDataEdit* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;

	static enum DataMode {
		Poly,
		Json,
	};


	void OpenData(FormDataC* FormData_);

};