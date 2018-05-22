#include "Art1.h"

using namespace iFish;

Art1::Art1()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Concrete Art 1 init");
	endTimeForPoint = 1 * 20;
	startTimeForPoint = ofGetElapsedTimeMillis();
	drawType = DrawType::RandomFigure;
}

void Art1::update()
{
	if (ofGetElapsedTimeMillis() - startTimeForPoint >= endTimeForPoint)
	{
		startTimeForPoint = ofGetElapsedTimeMillis();
		//x = ofGetWindowWidth() * ofNoise(ofGetElapsedTimef());
		//y = ofGetWindowHeight() * ofNoise(ofGetElapsedTimef()*-1);
		//addPoint(ofVec3f(x, y, 0));
	}	
	updateChangingColor();
}

void Art1::draw()
{
	fboHolst.begin();

	ofSetColor(255);
	fboHolst.draw(0, 0);
	
	ofSetLineWidth(2);
	//ofSetStyle();
	
	for (int j = num; j < points.size(); ++j)
	{
		ofSetColor(getChangingColor(j % colors[colorIt].size()));
		if (j > 0)
		{
			ofDrawLine(points[j - 1], points[j]);
		}
		ofFill();

	}
	for (int j = num; j < points.size(); ++j)
	{
		ofSetColor(getChangingColor(j % colors[colorIt].size()));
		drawCurrentPicture(j);
		ofFill();
	}
	num = points.size();

	fboHolst.end();

	fboHolst.draw(0, 0);
}

void Art1::drawCurrentPicture(int j)
{
	switch (drawType)
	{
	case DrawType::Circle1:
		ofDrawCircle(points[j], j % 8 + 1);
		break;

	case DrawType::Circle2:
		ofDrawCircle(points[j], rand() % 8 + 1);
		break;

	case DrawType::RandomFigure:
		drawRandomStuff(j);
		break;
	}	
}

void Art1::drawRandomStuff(int j)
{
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
	}	
}

Art1::~Art1()
{

}
