#pragma once
#include "ofMain.h"
#include "TestInterfaceLayout.h"

namespace iFish
{
	typedef ofPtr<class TestTrackerInterfaceLayout> TestTrackerInterfaceLayoutPtr;

	class TestTrackerInterfaceLayout : public TestInterfaceLayout
	{
	public:
		TestTrackerInterfaceLayout();

		virtual void update() override;
		virtual void draw() override;
		virtual ~TestTrackerInterfaceLayout();

	private:
		ofPtr<ofxDatGuiButton> trackingStartButton, trackingStopButton;
		ofPtr<ofxDatGuiButton> showCameraButton, showTrackerButton;
		ofPtr<ofxDatGuiLabel> peopleTrackedText;

		void trackingStartButtonClicked(ofxDatGuiButtonEvent event);
		void trackingStopButtonClicked(ofxDatGuiButtonEvent event);
		void showCameraButtonClicked(ofxDatGuiButtonEvent event);
		void showTrackerButtonClicked(ofxDatGuiButtonEvent event);
	};
}

