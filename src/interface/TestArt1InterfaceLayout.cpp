#include "TestArt1InterfaceLayout.h"
#include "../tracker/Tracker.h"

using namespace iFish;


TestArt1InterfaceLayout::TestArt1InterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Test Art1 InterfaceLayout init");

	addPointButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Add point"));
	addPointButton->onButtonEvent(this, &TestArt1InterfaceLayout::addPointButtonClicked);
	components.push_back(addPointButton);

	clearButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Clear"));
	clearButton->onButtonEvent(this, &TestArt1InterfaceLayout::clearButtonClicked);
	components.push_back(clearButton);

	changeArtButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Change Art"));
	changeArtButton->onButtonEvent(this, &TestArt1InterfaceLayout::changeArtButtonClicked);
	components.push_back(changeArtButton);

	//default align
	setPosition(ofPoint(100, 40));
}

void TestArt1InterfaceLayout::update()
{
	TestInterfaceLayout::update();
	clearButton->update();
	addPointButton->update();
	changeArtButton->update();
}

void TestArt1InterfaceLayout::draw()
{
	TestInterfaceLayout::draw();
}

void TestArt1InterfaceLayout::addPointButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::AddPoint;
	ofNotifyEvent(InterfaceEvent, type);
}

void TestArt1InterfaceLayout::clearButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::Clear;
	ofNotifyEvent(InterfaceEvent, type);
}

void TestArt1InterfaceLayout::changeArtButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::ChangeArt;
	ofNotifyEvent(InterfaceEvent, type);
}

TestArt1InterfaceLayout::~TestArt1InterfaceLayout()
{

}