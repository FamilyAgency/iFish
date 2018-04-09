#pragma once

#include "ofMain.h"
#include "tracker/CameraTracker.h"
#include "config/Config.h"
#include "art/ArtDrawer.h"
#include "interface/TestInterfaceLayout.h"

#define DEBUG_VERSION//

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void windowResized(int w, int h);

private:
	iFish::ConfigPtr config;
	iFish::CameraTrackerPtr tracker;
	iFish::ArtDrawerPtr artDrawer;

#ifdef DEBUG_VERSION
	iFish::TestInterfaceLayoutPtr trackerTestInterfaceLayout;
	iFish::TestInterfaceLayoutPtr art1TestInterfaceLayout;
	iFish::TestInterfaceLayoutPtr art2TestInterfaceLayout;
#endif

	void onConfigLoadComplete();
	void onInterfaceEvent(iFish::InterfaceEventType& Event);
	void mousePressed(int x, int y, int button);

};
