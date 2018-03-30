#pragma once
#include "ofMain.h"
#include "BaseArt.h"
#include "ofxInkSim.h"
#include "SampleBrush.h"

namespace iFish
{
	typedef ofPtr<class Art2> Art2Ptr;

	class Art2 : public BaseArt
	{
	public:
		Art2();
		virtual void update();
		virtual void draw();
		virtual ~Art2();

	private:
		ofxInkSim inkSim;
		SampleBrush brush;

		const double changeConst = 0.2;
		const double epsilonConst = 0.0001;

		bool isDifferent(ofVec3f pointA, ofVec3f pointB);
	};
}

