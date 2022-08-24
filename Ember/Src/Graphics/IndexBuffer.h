#pragma once
#include <GL/glew.h>
#include <stdint.h>

class IndexBuffer
{
public:

	IndexBuffer(size_t size, uint32_t count, void* data, int32_t mode, int32_t target = GL_ELEMENT_ARRAY_BUFFER);
	~IndexBuffer();

	void bind();
	void unBind();
	void draw();

private:
	uint32_t m_id;
	int32_t m_target;
	uint32_t m_count;
};
