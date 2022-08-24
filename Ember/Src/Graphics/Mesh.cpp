#include "Mesh.h"

Mesh::Mesh(Geometry geo, Material mat) :
	m_geo{ geo }, m_mat{ mat }
{

	m_vao = new VertexArray();
	m_posBuffer = new VertexBuffer(sizeof(m_geo.m_vertexPos) * sizeof(float), &m_geo.m_vertexPos[0], GL_STATIC_DRAW);
	m_vao->enableAttrib(0, 3, sizeof(float) * 3, (void*)0);

	if (m_geo.m_indicies.size() >= 0)
	{
		m_ibo = new IndexBuffer(sizeof(m_geo.m_indicies) * sizeof(uint32_t), sizeof(m_geo.m_indicies), &m_geo.m_indicies[0], GL_STATIC_DRAW);
	}

	m_shader = new Shader(m_mat.m_shader);
}

Mesh::~Mesh()
{
	delete m_vao;
	delete m_posBuffer;
	delete m_ibo;
	delete m_shader;
}

void Mesh::updateUniforms(glm::mat4 proj, glm::mat4 view)
{
	m_shader->use();
	m_shader->setVec3("uColor", m_mat.m_diff);
	m_shader->setMat4("uProjection", proj);
	m_shader->setMat4("uView", view);
}

void Mesh::render()
{
	m_vao->bind();
	if (m_ibo != nullptr)
	{
		m_ibo->draw();
	}
	m_vao->unBind();
}

glm::vec3* Mesh::getDiff(void)
{
	return &m_mat.m_diff;
}