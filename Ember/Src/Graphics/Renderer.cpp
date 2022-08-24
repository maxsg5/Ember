#include "Renderer.h"

Renderer::Renderer(RenderSettings settings) : 
	m_settings{settings}
{
	if (m_settings.depthTest)
	{
		glEnable(GL_DEPTH_TEST);
	}
	if (m_settings.blend)
	{
		glEnable(GL_BLEND);
		glBlendFunc(m_settings.sFactorBlend, m_settings.dFactorBlend);
	}
}

Renderer::~Renderer()
{

}

void Renderer::clear(bool color, bool depth, bool stencil)
{
	GLbitfield field;
	if (color && depth && stencil)
	{
		field = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT;
	}
	else if (color && depth && !stencil)
	{
		field = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
	}
	else if (color && !depth && stencil)
	{
		field = GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT;
	}
	else if (!color && depth && stencil)
	{
		field = GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT;
	}
	else if (!color && !depth && stencil)
	{
		field = GL_STENCIL_BUFFER_BIT;
	}
	else if (!color && depth && !stencil)
	{
		field = GL_DEPTH_BUFFER_BIT;
	}
	else if (color && !depth && !stencil)
	{
		field = GL_COLOR_BUFFER_BIT;
	}
	glClearColor(m_settings.backgroundCol.r, m_settings.backgroundCol.g, m_settings.backgroundCol.b, 1.0f);
	glClearDepth(m_settings.clearDepth);
	glClearStencil(m_settings.clearStencil);
	glClear(field);
}

void Renderer::render(Scene* scene)
{
	scene->render();
}
