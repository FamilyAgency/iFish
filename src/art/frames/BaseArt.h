#pragma once
#include "ofMain.h"

namespace iFish
{
	typedef ofPtr<class BaseArt> BaseArtPtr;

	class BaseArt
	{
	public:
		BaseArt();
		virtual void update() = 0;
		virtual void draw() = 0;

		void addPoint();
		void clear();

		virtual ~BaseArt();

	protected:
		// arts vector
		std::vector<ofVec3f> points;
	};
}

