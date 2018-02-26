#pragma once
#include "ofMain.h"
#include "Tracker.h"

namespace iFish
{
	typedef ofPtr<class CameraTracker> CameraTrackerPtr;

	class CameraTracker: public Tracker
	{
	public:
		CameraTracker();
		virtual void update();
		virtual void draw();
		virtual ~CameraTracker();
	};
}

