#include "ArtDrawer.h"
#include "frames/Art1.h"
#include "frames/Art2.h"
#include "frames/Art3.h"

using namespace iFish;

ArtDrawer::ArtDrawer()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Art Drawer init");

	arts.push_back(BaseArtPtr(new Art1()));
	//arts.push_back(BaseArtPtr(new Art2()));
	//arts.push_back(BaseArtPtr(new Art3()));

	currentArtIndex = 0;
	currentArt = arts[currentArtIndex];

	fboHolst.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 1);

	endTime = 1 * 5;
	startTime = ofGetElapsedTimef();

	updateFBO();
}

void ArtDrawer::init(ConfigPtr config)
{

}

void ArtDrawer::update()
{
	if (ofGetElapsedTimef() - startTime >= endTime)
	{
		startTime = ofGetElapsedTimef();
		updateFBO();
	}
	currentArt->update();
}

void ArtDrawer::draw()
{
	fboHolst.draw(0, 0);
	currentArt->draw();
}

void ArtDrawer::changeArt()
{
	currentArtIndex = (currentArtIndex + 1) % arts.size();
	currentArt = arts[currentArtIndex];
	clearArt();

	ofLog(ofLogLevel::OF_LOG_NOTICE, "Change Art...");
}

void ArtDrawer::changeColor()
{
	currentArt->changeColor();
	clearArt();

	ofLog(ofLogLevel::OF_LOG_NOTICE, "Change Color...");
}

void ArtDrawer::addPointToArt(ofVec3f point)
{
	currentArt->addPoint(point);
}

void ArtDrawer::clearArt()
{
	currentArt->clear();
	clearFBO();
}

ofImage ArtDrawer::getArt() {
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Get Art...");
	ofImage img;
	updateFBO();
	fboHolst.readToPixels(img.getPixelsRef());
	img.update();
	return img;
}

void ArtDrawer::updateFBO()
{
	fboHolst.begin();
	currentArt->showBackground();
	fboHolst.draw(0, 0);
	currentArt->draw();
	fboHolst.end();
	currentArt->clear();
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Save To FBO...");
}

void ArtDrawer::clearFBO()
{
	fboHolst.begin();
	currentArt->showBackground();
	fboHolst.end();

	startTime = ofGetElapsedTimef();
	updateFBO();
}

ArtDrawer::~ArtDrawer()
{

}
