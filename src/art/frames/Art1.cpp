#include "Art1.h"

using namespace iFish;

Art1::Art1()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 1 init");
	endTime = 1 * 15;
	startTime = ofGetElapsedTimeMillis();
}

void Art1::update()
{
	if (ofGetElapsedTimeMillis() - startTime >= endTime)
	{
		startTime = ofGetElapsedTimeMillis();
		x = ofGetWindowWidth() * ofNoise(ofGetElapsedTimef());
		y = ofGetWindowHeight() * ofNoise(ofGetElapsedTimef()*-1);
		addPoint(ofVec3f(x, y, 0));
	}	
}

void Art1::draw()
{
	//ofBackground(colors[colorIt][0]);

	for (int j = 0; j < points.size(); ++j)
	{
		ofSetColor(colors[colorIt][j % colors[colorIt].size()]);
		ofFill();
		ofDrawCircle(points[j], j % 5 + 1);
	}
}

Art1::~Art1()
{

}
