
#include "h.h"

bool X::X_SaveFile()
{
	std::fstream f;
	if (!FS::F_OpenFile(&f, std::string(FS::GetExePath() + "\\x_savedir.txt").c_str(), FS::fileopen::FILE_OUT)) {
		_log.AddLog("ERROR: game directory could not be saved! (can't create file)\n");
		return false;
	}

	f << GAME_PATH;

	_log.AddLog("game directory saved! (%s)\n", std::string(FS::GetExePath() + "\\x_savedir.txt").c_str());
	
	FS::F_CloseFile(&f); 

	return true;

}
bool X::X_LoadFile()
{
	std::fstream f;
	if (!FS::F_OpenFile(&f, std::string(FS::GetExePath() + "\\x_savedir.txt").c_str(), FS::fileopen::FILE_IN)) {
		_log.AddLog("ERROR: game directory save file could not be opened! (file does not exist)\n");
		return false;
	}

	std::string savepath;
	while (f.good()) 
		savepath.push_back(f.get());

	const char* save = savepath.c_str();

	memcpy(GAME_PATH, save, savepath.size() - 1);

	_log.AddLog("game directory loaded from save file! (%s)\n", GAME_PATH);


	FS::F_CloseFile(&f);

	return true;
}