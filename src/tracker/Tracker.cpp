#include "Tracker.h"

using namespace iFish;

Tracker::Tracker()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Base Tracker init");
}

void Tracker::clear()
{
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
