#include "Art1.h"

using namespace iFish;

Art1::Art1()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 1 init");
}

void Art1::update()
{

}

void Art1::draw()
{
	ofSetColor(ofFloatColor(1, 0, 0));
	ofDrawCircle(ofPoint(400, 400), 30);
}

Art1::~Art1()
{

}
