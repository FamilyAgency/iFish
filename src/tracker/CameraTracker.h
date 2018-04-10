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
		virtual void update() override;
		virtual void draw() override;
		virtual void clear() override;		

		virtual ~CameraTracker();
	};
}

