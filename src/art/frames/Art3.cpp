#include "Art3.h"

using namespace iFish;

Art3::Art3()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 3 init");
	emitter.setup();
	curlNoise.setup(256 * 1024);
	endTimeForPoint = 1 * 5;
	startTimeForPoint = ofGetElapsedTimeMillis();
}


void Art3::update()
{
	if (ofGetElapsedTimeMillis() - startTimeForPoint >= endTimeForPoint)
	{
		startTimeForPoint = ofGetElapsedTimeMillis();
		//x = ofGetWindowWidth() * ofNoise(ofGetElapsedTimef());
		//y = ofGetWindowHeight() * ofNoise(ofGetElapsedTimef()*-1);
		//addPoint(ofVec3f(x, y, 0));

		if (points.size() > 0)
		{
			emitter.update(points[points.size() - 1].x, points[points.size() - 1].y);
		}
	}
	curlNoise.update();
	updateChangingColor();
}

void Art3::draw()
{
	//ofSetColor(colors[colorIt][3]);
	ofSetColor(getChangingColor(3));

	if (points.size() > 1)
	{
		ofPushMatrix();
		curlNoise.draw();
		ofSetColor(getChangingColor(0));
		emitter.draw();
		ofPopMatrix();
	}
}

Art3::~Art3()
{
}
