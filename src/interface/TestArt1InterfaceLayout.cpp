#include "TestArt1InterfaceLayout.h"

using namespace iFish;

TestArt1InterfaceLayout::TestArt1InterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Test Art1 InterfaceLayout init");	
	
	//default align
	setPosition(ofPoint(100, 40));
}

void TestArt1InterfaceLayout::update()
{
	TestInterfaceLayout::update();	
}

void TestArt1InterfaceLayout::draw()
{
	TestInterfaceLayout::draw();
}

TestArt1InterfaceLayout::~TestArt1InterfaceLayout()
{

}
