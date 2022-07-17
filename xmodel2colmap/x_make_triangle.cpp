#include "h.h"


void X::X_MakeTriangle(std::fstream& fp, std::vector<vertex_s>& vertex, std::vector<face_s>& face, std::vector<output_mesh>& output)
{
	for (int j = 0; j < face.size(); j++) {
		for (int i = 0; i < 3; i++) {
			output[j].triangle[i] = vertex[face[j].vertexIndex].offset[i];
		}
		output.push_back(output[j]);
	}

	//for (int i = 0; i < output.size(); i++) {
	//	std::cout << "----" << i << "----\n";
	//	for (int j = 0; j < 3; j++) 
	//		std::cout << '[' << j << "]: " << output[i].triangle[j] << '\n';
	//	
	//	std::cout << '\n';
	//}
	_log.AddLog("writing the .map file..\n");
	X_WriteOutput(fp, output);
}

void X::X_WriteOutput(std::fstream& fp, std::vector<output_mesh>& mesh)
{
	if (!FS::F_CloseFile(&fp))
		return;
	std::string dir = std::string(GAME_PATH) + "\\map_source\\prefabs\\kej";
	std::string mapsource = dir + '\\' + fileinfo.mapname + ".map";

	if (!FS::F_DirectoryExists(dir))
		FS::F_CreateDirectory(dir);

	if (!FS::F_OpenFile(&fp, mapsource.c_str(), FS::fileopen::FILE_OUT)) {
		FS::F_Error("X_WriteOutput(): can't open file for output"
		"\ndoes map_source\\prefabs\\kej exist?\n");
		return;
	}

	fp << "iwmap 4\n";
	fp << '"' << "000_Global" << '"' << " flags  active\n";
	fp << '"' << "The Map" << '"' << " flags\n";
	fp << "// entity 0\n{\n";
	fp << '"' << "classname" << '"' << ' ' << '"' << "worldspawn" << '"' << '\n';

	uint32_t brushidx{};

	for (size_t i = 0; i < mesh.size() - 3 ; i) {

		if (i >= mesh.size()) break;

		fp << "// brush " << brushidx << '\n';
		fp << " {\n";
		fp << "  mesh\n  {\n";
		fp << "   clip\n";
		fp << "   lightmap_gray\n";
		fp << "   smoothing smoothing_hard\n";
		fp << "   2 2 0 8\n";
		fp << "   (\n";
		fp << "	v " << mesh[i].triangle[0] << ' ' << mesh[i].triangle[1] << ' ' << mesh[i].triangle[2] << " t -8192 4096 -4 4\n";

		i++; if (i >= mesh.size()) break;

		fp << "	v " << mesh[i].triangle[0] << ' ' << mesh[i].triangle[1] << ' ' << mesh[i].triangle[2] << " t -8192 4096 -4 4\n";

		i++; if (i >= mesh.size()) break;

		fp << "   )\n";
		fp << "   (\n";
		fp << "	v " << mesh[i].triangle[0] << ' ' << mesh[i].triangle[1] << ' ' << mesh[i].triangle[2] << " t -8192 4096 -4 4\n";
		fp << "	v " << mesh[i].triangle[0] << ' ' << mesh[i].triangle[1] << ' ' << mesh[i].triangle[2] << " t -8192 4096 -4 4\n";
		i++;
		fp << "   )\n";
		fp << "  }\n";
		fp << " }\n";
		brushidx++;
	}

	fp << "}\n";

	FS::F_CloseFile(&fp);

	_log.AddLog("done!\n");

}