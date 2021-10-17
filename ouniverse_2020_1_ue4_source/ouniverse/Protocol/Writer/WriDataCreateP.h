//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriDataP;

class UWriData;
class FocusUiRackC;

class AtlasLibC;

class OUNIVERSE_API WriDataCreateP : public ProtocolC, public InputC
{

public: 

	WriDataCreateP(int InID, WriDataP* InPro);

	UWriDataCreate* View_;

	WriDataP* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriDataCreate* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;


};