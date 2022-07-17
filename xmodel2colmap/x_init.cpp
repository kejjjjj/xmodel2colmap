#include "h.h"


//assuming we get modelfolder\\filename.XMODEL_EXPORT

void X::X_Init(const char* path)
{
	std::vector<vertex_s> vertex(1);
	std::vector<face_s> face(1);
	std::vector<output_mesh> output(1);

//	std::vector<bone_s> bone;
	std::fstream fp;
	FS::glob::file_valid = true;

	//const char* path = "D:\\Activision\\CallOfDuty4\\model_export\\cubetest.txt";

	std::string filename = FS::F_GetFileName(path);
	std::string extension = FS::GetFileExtension(filename);
	std::string mapname = FS::RemoveFileExtension(filename, extension.size());
	fileinfo.mapname = mapname.c_str();
	

	_log.AddLog("attempting to open: %s", path);

	std::string full_path = std::string(GAME_PATH) + '\\' + path;

	if (!FS::F_OpenFile(&fp, full_path.c_str(), FS::fileopen::FILE_IN)) {
		_log.AddLog(" <-- FAILED!\n");
		FS::F_Error("X_Init(): can't open the file");
		return;
	}
	_log.AddLog(" <-- OK!\n");
	X_ReadFile(fp, face, vertex); if (!FS::glob::file_valid) goto end;
	X_MakeTriangle(fp, vertex, face, output);

	
	end:
	FS::F_CloseFile(&fp);
}