#pragma once
#include <GL/glew.h>
#include <stdint.h>

class IndexBuffer
{
public:

	IndexBuffer(size_t size, uint32_t count, void* data, int mode, int target = GL_ELEMENT_ARRAY_BUFFER);
	~IndexBuffer();

	void bind();
	void unBind();
	void draw();

private:
	uint32_t m_id;
	int m_target;
	uint32_t m_count;
};
