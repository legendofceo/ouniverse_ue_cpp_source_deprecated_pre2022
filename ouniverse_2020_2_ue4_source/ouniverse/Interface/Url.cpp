//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Url.h"

#include <sstream>
#include <fstream>
#include <string>

#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "GenericPlatform/GenericPlatformFile.h"

#include "Min/DebugM.h"

#include "File/Oni@.h"

namespace GlobalURL_Dir
{
	FolderC DocMy;
	FolderC AppMy;
	FolderC Content;
	FolderC Log;
	FolderC Users;
	FolderC Config;
	FolderC Atlas;
}

namespace GlobalURL_File
{
	FileC Log;
}


FolderC::FolderC()
{
	S_ = "";
}

FolderC::FolderC(StringC InPath)
{
	S_ = InPath;
}

void FolderC::Make()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString NormDir = S_.ToFString();
	FPaths::NormalizeDirectoryName(NormDir);
	PlatformFile.CreateDirectoryTree(*NormDir);
}

ArrayC<FolderC> FolderC::GetFolders()
{
	StringC Seek = S_ / "*";
	//Seek += "*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *Seek.ToFString(), false, true);

	ArrayC<FolderC> Arr;
	int l = Files.Num();
	for (int i = 0; i < l; i++)
	{
		Arr.Add(FolderC(S_ / StringC(Files[i])));
	}

	return Arr;
}

ArrayC<FileC> FolderC::GetFiles()
{
	StringC Seek = S_ / "*";
	//Seek += "*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *Seek.ToFString(), true, false);

	ArrayC<FileC> Arr;

	int l = Files.Num();
	for (int i = 0; i < l; i++)
	{
		ArrayC<StringC> FileName = StringC(Files[i]).Split('.');
		Arr.Add(FileC(*this, FileName[0],FileName[1]));
	}

	return Arr;
}

ArrayC<FileC> FolderC::GetFiles(StringC InExtension)
{
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *S_.ToFString(), *InExtension.ToFString());

	ArrayC<FileC> Arr;

	int l = Files.Num();
	for (int i = 0; i < l; i++)
	{
		ArrayC<StringC> FileName = StringC(Files[i]).Split('.');
		Arr.Add(FileC(*this, FileName[0], FileName[1]));
	}

	return Arr;
}

StringC FolderC::GetFinalDir()
{
	StringC FinalDir = S_.RemoveLastChar();
	int Last = FinalDir.FindLast("/\\");
	return FinalDir.SubString(Last + 1,-1);
}

StringC FolderC::ToString()
{
	return S_;
}

FileC FolderC::ToFile(StringC File, StringC Ext)
{
	return FileC(*this, File, Ext);
}

FolderC FolderC::ToInsideFolder(StringC InNextFolder)
{
	return ToString() / InNextFolder;
}



FileC::FileC()
{
	Fo_ = FolderC();
	Fi_ = "NULL";
	Ext_ = "NULL";

}

FileC::FileC(FolderC InFolder, StringC InFileName, StringC InExtension)
{
	Fo_ = InFolder;
	Fi_ = InFileName;
	Ext_ = InExtension;
}

StringC FileC::ToString()
{
	return Fo_.ToString() / Fi_ +"."+ Ext_ ;
}

StringC FileC::Name()
{
	return Fi_;
}

bool FileC::Exists()
{

	if (FPaths::FileExists(ToString().ToChar()))
	{
		return true;
	}

	return false;
}

DocC FileC::Doc()
{
	return DocC(*this);
}







DocC::DocC(FileC InFile)
{
	F_ = InFile;
}

FileC DocC::ToFile()
{
	return F_;
}

DocC& DocC::Open()
{
	std::stringstream sstr;

	std::ifstream ifs(F_.ToString().ToChar());
	if (!ifs.is_open()) {

		return *this;
	}

	Success_ = true;
	sstr << ifs.rdbuf();
	S_ = StringC(sstr.str());

	ifs.close();

	return *this;
}

StringC DocC::ToString()
{
	return S_;
}


bool DocC::Append(StringC Text)
{
	std::ofstream out;
	out.open(F_.ToString().ToStd(), std::ios::app);
	out << Text.ToChar();
	out.close();
	return true;
}

bool DocC::Write(StringC Text)
{
	std::ofstream out;
	out.open(F_.ToString().ToStd(), std::ios::trunc);
	out << Text.ToChar();
	out.close();
	return true;
}

bool DocC::Empty()
{
	std::ofstream ofs;
	ofs.open(F_.ToString().ToStd(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return true;
}

bool DocC::Success()
{
	return Success_;
}


void PathC::SetGlobals()
{
	StringC D_OUniverse = "OUniverse";
	StringC D_ThisOUniverse = "OUniverse I";

	StringC D_Config = "Config";
	StringC D_Log = "Logs";

	StringC D_Users = "Users";
	StringC D_Atlas = "Atlas";

	StringC UserDir = StringC(FString(FPlatformProcess::UserDir()));
	StringC AppDir = StringC(FString(FPlatformProcess::UserSettingsDir()));

	GlobalURL_Dir::DocMy	= FolderC(UserDir + D_OUniverse);
	GlobalURL_Dir::AppMy	= FolderC(AppDir + D_ThisOUniverse / D_Config);
	GlobalURL_Dir::Content	= FolderC(StringC(FPaths::ProjectContentDir()));
	GlobalURL_Dir::Log		= FolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Log));
	GlobalURL_Dir::Users	= FolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Users));
	GlobalURL_Dir::Config   = FolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Config));
	GlobalURL_Dir::Atlas	= FolderC(StringC(GlobalURL_Dir::Content.ToString() + D_Atlas));

	GlobalURL_File::Log = DirLog().ToFile("log", "txt");
	   
}

FolderC PathC::DirLog()
{
	return GlobalURL_Dir::Log;
}

FolderC PathC::DirUsers()
{
	return GlobalURL_Dir::Users;
}

FolderC PathC::DirConfig()
{
	return GlobalURL_Dir::Config;
}

FolderC PathC::DirContent()
{
	return GlobalURL_Dir::Content;
}

FolderC PathC::DirAtlas()
{
	return GlobalURL_Dir::Atlas;
}

FileC PathC::FileLog()
{
	return DirLog().ToFile("log", "txt");
}

FileC PathC::FileInternalConfig()
{
	return DirConfig().ToFile(OniFI::InternalFileName, OniFI::Extension);
}

FileC PathC::FileGlobalConfig()
{
	return DirConfig().ToFile(OniFI::GlobalFileName, OniFI::Extension);
}

FolderC PathC::DirUserSelected(UserUID InUserUID)
{
	return DirUsers().ToInsideFolder(InUserUID.ToString());
}

FileC PathC::FileBabel()
{
	return DirContent().ToInsideFolder("file").ToFile("_", "babel");
}

FileC PathC::FileLogLegend()
{
	return DirContent().ToInsideFolder("file").ToFile("_", "loglegend");
}