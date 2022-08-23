#include "TestLayer.h"

TestLayer::TestLayer()
{
}

TestLayer::~TestLayer()
{
	delete m_shader;
}

void TestLayer::onAttach(Window* win)
{
	m_win = win;
	m_shader = new Shader(".\\Src\\Shaders\\basicShader.hlsl");

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	float vertexPositions[] =
	{
		0.0f,  1.0f, 0.0f,
	   -1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f
	};

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);
	
}

void TestLayer::onDetach()
{

}

void TestLayer::onUpdate(double dt)
{
	glClearColor(0.25f, 0.25f, 0.25f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void TestLayer::onRender()
{
	m_shader->use();
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(NULL);
}
