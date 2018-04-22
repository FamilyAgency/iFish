#include "BaseArt.h"

using namespace iFish;


BaseArt::BaseArt()
{
	colorIt = 0;
	changeIt = 0;
	changingCount = 20;
	endTime = 1 * 1;
	startTime = ofGetElapsedTimef();
	alpha = 1;
	betta = 0;
	num = 0;
	setBackgroundColors();
	fboHolst.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
}

void BaseArt::init(ConfigPtr config)
{

}

void BaseArt::addPoint(ofVec3f point)
{
	//ofLog(ofLogLevel::OF_LOG_NOTICE, "Add Point...");
	points.push_back(point);
	draw();
}

void BaseArt::clear()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Clear Art...");
	points.clear();
	num = 0;
}

void BaseArt::clearAll()
{
	clear();

	fboHolst.begin();
	ofBackground(0, 0);
	fboHolst.end();
}

void BaseArt::showBackground()
{
	ofBackgroundGradient(back1, back2, OF_GRADIENT_CIRCULAR);
}

void BaseArt::setBackgroundColors()
{
	back1 = getChangingColor(0);
	back2 = getChangingColor(1);
}

void BaseArt::setAlphaBetta()
{
	alpha = (changingCount - changeIt) / static_cast<float>(changingCount);
	betta = 1 - alpha;
}

void BaseArt::changeColor()
{
	colorIt = ++colorIt % colors.size();
	changeIt = 0;

	setAlphaBetta();
	setBackgroundColors();
}

ofColor BaseArt::getChangingColor(int it)
{
	return colors[colorIt][it] * alpha + colors[(colorIt + 1) % colors.size()][it] * betta;
}

void BaseArt::updateChangingColor()
{
	if (ofGetElapsedTimef() - startTime >= endTime)
	{
		startTime = ofGetElapsedTimef();
		setAlphaBetta();
		if (++changeIt == changingCount)
		{
			changeColor();
		}
		else
		{
			setBackgroundColors();
		}
	}
}

BaseArt::~BaseArt()
{

}
