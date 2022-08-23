#pragma once
#include "../Src/Core/Layer.h"
#include "../Src/Graphics/Shader.h"
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

private:
	Window* m_win;
	Shader* m_shader;
	unsigned int m_vao;
};