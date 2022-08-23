#include "../Src/Core/Application.h"
#include "TestLayer.h"

class Sandbox : public Application
{
public:
	Sandbox(const std::string label) : Application(label)
	{
	}
};

int main()
{
	Sandbox* sb = new Sandbox("Test");
	
	sb->pushLayer(new TestLayer());

	sb->start();
	delete sb;
	return 0;
}