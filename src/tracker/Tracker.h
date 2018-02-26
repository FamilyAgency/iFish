#pragma once
#include "ofMain.h"

namespace iFish
{
	typedef ofPtr<class Tracker> TrackerPtr;

	class Tracker
	{
	public:
		Tracker();
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual ~Tracker();
	};
}

