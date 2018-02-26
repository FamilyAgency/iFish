#pragma once
#include "ofMain.h"
#include "InterfaceLayout.h"
#include "ofxDatGui.h"

namespace iFish
{
	typedef ofPtr<class IFishInterfaceLayout> IFishInterfaceLayoutPtr;

	class IFishInterfaceLayout : public InterfaceLayout
	{
	public:
		IFishInterfaceLayout();		

		virtual void update();
		virtual void draw();
		virtual ~IFishInterfaceLayout();

	private:
		ofPtr<ofxDatGuiButton> changeArtButton;
		void onButtonChangeArtEvent(ofxDatGuiButtonEvent event);
	};
}

