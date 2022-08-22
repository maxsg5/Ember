#include "../Core/Application.h"

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
	sb->start();
	delete sb;
	return 0;
}