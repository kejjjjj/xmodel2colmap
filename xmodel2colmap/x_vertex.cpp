#include "h.h"

//assuming the line after NUMVERTS
void X::X_ReadVerts(std::fstream& fp, std::vector<vertex_s>& vertex)
{
	uint32_t i{};
	uint32_t cur_vertex{};

	int ah = 0;
	char ch;
	while (fp.good()) {
		
		// read the vert index //
		FS::F_ReadValueAfterSpace(fp, vertex[i].vertexIndex); //vertex index


		// read the offset //
		FS::F_SkipCharacters(fp, 7);
		vertex[i].offset[0] = std::stof(FS::F_ReadUntil(fp, ' ').c_str());
		vertex[i].offset[1] = std::stof(FS::F_ReadUntil(fp, ' ').c_str());
		vertex[i].offset[2] = std::stof(FS::F_ReadUntil(fp, '\n').c_str());

		// read the bones //
		FS::F_SkipCharacters(fp, 6);
		vertex[i].bones = std::stoi(FS::F_ReadUntil(fp, '\n').c_str());

		// read the 2d bone thing //
		FS::F_SkipCharacters(fp, 5);
		vertex[i].bone[0] = std::stof(FS::F_ReadUntil(fp, ' ').c_str());
		vertex[i].bone[1] = std::stof(FS::F_ReadUntil(fp, '\n').c_str());

		vertex.push_back(vertex[i]);

		FS::F_SkipLine(fp);
		ch = FS::F_Get(fp);

		//printf("vertex[%u].vertexIndex: %i\n", i, vertex[i].vertexIndex);
		//printf("vertex[%u].offset[0]: %.6f\n", i, vertex[i].offset[0]);
		//printf("vertex[%u].offset[1]: %.6f\n", i, vertex[i].offset[1]);
		//printf("vertex[%u].offset[2]: %.6f\n", i, vertex[i].offset[2]);
		//printf("vertex[%u].bones: %i\n", i, vertex[i].bones);
		//printf("vertex[%u].bone[0]: %.6f\n", i, vertex[i].bone[0]);
		//printf("vertex[%u].bone[1]: %.6f\n\n", i, vertex[i].bone[1]);


		if (ch != 'V') {
			_log.AddLog("Finished parsing vertices after (%u) indices\n", i);
			printf("char not found! [%c] (line: %u)\n", ch, FS::glob::lines_read);
			break;
		}
		for (uint16_t j = 0; j < 3; j++)
			vertex[i].offset[j] *= MODELSCALE;

		i++;

	}
}