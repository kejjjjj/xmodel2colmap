#include "h.h"


bool FS::F_OpenFile(std::fstream* fp, const char* path, fileopen type)
{

	glob::file_valid = true;
	glob::chars_read = 0;
	glob::lines_read = 1;
	if (fp->is_open())
		return true;

	fp->open(path, (int)type);

	if (!fp->is_open())
		return false;

	return true;


}
bool FS::F_CloseFile(std::fstream* fp)
{
	if (fp->is_open())
		fp->close();

	if (fp->is_open())
		return false;

	return true;
}
void FS::F_Error(const char* text)
{
	_log.AddLog("ERROR: %s\n", text);
	_log.AddLog("on line: (%u)\n", glob::lines_read);
	glob::file_valid = false;
}
char FS::F_Get(std::fstream& fp)
{
	if (!fp.is_open())
		return 0;
	char ch;
	fp.get(ch);

	glob::chars_read += 1;
	if (ch == '\n')
		glob::lines_read += 1;

	return ch;
}
void FS::F_SkipLine(std::fstream& fp)
{
	char ch;

	while (fp.good()) {
		ch = F_Get(fp);
		if (ch == '\n')
			break;
	}
}
std::string FS::F_ReadUntil(std::fstream& fp, char end)
{
	char ch;
	std::string txt;

	while (true) {
		ch = FS::F_Get(fp);
		txt.push_back(ch);
		if (ch == end)
			break;
	}
	if (txt.size() < 1)
		return "N/A";

	return txt;
}
void FS::F_SkipCharacters(std::fstream& fp, uint32_t len)
{
	for (uint32_t i = 0; i < len; i++)
		F_Get(fp);
}
std::string FS::F_GetFileName(std::string fullpath)
{
	size_t pos = fullpath.find_last_of('\\');

	if (pos < 1)
		return fullpath;

	fullpath = fullpath.substr(pos + 1);


	return fullpath;
}
std::string FS::GetFileExtension(std::string file)
{

	int extensionPos = file.find_last_of(".");

	if (extensionPos < 0)
		return "No extension";

	file = file.substr(extensionPos);


	return file;
}
std::string FS::RemoveFileExtension(std::string file, size_t chars)
{
	return file.substr(0, file.size() - chars);
}
std::string FS::GetExeFileName()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	return std::string(buffer);
}
std::string FS::GetExePath()
{
	std::string f = GetExeFileName();
	return f.substr(0, f.find_last_of("\\/"));
}
bool FS::F_DirectoryExists(std::string directory_path)
{
	return fs::exists(directory_path);
}
bool FS::F_CreateDirectory(std::string path)
{
	return _mkdir((path).c_str()) != -1;
}