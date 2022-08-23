#pragma once
#include "../Src/Core/Layer.h"
#include "../Src/Graphics/Shader.h"
#include "../Src/Gui/gui.h"
#include "../Src/Math/glm.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class TestLayer : public Layer
{
public:
	TestLayer();
	~TestLayer();

	virtual void onAttach(Window* win);
	virtual void onDetach();
	virtual void onUpdate(double dt);
	virtual void onRender();
	virtual void onImguiRender();

private:
	Window* m_win;
	Shader* m_shader;
	unsigned int m_vao;
	glm::vec3 m_triColor;
};