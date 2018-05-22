#pragma once
#include "ofMain.h"
#include "../interface/TestTrackerInterfaceLayout.h"

namespace iFish
{
	typedef ofPtr<class Tracker> TrackerPtr;

	class Tracker 
	{
	public:
		Tracker();

		ofEvent<InterfaceEventType> newPointEvent;
		ofEvent<ofVec3f> errorEvent;

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void clear();
		virtual void addPointToTracker();
		virtual ofVec3f getLastPoint() const;
		virtual std::vector<ofVec3f> getAllPoints() const;

		virtual ~Tracker();		

	protected:
		ofVec3f lastTrackedPoint;
		std::vector<ofVec3f> trackedPoints;
	};
}/*
#pragma once
#include "ofMain.h"

namespace iFish
{
	typedef ofPtr<class Tracker> TrackerPtr;

	class Tracker
	{
	public:
		Tracker();

		ofEvent<ofVec3f> newPointEvent;  // TODO
		ofEvent<ofVec3f> errorEvent;  // TODO

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void clear();

		virtual ofVec3f getLastPoint() const;
		virtual std::vector<ofVec3f> getAllPoints() const;

		virtual ~Tracker();

	protected:
		ofVec3f lastTrackedPoint;
		std::vector<ofVec3f> trackedPoints;
	};
}


*/