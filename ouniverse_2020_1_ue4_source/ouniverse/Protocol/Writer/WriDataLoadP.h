//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriterPro;
class WriLoadoutC;

class UWriDataLoad;
class FocusUiRackC;


class OUNIVERSE_API WriDataLoadP : public ProtocolC, public InputC
{

public: 

	WriDataLoadP(int InID, WriterPro* InPro, WriLoadoutC* InWriData);

	UWriDataLoad* View_;

	WriterPro* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriDataLoad* InView);

	static enum Focus {
		FRack,
		FStart,
		FBack,
		FOCUS_MAX,
	};

	WriLoadoutC* WriData_;

	FocusUiRackC* ORack_;

	static void LoadThread(WriLoadoutC* InWriData);

	void LoadingAnimationComplete();

};