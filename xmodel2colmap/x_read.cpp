#include "h.h"


void X::X_ReadFile(std::fstream& fp, std::vector<face_s>& face, std::vector<vertex_s>& vertex)
{
	char ch{};
	while (fp.good()) {
		ch = FS::F_Get(fp);
		if (ch == 'N') {
			ch = FS::F_Get(fp);
			if (ch == 'U') {
				ch = FS::F_Get(fp);
				if (ch == 'M') {
					ch = FS::F_Get(fp);
					if (ch == 'V') {
						_log.AddLog("Numverts begins at (%u)\n", FS::glob::lines_read);
						goto stoploop;
					}
				}
			}
		}
	}
stoploop:
	if (fp.eof()) {
		FS::F_Error("Couldn't find NUMVERTS from the file");
		return;
	}


	FS::F_ReadValueAfterSpace<uint32_t>(fp, fileinfo.vertexCount); if (!FS::glob::file_valid) return;
	X_ReadVerts(fp, vertex);
	X_ReadFaces(fp, face);

}