#pragma once
#include "ofMain.h"

namespace iFish
{
	typedef ofPtr<class Tracker> TrackerPtr;

	class Tracker 
	{
	public:
		Tracker();

		ofEvent<ofVec3f> newPointEvent;
		ofEvent<ofVec3f> errorEvent;

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void clear();

		virtual ofVec3f getLastPoint() const;
		virtual std::vector<ofVec3f> getAllPoints() const;

		virtual ~Tracker();		

	protected:
		ofVec3f lastTrackedPoint;
		std::vector<ofVec3f> trackedPoints;/* = {
			ofVec3f(50, 50, 50), 
			ofVec3f(150, 150, 150), 
			ofVec3f(250, 250, 250), 
			ofVec3f(350, 350, 350)};*/
	};
}

