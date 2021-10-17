//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class AtlasLibC;
class AtlasC;
class WriLoadoutC;

class WriMenuP;
class WriterPro;
class UWriFile;

class FocusUiC;
class FocusUiRackC;

class OUNIVERSE_API WriFileP : public ProtocolC, public InputC
{

public: 

	WriFileP(int InID, WriMenuP* InPro, WriterPro* InWriPro, WriLoadoutC* InWriData, AtlasLibC* InAtlasLib);

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(UWriFile* InView);

	bool InputCommand(KeyS InKey) override;
	

	static enum Focus {
		FRack,
		FScroller,
		FLoad,
		FOCUS_MAX,
	};
	
	void AcceptLoad();
	void AcceptNew();
	
private:

	UWriFile* View_;
	WriMenuP* Pro_;
	WriterPro* WriPro_;

	AtlasLibC* AtlasLib_;
	WriLoadoutC* WriData_;

	FocusUiRackC* FRack_;
	FocusUiC* FScroller_;
};