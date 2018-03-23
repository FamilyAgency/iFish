#include "BaseArt.h"

using namespace iFish;

BaseArt::BaseArt()
{
	
}

void BaseArt::addPoint(ofVec3f point)
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Add Point...");
	points.push_back(point);
	draw();
}

void BaseArt::clear()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Clear Art...");
	points.clear();
	draw();
}

BaseArt::~BaseArt()
{

}
