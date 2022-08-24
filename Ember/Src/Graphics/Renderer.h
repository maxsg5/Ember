#pragma once
#include "GL/glew.h"
#include "../Math/glm.hpp"
#include "Scene.h"

struct RenderSettings
{
	bool depthTest;
	bool blend;
	int32_t sFactorBlend;
	int32_t dFactorBlend;
	glm::vec3 backgroundCol;
	float clearDepth = 1.0f;
	int32_t clearStencil = 0;
};

class Renderer
{
public:
	Renderer(RenderSettings settings);
	~Renderer();

	void clear(bool color, bool depth, bool stencil = false);
	void render(Scene* scene);

private:
	RenderSettings m_settings;
};