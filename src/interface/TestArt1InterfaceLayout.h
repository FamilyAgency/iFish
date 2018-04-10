#pragma once
#include "ofMain.h"
#include "TestInterfaceLayout.h"
#include "../tracker/Tracker.h"


namespace iFish
{
	typedef ofPtr<class TestArt1InterfaceLayout> TestArt1InterfaceLayoutPtr;

	class TestArt1InterfaceLayout : public TestInterfaceLayout, Tracker
	{
	public:
		TestArt1InterfaceLayout();

		virtual void update() override;
		virtual void draw() override;

		virtual ~TestArt1InterfaceLayout();

	private:
		ofPtr<ofxDatGuiButton> /*addPointButton, */clearButton, changeArtButton, changeColorButton, saveArtButton;

		//void addPointButtonClicked(ofxDatGuiButtonEvent event);
		void clearButtonClicked(ofxDatGuiButtonEvent event);
		void changeArtButtonClicked(ofxDatGuiButtonEvent event);
		void changeColorButtonClicked(ofxDatGuiButtonEvent event);
		void saveArtButtonClicked(ofxDatGuiButtonEvent event);
	};
}
