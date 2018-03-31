#include "ArtDrawer.h"
#include "frames/Art1.h"
#include "frames/Art2.h"
#include "frames/Art3.h"

using namespace iFish;

ArtDrawer::ArtDrawer()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Art Drawer init");

	arts.push_back(BaseArtPtr(new Art1()));
	arts.push_back(BaseArtPtr(new Art2()));
	arts.push_back(BaseArtPtr(new Art3()));

	currentArtIndex = 0;
	currentArt = arts[currentArtIndex];
}

void ArtDrawer::update()
{
	currentArt->update();
}

void ArtDrawer::draw()
{
	currentArt->draw();
}

void ArtDrawer::changeArt()
{
	currentArtIndex = (currentArtIndex + 1) % arts.size();
	currentArt = arts[currentArtIndex];

	ofLog(ofLogLevel::OF_LOG_NOTICE, "Change Art...");
}


void ArtDrawer::addPointToArt(ofVec3f point)
{
	currentArt->addPoint(point);
}

void ArtDrawer::clearArt()
{
	currentArt->clear();
}


ArtDrawer::~ArtDrawer()
{

}
