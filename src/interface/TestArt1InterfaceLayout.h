#pragma once
#include "ofMain.h"
#include "TestInterfaceLayout.h"

namespace iFish
{
	typedef ofPtr<class TestArt1InterfaceLayout> TestArt1InterfaceLayoutPtr;

	class TestArt1InterfaceLayout : public TestInterfaceLayout
	{
	public:
		TestArt1InterfaceLayout();

		virtual void update() override;
		virtual void draw() override;
		virtual ~TestArt1InterfaceLayout();

	private:
		ofPtr<ofxDatGuiButton> nextArtBtn;

		void nextArtButtonClicked(ofxDatGuiButtonEvent event);
		
	};
}

