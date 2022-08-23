#pragma once
#include "Window.h"
#include <string>

class Layer
{
public:
    Layer(const std::string& name = "Layer");
    virtual ~Layer() = default;

    virtual void onAttach(Window* win) {};
    virtual void onDetach() {};
    virtual void onUpdate(double dt) {};
    virtual void onRender() {};
    virtual void onImguiRender() {};

protected:
    std::string m_name;
};