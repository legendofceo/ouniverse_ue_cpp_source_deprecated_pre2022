// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

namespace DataKeys
{
	static const char* const UniversalNumber = "@";
	static const char* const ID = "#";
	static const char* const FormType = "%";
	static const char* const LuaScript = "lu";
	static const char* const DataAddress = "d";
	static const char* const Path = "p";
	
	namespace Actra
	{
		static const char* const FirstName = "fnm";
		static const char* const LastName = "lnm";
		static const char* const Age = "age";
		static const char* const Sex = "sex";
		static const char* const Bodyshape = "bosh";
		static const char* const Head = "head";
	}
	namespace Area
	{
		static const char* const Cell	= "c";
	}

	namespace Cell
	{
		static const char* const Map = "cem";
	}

	namespace Manifest
	{
		static const char* const Spawns = "mnsp";
	}

	namespace Bodyshape
	{
		static const char* const NudeBust			= "bsnb";
		static const char* const NudeLegs			= "bsnl";
		static const char* const NudeHands			= "bsnh";
		static const char* const NudeFeet			= "bsnf";
	}

	namespace Skeleton
	{
		static const char* const SkeletalMesh = "skskm";
	}

	namespace Fitting
	{
		static const char* const BodyshapeMap	= "bs";
	}

	namespace Wearable
	{
		static const char* const SkeletalMesh = "weskm";
	}

	namespace XForm
	{
		static const char* const Position	= "p";
		static const char* const Rotation	= "r";
		static const char* const Scale		= "s";
	}
}