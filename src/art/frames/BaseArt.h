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
		virtual ~BaseArt();

	private:
		// arts vector
	};
}

