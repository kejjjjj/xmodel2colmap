#include "h.h"


void X::X_Init(const char* path)
{
	std::vector<vertex_s> vertex(1);
	std::vector<face_s> face(1);
	std::vector<output_mesh> output(1);

//	std::vector<bone_s> bone;
	std::fstream fp;
	FS::glob::file_valid = true;

	//const char* path = "D:\\Activision\\CallOfDuty4\\model_export\\cubetest.txt";

	fileinfo.mapname = FS::F_GetFileName(path);

	_log.AddLog("attempting to open: %s", path);

	if (!FS::F_OpenFile(&fp, path, FS::fileopen::FILE_IN)) {
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