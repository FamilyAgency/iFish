#include "BaseArt.h"

using namespace iFish;


BaseArt::BaseArt()
{
	colorIt = 0;
}

void BaseArt::addPoint(ofVec3f point)
{
	//ofLog(ofLogLevel::OF_LOG_NOTICE, "Add Point...");
	points.push_back(point);
	draw();
}

void BaseArt::clear()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Clear Art...");
	points.clear();
	showBackground();
	draw();
}

void BaseArt::showBackground()
{
	ofBackground(colors[colorIt][0]);
}

void BaseArt::changeColor()
{
	colorIt = ++colorIt % colors.size();
}

BaseArt::~BaseArt()
{

}
