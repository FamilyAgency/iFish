#include "Tracker.h"

using namespace iFish;

Tracker::Tracker()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Base Tracker init");
}

void Tracker::addPointToTracker()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Add point to tracker");
	lastTrackedPoint = ofVec3f(rand() % 1000, rand() % 700, 0);	// Randome point
	trackedPoints.push_back(lastTrackedPoint);
	auto type = InterfaceEventType::NewPointCome;
	ofNotifyEvent(newPointEvent, type);
}

void Tracker::clear()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Clear tracker");
	trackedPoints.clear();

}

ofVec3f Tracker::getLastPoint() const
{
	return lastTrackedPoint;
}

std::vector<ofVec3f> Tracker::getAllPoints() const
{
	return trackedPoints;
}

Tracker::~Tracker()
{

}
