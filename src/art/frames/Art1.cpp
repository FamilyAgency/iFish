#include "Art1.h"

using namespace iFish;

Art1::Art1()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 1 init");
	endTime = 1 * 10;
	startTime = ofGetElapsedTimeMillis();
}

void Art1::update()
{
	//if (ofGetElapsedTimeMillis() - startTime >= endTime)
	{
		startTime = ofGetElapsedTimeMillis();
		x = ofGetWindowWidth() * ofNoise(ofGetElapsedTimef());
		y = ofGetWindowHeight() * ofNoise(ofGetElapsedTimef()*-1);
		addPoint(ofVec3f(x, y, 0));
	}	
}

void Art1::draw()
{
	ofBackground(ofColor::white);
	ofSetColor(ofColor(250, 0, 0));

	for (int j = 0; j < points.size(); ++j)
	{
		ofDrawCircle(points[j], 3);
		if (j > 0) 
		{
			ofSetLineWidth(3);
			ofDrawLine(points[j - 1], points[j]);
		}
	}
}

Art1::~Art1()
{

}
