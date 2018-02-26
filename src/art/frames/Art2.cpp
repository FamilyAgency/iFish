#include "Art2.h"

using namespace iFish;

Art2::Art2()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 2 init");
}

void Art2::update()
{

}

void Art2::draw()
{
	ofSetColor(ofFloatColor(1, 0, 0));

	float i = 0;
	ofPolyline line;

	while (i < TWO_PI)
	{
		float r = (2 - 2 * sin(i) + sin(i)*sqrt(abs(cos(i))) / (sin(i) + 1.4)) * -80;
		float x = ofGetWidth() / 2 + cos(i) * r;
		float y = ofGetHeight() / 2 + sin(i) * r;
		line.addVertex(ofVec2f(x, y));
		i += 0.005*HALF_PI*0.5;
	}
	line.close();
	line.draw();
}

Art2::~Art2()
{
}
