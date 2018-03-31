#include "Art3.h"

using namespace iFish;

Art3::Art3()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 3 init");
	emitter.setup();
	curlNoise.setup(1024 * 256);
}


void Art3::update()
{
	if (points.size() > 1)
	{
		points[points.size() - 2] += (points[points.size() - 1] - points[points.size() - 2]) * 0.2;
		emitter.update(points[points.size() - 2].x, points[points.size() - 2].y);
	}
	curlNoise.update();
}

void Art3::draw()
{
	ofBackground(ofColor::white);
	ofSetColor(ofColor(1, 1, 200));

	if (points.size() > 1)
	{
		ofPushMatrix();
		curlNoise.draw();
		ofSetColor(ofColor::white);
		emitter.draw();
		ofPopMatrix();
	}
}

Art3::~Art3()
{
}
