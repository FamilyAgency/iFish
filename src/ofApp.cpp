#include "ofApp.h"
#include "tracker/CameraTracker.h"
#include "interface/TestTrackerInterfaceLayout.h"
#include "interface/TestArt1InterfaceLayout.h"
#include "tools/http/HttpService.h"

using namespace iFish;

//--------------------------------------------------------------
void ofApp::setup()
{
	config = ConfigPtr(new Config());
	ofAddListener(config->loadCompleteEvent, this, &ofApp::onConfigLoadComplete);

#ifdef DEBUG_VERSION	
	trackerTestInterfaceLayout = TestInterfaceLayoutPtr(new TestTrackerInterfaceLayout());
	trackerTestInterfaceLayout->setPosition(ofPoint(20, 20));
	trackerTestInterfaceLayout->setVisibility(true);
	ofAddListener(trackerTestInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);

	art1TestInterfaceLayout = TestInterfaceLayoutPtr(new TestArt1InterfaceLayout());
	art1TestInterfaceLayout->setPosition(ofPoint(300, 20));
	art1TestInterfaceLayout->setVisibility(false);
	ofAddListener(art1TestInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);

	/*addTestInterfaceLayout = TestInterfaceLayoutPtr(new TestArt1InterfaceLayout());
	addTestInterfaceLayout->setPosition(ofPoint(600, 20));
	addTestInterfaceLayout->setVisibility(true);
	ofAddListener(addTestInterfaceLayout->InterfaceEvent, this, &ofApp::onInterfaceEvent);*/

#endif
	tracker = iFish::CameraTrackerPtr(new CameraTracker(ofGetWidth(), ofGetHeight()));  //TwoCameraTracker
	//tracker = iFish::TrackerPtr(new CameraTracker());//TwoCameraTracker	
	ofAddListener(tracker->newPointEvent, this, &ofApp::onInterfaceEvent);
	artDrawer = ArtDrawerPtr(new ArtDrawer());	
	artSaver = ArtSaverPtr(new ArtSaver());

	//schedule = SchedulePtr(new Schedule());
	//soundManager = SoundManagerPtr(new SoundManager());
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
	case InterfaceEventType::TrackingStart:
		tracker->start();
		//art1TestInterfaceLayout->setVisibility(true);
		//artDrawer->setVisibility(true);
		break;

	case InterfaceEventType::TrackingStop:
		tracker->stop();
		artSaver->saveArt(artDrawer->getArt());
		artDrawer->clearArt();
		tracker->clear();
		artDrawer->setVisibility(false);
		art1TestInterfaceLayout->setVisibility(false);
		break;

	case InterfaceEventType::ShowCamera:
		artSaver->saveArt(artDrawer->getArt());
		artDrawer->setVisibility(false);
		art1TestInterfaceLayout->setVisibility(false);
		break;

	case InterfaceEventType::ShowTracker:
		artSaver->saveArt(artDrawer->getArt());
		artDrawer->setVisibility(true);
		art1TestInterfaceLayout->setVisibility(true);
		break;

	case InterfaceEventType::ChangeArt:
		artDrawer->changeArt();
		break;

	case InterfaceEventType::ChangeColor:
		artDrawer->changeColor();
		break;

	case InterfaceEventType::SaveArt:
		artSaver->saveArt(artDrawer->getArt());
		break;

	case InterfaceEventType::AddPoint:
		tracker->addPointToTracker();
		break;

	case InterfaceEventType::Clear:
		artDrawer->clearArt();
		tracker->clear();
		break;

	case InterfaceEventType::NewPointCome:
		artDrawer->addPointToArt(tracker->getLastPoint());
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

	// finally, a tracker report:
	ofSetColor(0, 0, 0);
	stringstream reportStr;
	reportStr << "Press mouse button to something to change color setting." << endl;
	reportStr << "Current color setting:" << endl;
	reportStr << "min - (" + std::to_string(tracker->getTrackColorMin()[0]) + \
		", " + std::to_string(tracker->getTrackColorMin()[1]) + ", " +
		std::to_string(tracker->getTrackColorMin()[2]) + ");" << endl;

	reportStr << "max - (" + std::to_string(tracker->getTrackColorMax()[0]) + \
		", " + std::to_string(tracker->getTrackColorMax()[1]) + ", " +
		std::to_string(tracker->getTrackColorMax()[2]) + ");" << endl;

	reportStr << "velocity: " << std::to_string(tracker->getVelocity()) << endl;
	//ofDrawBitmapString(reportStr.str(), 400, 540);

	// setting epsilon-distancy
	// current point is saved in arrays if distancy(current point, last point) >= epsilon
	tracker->setEpsilonUpdate(2.5);

#endif
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

void ofApp::mousePressed(int x, int y, int button) 
{
	if (y > 200)
	{
		tracker->setColorsFromMousePressed(x, y);
		art1TestInterfaceLayout->setVisibility(true);
		artDrawer->setVisibility(true);
	}
}