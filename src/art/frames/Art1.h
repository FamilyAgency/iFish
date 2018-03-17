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
		std::vector<std::vector<ofColor>> colors = {
			std::vector<ofColor>{
						ofColor(121, 108, 204),
						ofColor(86, 88, 201),
						ofColor(114, 80, 201),
						ofColor(214, 206, 240),
						ofColor(15, 29, 137)},
			std::vector<ofColor>{
						ofColor(121, 108, 204),
						ofColor(86, 88, 201),
						ofColor(114, 80, 201),
						ofColor(214, 206, 240),
						ofColor(15, 29, 137)}
		};

	};
}

