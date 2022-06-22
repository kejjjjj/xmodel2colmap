#include "h.h"

//assuming current char is N before UMFACES
void X::X_ReadFaces(std::fstream& fp, std::vector<face_s>& face)
{
	uint32_t i{};
	std::string numfaces = FS::F_ReadUntil(fp, 'S');

	if (numfaces.find("FACES") < 1) {
		FS::F_Error("X_ReadFaces(): numfaces != " "UMFACES\n");
		_log.AddLog("[%s]\n", numfaces.c_str());
		return;
	}
	
	fileinfo.faceCount = std::atoi(FS::F_ReadUntil(fp, '\n').c_str());
	//FS::F_Get(fp);
	while (true) {

		FS::F_ReadUntil(fp, 'T');
		char ch = FS::F_Get(fp);
		if (ch != 'R') {
			_log.AddLog("X_ReadFaces(): stopping numfaces...\n");
			_log.AddLog("after iterations: %i\n", i) ;
			_log.AddLog("on line: (%u)\n", FS::glob::lines_read);

			break;
		}


		FS::F_ReadUntil(fp, ' ');

		// read the triangles //
		face[i].tri[0] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
		face[i].tri[1] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
		face[i].tri[2] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
		face[i].tri[3] = std::atof(FS::F_ReadUntil(fp, '\n').c_str());


		for(int o = 0; o < 3; o++){ //loop 3 times, because each face needs 3 points

			// read the vertex index this face needs //
			FS::F_SkipCharacters(fp, 5);
			face[i].vertexIndex = std::atoi(FS::F_ReadUntil(fp, '\n').c_str());

			// read the triangle normals //
			FS::F_SkipCharacters(fp, 7);
			face[i].normal[0] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].normal[1] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].normal[2] = std::atof(FS::F_ReadUntil(fp, '\n').c_str());

			// read the face color //
			FS::F_SkipCharacters(fp, 6);
			face[i].color[0] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].color[1] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].color[2] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].color[3] = std::atof(FS::F_ReadUntil(fp, '\n').c_str());

			// read the face UV //
			FS::F_SkipCharacters(fp, 3);
			face[i].uv[0] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].uv[1] = std::atof(FS::F_ReadUntil(fp, ' ').c_str());
			face[i].uv[2] = std::atof(FS::F_ReadUntil(fp, '\n').c_str());

			face.push_back(face[i]);

			i++;
		}

		//FS::F_SkipLine(fp);
		//FS::F_SkipLine(fp);


	}
	//for (int i = 0; i < face.size(); i++) {
	//	printf("face[%i].tri[0]: %.1f\n", i, face[i].tri[0]);
	//	printf("face[%i].tri[1]: %.1f\n", i, face[i].tri[1]);
	//	printf("face[%i].tri[2]: %.1f\n", i, face[i].tri[2]);
	//	printf("face[%i].tri[3]: %.1f\n", i, face[i].tri[3]);

	//	printf("face[%i].vertexIndex: %i\n", i, face[i].vertexIndex);

	//	printf("face[%i].normal[0]: %.6f\n", i, face[i].normal[0]);
	//	printf("face[%i].normal[1]: %.6f\n", i, face[i].normal[1]);
	//	printf("face[%i].normal[2]: %.6f\n", i, face[i].normal[2]);


	//	printf("face[%i].color[0]: %.6f\n", i, face[i].color[0]);
	//	printf("face[%i].color[1]: %.6f\n", i, face[i].color[1]);
	//	printf("face[%i].color[2]: %.6f\n", i, face[i].color[2]);
	//	printf("face[%i].color[3]: %.6f\n", i, face[i].color[3]);

	//	printf("face[%i].uv[0]: %.6f\n", i, face[i].uv[0]);
	//	printf("face[%i].uv[1]: %.6f\n", i, face[i].uv[1]);
	//	printf("face[%i].uv[2]: %.6f\n\n", i, face[i].uv[2]);

	//}

}