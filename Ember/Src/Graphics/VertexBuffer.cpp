#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(size_t size, void* data, int mode, int target) :
	m_target{target}
{
	glGenBuffers(1, &m_id);
	bind();
	glBufferData(m_target, size, data, mode);
	unBind();
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_id);
}

void VertexBuffer::bind()
{
	glBindBuffer(m_target, m_id);
}

void VertexBuffer::unBind()
{
	glBindBuffer(m_target, m_id);
}