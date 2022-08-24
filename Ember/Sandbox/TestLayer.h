#pragma once
#include "../Src/Core/Layer.h"
#include "../Src/Graphics/Graphics.h"
#include "../Src/Gui/gui.h"
#include "../Src/Math/glm.hpp"
#include "../Src/Math/gtc/matrix_transform.hpp"
#include <stdint.h>
#include <vector>


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
	Renderer* m_renderer;
	Scene* m_scene;
};