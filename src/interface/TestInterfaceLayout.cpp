#include "TestInterfaceLayout.h"

using namespace iFish;

TestInterfaceLayout::TestInterfaceLayout()
{

}

TestInterfaceLayout::~TestInterfaceLayout()
{

}

void TestInterfaceLayout::update()
{
	if (isVisible)
	{
		for (int i = 0; i < components.size(); ++i)
		{
			components[i]->update();
		}
	}
}

void TestInterfaceLayout::draw()
{
	if (isVisible)
	{
		for (int i = 0; i < components.size(); ++i)
		{
			components[i]->draw();
		}
	}
}

void TestInterfaceLayout::setVisibility(bool isVisible)
{
	this->isVisible = isVisible;
}

void TestInterfaceLayout::setPosition(const ofPoint& position)
{
	this->position = position;

	// align UI
	const int paddingLeft = position.x;
	const int shiftY = 40;

	for (int i = 0; i < components.size(); ++i)
	{
		components[i]->setPosition(paddingLeft, position.y + i * shiftY);
	}
}

