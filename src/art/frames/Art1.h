#pragma once
#include "ofMain.h"
#include "BaseArt.h"


namespace iFish
{
	typedef ofPtr<class Art1> Art1Ptr;

	class Art1 : public BaseArt
	{
	public:
		Art1();

		virtual void update();
		virtual void draw();
		
		virtual ~Art1();

	private:
		// arts vector
	
		int x = 0, y = 0;		
		uint16_t startTimeForPoint, endTimeForPoint;
	};
}

