#include "ArtSaver.h"

using namespace iFish;

ArtSaver::ArtSaver()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Art Saver init");
	numberOfSaveArt = 0;

}

void ArtSaver::init(ConfigPtr config)
{

}

void ArtSaver::saveArt(ofImage img)
{
	img.save("images\\" + std::to_string(numberOfSaveArt++) + ".png");
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Save Art...");
}

ArtSaver::~ArtSaver()
{

}
