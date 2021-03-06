//Copyright 2015-2019, All Rights Reserved.

/**

## Dir

**Struct:** DirS

Represents a directory in an OOP sense.

* Allows paths to be passed around and dynamically updated if changed.
* Has a few helper functions for directory management built in.

> Possibly this should be changed to a class.

*/

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"

#include "System/UserUID.h"

class FileC;
class FolderC;
class DocC;
class DocStreamC;


class FolderC
{

public:
	FolderC();
	FolderC(StringC InPath);

	void Make();

	StringC ToString();

	FileC ToFile(StringC File, StringC Ext);
	FolderC ToInsideFolder(StringC InNextFolder);

	StringC GetFinalDir();

	ArrayC<FolderC> GetFolders();
	ArrayC<FileC> GetFiles();
	ArrayC<FileC> GetFiles(StringC InExtension);


protected:

	StringC S_;

};


class FileC
{

public:

	FileC();

	FileC(FolderC InFolder, StringC InFileName, StringC InExtension);

	StringC ToString();

	StringC Name();

	DocC Doc();

	bool Exists();

private:

	FolderC Fo_;
	StringC Fi_;
	StringC Ext_;
};


class DocC
{

public:

	DocC(FileC InFile);

	DocC& Open();

	bool Success();

	FileC ToFile();

	bool Append(StringC Text);
	bool Write(StringC Text);
	bool Empty();

	StringC ToString();

private:
	
	FileC F_;
	StringC S_;

	bool Success_;
};


class PathC
{
public:

	static FolderC DirLog();
	static FolderC DirUsers();
	static FolderC DirConfig();
	static FolderC DirContent();
	static FolderC DirAtlas();
	static FileC FileLog();
	static FileC FileInternalConfig();
	static FileC FileGlobalConfig();
	static FileC FileBabel();
	static FileC FileLogLegend();

	static FolderC DirUserSelected(UserUID InUserUID);

	static void SetGlobals();
};