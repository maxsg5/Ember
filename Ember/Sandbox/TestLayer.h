#pragma once
#include "../Src/Core/Layer.h"
#include "../Src/Graphics/Shader.h"
#include "../Src/Graphics/Camera.h"
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

	unsigned int m_vao;
	glm::vec3 m_triColor;

	glm::mat4 m_proj;
	glm::mat4 m_view;
};