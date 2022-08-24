#include "TestLayer.h"

TestLayer::TestLayer()
{
}

TestLayer::~TestLayer()
{
	delete m_shader;
	delete m_camera;
}

void TestLayer::onAttach(Window* win)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_win = win;
	m_shader = new Shader(".\\Src\\Shaders\\basicShader.hlsl");

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	float vertexPositions[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
	};

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);

	uint32_t indices[] = {
		 0, 1, 2,
		 2, 3, 0
	};

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	m_triColor = { 0.32f, 0.41f, 0.86f };

	m_camera = new Camera({ 0.0f, 0.0f, 7.5f });
}

void TestLayer::onDetach()
{
}

void TestLayer::onUpdate(float dt)
{
	glClearColor(0.25f, 0.25f, 0.25f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	m_view = *m_camera->getView();
	m_proj = glm::perspective(glm::radians(45.0f), static_cast<float>(m_win->getWidth()) / static_cast<float>(m_win->getHeight()), 0.1f, 100.0f);
	m_camera->move(*m_win->getContext(), dt);
}

void TestLayer::onRender()
{
	m_shader->use();
	m_shader->setVec3("uColor", m_triColor);
	m_shader->setMat4("uProjection", m_proj);
	m_shader->setMat4("uView", m_view);
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(NULL);
}

void TestLayer::onImguiRender()
{
	ImGui::ColorEdit3("Quad Color", &m_triColor[0]);
	ImGui::Text("FPS: %f", ImGui::GetIO().Framerate);

}
