#pragma once
#include <GL/glew.h>
#include <stdint.h>
#include <iostream>

class VertexBuffer
{
public:
	VertexBuffer(size_t size, void* data, int32_t mode, int32_t target = GL_ARRAY_BUFFER);
	~VertexBuffer();

	void bind();
	void unBind();

private:
	uint32_t m_id;
	int32_t m_target;
};

