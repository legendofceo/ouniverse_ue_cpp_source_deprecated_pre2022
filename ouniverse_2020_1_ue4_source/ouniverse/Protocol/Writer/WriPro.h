//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class UUi;
class UMajor;
class MaestroC;

class WriMenuP;
class WriDataLoadP;
class WriSplashP;
class WriLoadoutC;

class UWriPro;

class WriFooterP;

class FluxSwitchOpC;

class DictC;

class OUNIVERSE_API WriterPro : public ProtocolC, public InputStackC
{
	friend MaestroC;

public: 

	static FText Dict(int InID);

	void GoMain();
	void GoDataLoad();
	void EscWriter();


	void DataLoad();
	void DataUnload();


private:

	
	static WriterPro* Create(int InID, UMajor* InMajor);

	WriterPro(int InID, UMajor* InMajor);

	UMajor* Major_;
	MaestroC* Maestro_;
	UUi* Ui_;

	WriMenuP* WriMain_;
	WriDataLoadP* WriDataLoad_;
	WriSplashP* WriSplash_;
	UWriPro* View_;
	WriFooterP* WriFooter_;

	DictC* WriterDict_;
	
	WriLoadoutC* WriData_;

	static enum Focus {
		FOCUS_MAX,
	};

	static enum Dock {
		DWri,
		DOCK_MAX,
	};
	
	static enum Pro {
		PFooter,
		PSplash,
		PDataLoad,
		PMain,
		PRO_MAX,
	};

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void OpenSplash();

};