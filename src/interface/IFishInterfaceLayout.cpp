#include "IFishInterfaceLayout.h"

using namespace iFish;

IFishInterfaceLayout::IFishInterfaceLayout()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "IFish InterfaceLayout init");

	changeArtButton = ofPtr<ofxDatGuiButton>(new ofxDatGuiButton("Change Art"));
	changeArtButton->onButtonEvent(this, &IFishInterfaceLayout::onButtonChangeArtEvent);
	changeArtButton->setPosition(20, 20);
}

void IFishInterfaceLayout::update()
{
	changeArtButton->update();
}

void IFishInterfaceLayout::draw()
{
	changeArtButton->draw();
}

void IFishInterfaceLayout::onButtonChangeArtEvent(ofxDatGuiButtonEvent event)
{
	auto type = InterfaceEventType::ChangeArt;
	ofNotifyEvent(InterfaceEvent, type);
}

IFishInterfaceLayout::~IFishInterfaceLayout()
{

}
