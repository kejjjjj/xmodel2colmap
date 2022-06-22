#pragma once

#ifndef thisparser
#define thisparser
#include "h.h"

struct file_info
{
	uint32_t triangleCount;
	uint32_t faceCount;
	uint32_t vertexCount;
	uint32_t boneCount;
	const char* mapname;

};
struct vertex_s
{
	uint32_t vertexIndex;
	vec3_t offset;
	uint32_t bones;
	vec2_t bone;
};
struct face_s
{
	vec4_t tri;
	uint32_t vertexIndex;
	vec3_t normal;
	vec4_t color;
	vec3_t uv;
};
struct bone_s
{
	uint32_t boneIndex;
	vec3_t offset;
	vec3_t scale;
	vec3_t angles[3];
};
struct output_mesh
{
	vec3_t triangle;
};
namespace X
{
	inline file_info fileinfo;

	void X_Init(const char* path);
	void X_ReadFile(std::fstream& fp, std::vector<face_s>& face, std::vector<vertex_s>& vertex);
	void X_ReadVerts(std::fstream& fp, std::vector<vertex_s>& vertex);
	void X_ReadFaces(std::fstream& fp, std::vector<face_s>& face);
	void X_MakeTriangle(std::fstream& fp, std::vector<vertex_s>& vertex, std::vector<face_s>& face, std::vector<output_mesh>& output);
	void X_WriteOutput(std::fstream& fp, std::vector<output_mesh>& mesh);
}

#endif