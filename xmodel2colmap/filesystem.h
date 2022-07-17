#pragma once

#ifndef thisfilesystem
#define thisfilesystem

namespace FS
{
	enum class fileopen
	{
		FILE_IN = 1,
		FILE_OUT = 2,
		FILE_APP = 8,
		FILE_BINARY = 32
	};

	std::string GetExeFileName();
	std::string GetExePath();

	bool F_OpenFile(std::fstream* fp, const char* path, fileopen type);
	bool F_CloseFile(std::fstream* fp);

	char F_Get(std::fstream& fp);
	void F_SkipLine(std::fstream &fp);
	void F_SkipCharacters(std::fstream& fp, uint32_t len);

	std::string F_ReadUntil(std::fstream& fp, char end);
	void F_Error(const char* text);

	std::string F_GetFileName(std::string fullpath);
	std::string GetFileExtension(std::string file);
	std::string RemoveFileExtension(std::string file, size_t chars);

	template <typename t> void F_ReadValueAfterSpace(std::fstream& fp, t& value)
	{
		char ch;

		while (true) {
			ch = F_Get(fp);
			if (ch == ' ')
				break;
		}
		F_ReadValue<t>(fp, value);
	}
	template <typename t> void F_ReadValue(std::fstream& fp, t& value)
	{
		char ch;
		std::string val;
		char prevchar{};
		while (true) {
			ch = F_Get(fp);
			
			if (!std::isdigit(ch) && ch != '.' && ch != '-')
				break;
			prevchar = ch;
			val.push_back(ch);
		}
		//std::cout << "stopped after [" << prevchar << "]\n";

		if (val.size() < 0) {
			F_Error("F_ReadValue(): empty value");
			return;
		}
		value = (t)std::atof(val.c_str());

	}

	bool F_DirectoryExists(std::string directory_path);
	bool F_CreateDirectory(std::string path);

	namespace glob
	{
		inline uint32_t chars_read;
		inline uint16_t lines_read = 1;
		inline bool file_valid;
	}
}

#endif