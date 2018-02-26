#pragma once
#include "ofMain.h"

namespace iFish
{
	typedef ofPtr<class InterfaceLayout> InterfaceLayoutPtr;

	class InterfaceLayout
	{
	public:
		InterfaceLayout();

		ofEvent<void> changeArtEvent;

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual ~InterfaceLayout();

	private:
		// arts vector
	};
}

