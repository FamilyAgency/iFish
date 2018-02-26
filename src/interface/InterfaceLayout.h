#pragma once
#include "ofMain.h"

namespace iFish
{
	enum class InterfaceEventType
	{
		None,
		AddPoint,
		ChangeArt,
		ClearArt,
		ResetTimer
	};

	typedef ofPtr<class InterfaceLayout> InterfaceLayoutPtr;

	class InterfaceLayout
	{
	public:
		InterfaceLayout();

		ofEvent<InterfaceEventType> InterfaceEvent;

		virtual void update() = 0;
		virtual void draw() = 0;
		virtual ~InterfaceLayout();

	private:
		// arts vector
	};
}

