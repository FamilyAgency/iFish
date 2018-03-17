#include "BaseArt.h"

using namespace iFish;

BaseArt::BaseArt()
{
	
}

void BaseArt::addPoint()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Add Point...");
	points.push_back(ofVec3f(rand() % 1000, rand() % 1000, 0));
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
