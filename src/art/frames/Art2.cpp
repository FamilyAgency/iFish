#include "Art2.h"

using namespace iFish;

Art2::Art2()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 2 init");
	inkSim.setup();
	//inkSim.setDrawMode(ofxInkSim::INKFIX);
	//inkSim.setDrawMode(ofxInkSim::INKSURF);
	inkSim.setDrawMode(ofxInkSim::INKFLOW);
}

bool Art2::isDifferent(ofVec3f pointA, ofVec3f pointB)
{
	return abs((pointB - pointA).x) > epsilonConst || abs((pointB - pointA).y) > epsilonConst || 
		abs((pointB - pointA).z) > epsilonConst;
}

void Art2::update()
{
	if (points.size() > 1 && isDifferent(points[points.size() - 2], points[points.size() - 1]))
	{
		points[points.size() - 2] += (points[points.size() - 1] - points[points.size() - 2]) * changeConst;
		inkSim.stroke(&brush, points[points.size() - 2].x, points[points.size() - 2].y, 
			getInkColor(rand() % 255, rand() % 255, rand() % 255), 5);
	} else if(points.size() == 0)
	{
		inkSim.clear();
	}
	inkSim.update();
}

void Art2::draw()
{
	inkSim.draw();
}

Art2::~Art2()
{
}
