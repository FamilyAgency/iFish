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
	
	showCameraButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Show camera"));
	showCameraButton->onButtonEvent(this, &TestTrackerInterfaceLayout::showCameraButtonClicked);
	components.push_back(showCameraButton);

	showTrackerButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Show tracker"));
	showTrackerButton->onButtonEvent(this, &TestTrackerInterfaceLayout::showTrackerButtonClicked);
	components.push_back(showTrackerButton);
	
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

void TestTrackerInterfaceLayout::showCameraButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::ShowCamera;
	ofNotifyEvent(InterfaceEvent, type);
}

void TestTrackerInterfaceLayout::showTrackerButtonClicked(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::ShowTracker;
	ofNotifyEvent(InterfaceEvent, type);
}

TestTrackerInterfaceLayout::~TestTrackerInterfaceLayout()
{

}
