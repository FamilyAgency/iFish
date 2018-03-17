#include "ArtDrawer.h"
#include "frames/Art1.h"
#include "frames/Art2.h"

using namespace iFish;

ArtDrawer::ArtDrawer()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Art Drawer init");

	arts.push_back(BaseArtPtr(new Art1()));
	arts.push_back(BaseArtPtr(new Art2()));

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


void ArtDrawer::addPointToArt()
{
	currentArt->addPoint();
}

void ArtDrawer::clearArt()
{
	currentArt->clear();
}


ArtDrawer::~ArtDrawer()
{

}
