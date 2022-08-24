#include "TestLayer.h"

TestLayer::TestLayer()
{
}

TestLayer::~TestLayer()
{
	delete m_renderer;
	delete m_scene;
}

void TestLayer::onAttach(Window* win)
{
	m_win = win;

	RenderSettings renderSettings{
		true,
		true,
		GL_SRC_ALPHA,
		GL_ONE_MINUS_SRC_ALPHA,
		{ 0.25f, 0.25f, 0.25f }
	};
	m_renderer = new Renderer(renderSettings);

	SceneSettings sceneSettings = {
		glm::radians(45.0f),
		static_cast<float>(m_win->getWidth()) / static_cast<float>(m_win->getHeight()),
		0.01f,
		100.0f
	};
	m_scene = new Scene(sceneSettings);
	m_scene->addCamera(new Camera({ 0.0f, 0.0f, 7.5f }));

	std::vector<float> vertexPositions = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
	};
	std::vector<uint32_t> indices = {
		 0, 1, 2,
		 2, 3, 0
	};
	Geometry geo = { vertexPositions, indices };
	Material mat = { ".\\Src\\Shaders\\basicShader.hlsl", glm::vec3(0.32f, 0.41f, 0.86f)};
	m_scene->addMesh(new Mesh(geo, mat));
}

void TestLayer::onDetach()
{
}

void TestLayer::onUpdate(float dt)
{
	m_scene->update(*m_win->getContext(), dt);
}

void TestLayer::onRender()
{
	m_renderer->clear(true, true);
	m_renderer->render(m_scene);
}

void TestLayer::onImguiRender()
{
	ImGui::Text("FPS: %f", ImGui::GetIO().Framerate);
}
