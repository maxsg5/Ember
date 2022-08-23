#include "LayerStack.h"

LayerStack::LayerStack()
{

}

LayerStack::~LayerStack()
{
    while (!isEmpty())
    {
        m_layers.back()->onDetach();
        m_layers.pop_back();
    }
}

void LayerStack::push(Layer* layer, Window* win)
{
    layer->onAttach(win);
    m_layers.push_back(layer);
}

void LayerStack::pop()
{
    m_layers.back()->onDetach();
    m_layers.pop_back();
}

bool LayerStack::isEmpty()
{
    return m_layers.size() == 0;
}

int LayerStack::size()
{
    return m_layers.size();
}

void LayerStack::updateLayers(float dt)
{
    for (int i = m_layers.size() - 1; i >= 0; i--)
    {
        Layer* layer = m_layers[i];
        layer->onUpdate(dt);
        layer->onRender();
        layer->onImguiRender();
    }
}