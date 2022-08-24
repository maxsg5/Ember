#pragma once
#include "../Src/Core/Layer.h"
#include "../Src/Graphics/Graphics.h"
#include "../Src/Gui/gui.h"
#include "../Src/Math/glm.hpp"
#include "../Src/Math/gtc/matrix_transform.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class TestLayer : public Layer
{
public:
	TestLayer();
	~TestLayer();

	virtual void onAttach(Window* win);
	virtual void onDetach();
	virtual void onUpdate(float dt);
	virtual void onRender();
	virtual void onImguiRender();

private:
	Window* m_win;
	Shader* m_shader;
	Camera* m_camera;
	Renderer* m_renderer;

	glm::vec3 m_triColor;

	glm::mat4 m_proj;
	glm::mat4 m_view;

	VertexBuffer* m_vbo;
	IndexBuffer* m_ibo;
	VertexArray* m_vao;
};