#pragma once
#include "GL/glew.h"
#include "../Math/glm.hpp"

struct RenderSettings
{
	bool depthTest;
	bool blend;
	int sFactorBlend;
	int dFactorBlend;
	glm::vec3 backgroundCol;
	float clearDepth = 1.0f;
	int clearStencil = 0;
};

class Renderer
{
public:
	Renderer(RenderSettings settings);
	~Renderer();

	void clear(bool color, bool depth, bool stencil = false);

private:
	RenderSettings m_settings;
};