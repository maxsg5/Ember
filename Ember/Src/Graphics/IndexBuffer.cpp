#include "IndexBuffer.h"
#include <iostream>

IndexBuffer::IndexBuffer(size_t size, uint32_t count, void* data, int32_t mode, int32_t target) :
	m_target{target}, m_count{count}
{
	glGenBuffers(1, &m_id);
	bind();
	glBufferData(m_target, size, data, mode);
	unBind();
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_id);
}

void IndexBuffer::bind()
{
	glBindBuffer(m_target, m_id);
}

void IndexBuffer::unBind()
{
	glBindBuffer(m_target, m_id);
}

void IndexBuffer::draw()
{
	glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, NULL);
}