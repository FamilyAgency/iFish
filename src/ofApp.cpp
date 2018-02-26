#include "ofApp.h"
#include "tracker/CameraTracker.h"
#include "interface/IFishInterfaceLayout.h"

using namespace iFish;

//--------------------------------------------------------------
void ofApp::setup()
{
	config = ConfigPtr(new Config());
	ofAddListener(config->loadCompleteEvent, this, &ofApp::onConfigLoadComplete);

#ifdef DEBUG_VERSION	
	interfaceLayout = InterfaceLayoutPtr(new IFishInterfaceLayout());
	ofAddListener(interfaceLayout->changeArtEvent, this, &ofApp::onChangeArt);
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

	ofLog(ofLogLevel::OF_LOG_NOTICE, "Start application...");
}

//--------------------------------------------------------------
void ofApp::onChangeArt()
{
	artDrawer->changeArt();
}

//--------------------------------------------------------------
void ofApp::update()
{
	tracker->update();
	artDrawer->update();

	/*schedule->update();
	soundManager->update();*/

#ifdef DEBUG_VERSION
	interfaceLayout->update();
#endif
}

//--------------------------------------------------------------
void ofApp::draw()
{
	tracker->draw();
	artDrawer->draw();	

#ifdef DEBUG_VERSION
	// on top level
	interfaceLayout->draw();
#endif
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}
