#include "TestTrackerInterfaceLayout.h"

using namespace iFish;

TestTrackerInterfaceLayout::TestTrackerInterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "IFish InterfaceLayout init");
	
	trackingStartButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Tracking Start"));
	trackingStartButton->onButtonEvent(this, &TestTrackerInterfaceLayout::trackingStartButtonClicked);
	components.push_back(trackingStartButton);

	trackingStopButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Tracking Stop"));
	trackingStopButton->onButtonEvent(this, &TestTrackerInterfaceLayout::trackingStopButtonClicked);
	//trackingStopButton->setEnabled(false);
	components.push_back(trackingStopButton);

	//default align
	setPosition(ofPoint(20, 40));
}

void TestTrackerInterfaceLayout::update()
{
	TestInterfaceLayout::update();	
}

void TestTrackerInterfaceLayout::draw()
{
	TestInterfaceLayout::draw();
}

void TestTrackerInterfaceLayout::trackingStartButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::TrackingStart;
	ofNotifyEvent(InterfaceEvent, type);
}

void TestTrackerInterfaceLayout::trackingStopButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::TrackingStop;
	ofNotifyEvent(InterfaceEvent, type);
}

TestTrackerInterfaceLayout::~TestTrackerInterfaceLayout()
{

}
