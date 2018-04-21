#include "Art1.h"

using namespace iFish;

Art1::Art1()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 1 init");
	endTimeForPoint = 1 * 20;
	startTimeForPoint = ofGetElapsedTimeMillis();
}

void Art1::update()
{
	if (ofGetElapsedTimeMillis() - startTimeForPoint >= endTimeForPoint)
	{
		startTimeForPoint = ofGetElapsedTimeMillis();
		x = ofGetWindowWidth() * ofNoise(ofGetElapsedTimef());
		y = ofGetWindowHeight() * ofNoise(ofGetElapsedTimef()*-1);
		addPoint(ofVec3f(x, y, 0));
	}	
	updateChangingColor();
}

void Art1::draw()
{
	fboHolst.begin();

	ofSetColor(255);
	fboHolst.draw(0, 0);
	
	for (int j = num; j < points.size(); ++j)
	{
		ofSetColor(getChangingColor(j % colors[colorIt].size()));
		ofFill();
		switch (rand() % 3)
		{
		case 0:
			ofDrawCircle(points[j], rand() % 8 + 1);
			break;
		case 1:
			ofDrawEllipse(points[j], rand() % 16 + 1, rand() % 16 + 1);
			break;
		case 2:
			ofDrawRectangle(points[j], rand() % 16 + 1, rand() % 16 + 1);
			break;
		default:
			break;
		}
	}
	num = points.size();

	fboHolst.end();

	fboHolst.draw(0, 0);
}

Art1::~Art1()
{

}
