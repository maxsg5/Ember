#pragma once
#include <stdint.h>
#include <vector>
#include "../Math/glm.hpp"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

struct Geometry
{
	std::vector<float> m_vertexPos;
	std::vector<uint32_t> m_indicies;
	//add other vertex info here
	//things like normals etc
};

struct Material
{
	const char* m_shader;
	glm::vec3 m_diff;
	glm::vec3 m_amb;
	glm::vec3 m_spec;
	float m_shine;
};

class Mesh
{
public:
	Mesh(Geometry geo, Material mat);
	~Mesh();

	void updateUniforms(glm::mat4 proj, glm::mat4 view);
	void render();
	glm::vec3* getDiff(void);

private:
	Geometry m_geo;
	Material m_mat;
	Shader* m_shader;

	VertexArray* m_vao;
	VertexBuffer* m_posBuffer;
	IndexBuffer* m_ibo = nullptr;

};