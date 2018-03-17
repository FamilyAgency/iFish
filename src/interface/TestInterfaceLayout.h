#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"


namespace iFish
{
	enum class InterfaceEventType
	{
		None,
		TrackingStart,
		TrackingStop,
		NewPointCome,

		AddPoint,
		Clear,

		ShowArt1,
		ShowArt2,
		ShowArt3,
		ChangeArt
	};

	typedef ofPtr<class TestInterfaceLayout> TestInterfaceLayoutPtr;

	class TestInterfaceLayout
	{
	public:
		TestInterfaceLayout();

		ofEvent<InterfaceEventType> InterfaceEvent;

		virtual void update();
		virtual void draw();
		virtual ~TestInterfaceLayout();
		virtual void setVisibility(bool isVisible);
		virtual void setPosition(const ofPoint& position);

	protected:
		bool isVisible;
		ofPoint position;
		vector<ofPtr<ofxDatGuiComponent>> components;
	};
}
