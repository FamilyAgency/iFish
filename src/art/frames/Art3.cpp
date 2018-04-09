#include "Art3.h"

using namespace iFish;

Art3::Art3()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 3 init");
	//emitter.setup();
	//curlNoise.setup(256 * 256);
	endTime = 1 * 15;
	startTime = ofGetElapsedTimeMillis();
}


void Art3::update()
{
	/*if (ofGetElapsedTimeMillis() - startTime >= endTime)
	{
		startTime = ofGetElapsedTimeMillis();
		x = ofGetWindowWidth() * ofNoise(ofGetElapsedTimef());
		y = ofGetWindowHeight() * ofNoise(ofGetElapsedTimef()*-1);
		addPoint(ofVec3f(x, y, 0));
		emitter.update(points[points.size() - 1].x, points[points.size() - 1].y);
	}
	curlNoise.update();*/
}

void Art3::draw()
{
	/*ofBackgroundGradient(colors[colorIt][0], colors[colorIt][1], OF_GRADIENT_CIRCULAR);
	ofSetColor(colors[colorIt][3]);

	if (points.size() > 1)
	{
		ofPushMatrix();
		curlNoise.draw();
		ofSetColor(colors[colorIt][0]);
		emitter.draw();
		ofPopMatrix();
	}*/
}

Art3::~Art3()
{
}
