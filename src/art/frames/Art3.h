#pragma once
#include "ofMain.h"
#include "BaseArt.h"
//#include "ofxCurlNoise.h"
#include "ofxGui.h"


namespace iFish
{
	typedef ofPtr<class Art3> Art3Ptr;

	class Art3 : public BaseArt
	{
	public:
		Art3();
		virtual void update();
		virtual void draw();
		virtual ~Art3();

	private:
		//ParticleEmitter emitter;
		//ofxCurlNoise curlNoise;

		int x = 0, y = 0;
		uint16_t startTimeForPoint, endTimeForPoint;
	};
}

