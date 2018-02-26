#pragma once
#include "ofMain.h"
#include "BaseArt.h"

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
		// arts vector
	};
}

