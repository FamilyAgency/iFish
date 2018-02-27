#include "TestArt1InterfaceLayout.h"

using namespace iFish;

TestArt1InterfaceLayout::TestArt1InterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Test Art1 InterfaceLayout init");
	
	nextArtBtn = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Next Art"));
	nextArtBtn->onButtonEvent(this, &TestArt1InterfaceLayout::nextArtButtonClicked);
	components.push_back(nextArtBtn);

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

void TestArt1InterfaceLayout::nextArtButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::ChangeArt;
	ofNotifyEvent(InterfaceEvent, type);
}

TestArt1InterfaceLayout::~TestArt1InterfaceLayout()
{

}
