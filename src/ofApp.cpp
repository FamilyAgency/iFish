#include "ofApp.h"
#include "tracker/CameraTracker.h"
#include "interface/TestTrackerInterfaceLayout.h"
#include "interface/TestArt1InterfaceLayout.h"

using namespace iFish;

//--------------------------------------------------------------
void ofApp::setup()
{
	config = ConfigPtr(new Config());
	ofAddListener(config->loadCompleteEvent, this, &ofApp::onConfigLoadComplete);

#ifdef DEBUG_VERSION	
	trackerTestInterfaceLayout = TestInterfaceLayoutPtr(new TestTrackerInterfaceLayout());
	trackerTestInterfaceLayout->setPosition(ofPoint(20, 40));
	trackerTestInterfaceLayout->setVisibility(true);
	ofAddListener(trackerTestInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);

	art1TestInterfaceLayout = TestInterfaceLayoutPtr(new TestArt1InterfaceLayout());
	art1TestInterfaceLayout->setPosition(ofPoint(300, 40));
	art1TestInterfaceLayout->setVisibility(true);
	ofAddListener(art1TestInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);

	/*addTestInterfaceLayout = TestInterfaceLayoutPtr(new TestArt1InterfaceLayout());
	addTestInterfaceLayout->setPosition(ofPoint(600, 40));
	addTestInterfaceLayout->setVisibility(true);
	ofAddListener(addTestInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);*/

#endif

	tracker = iFish::TrackerPtr(new CameraTracker());//TwoCameraTracker	
	artDrawer = ArtDrawerPtr(new ArtDrawer());	

	//schedule = SchedulePtr(new Schedule());
	//soundManager = SoundManagerPtr(new SoundManager());
	//artSaver = ArtSaverPtr(new ArtSaver());
	//tcpController = tcpControllerPtr(new tcpController());

	config->load();
}

//--------------------------------------------------------------
void ofApp::onConfigLoadComplete()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Config load complete");

	//tracker->init(config);

	ofLog(ofLogLevel::OF_LOG_NOTICE, "Start application...");
}

//--------------------------------------------------------------
void ofApp::onInterfaceEvent(iFish::InterfaceEventType& Event)
{
	switch (Event)
	{
	case InterfaceEventType::ChangeArt:
		artDrawer->changeArt();
		break;
	case InterfaceEventType::AddPoint:
		artDrawer->addPointToArt();
		break;
	case InterfaceEventType::Clear:
		artDrawer->clearArt();
		break;
	}	
}

//--------------------------------------------------------------
void ofApp::update()
{
	tracker->update();
	artDrawer->update();

	/*schedule->update();
	soundManager->update();*/

#ifdef DEBUG_VERSION
	trackerTestInterfaceLayout->update();
	art1TestInterfaceLayout->update();
#endif
}

//--------------------------------------------------------------
void ofApp::draw()
{
	tracker->draw();
	artDrawer->draw();	

#ifdef DEBUG_VERSION
	// on top level
	trackerTestInterfaceLayout->draw();
	art1TestInterfaceLayout->draw();
#endif
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}
