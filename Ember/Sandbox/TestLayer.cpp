#include "TestLayer.h"

TestLayer::TestLayer()
{
}

TestLayer::~TestLayer()
{
	delete m_shader;
	delete m_camera;
	delete m_vbo;
	delete m_ibo;
	delete m_vao;
}

void TestLayer::onAttach(Window* win)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_win = win;
	m_shader = new Shader(".\\Src\\Shaders\\basicShader.hlsl");

	m_vao = new VertexArray();

	float vertexPositions[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
	};
	
	m_vbo = new VertexBuffer(sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	m_vao->enableAttrib(0, 3, sizeof(float) * 3, (void*)0);

	uint32_t indices[] = {
		 0, 1, 2,
		 2, 3, 0
	};

	m_ibo = new IndexBuffer(sizeof(indices), sizeof(indices) / sizeof(uint32_t), indices, GL_STATIC_DRAW);
	
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
	m_vao->bind();
	m_ibo->draw();
	m_vao->unBind();
}

void TestLayer::onImguiRender()
{
	ImGui::ColorEdit3("Quad Color", &m_triColor[0]);
	ImGui::Text("FPS: %f", ImGui::GetIO().Framerate);

}
