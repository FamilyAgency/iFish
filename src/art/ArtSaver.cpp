#include "ArtSaver.h"

using namespace iFish;

ArtSaver::ArtSaver()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Art Saver init");

}

void ArtSaver::saveArt(ofImage img, std::string path)
{
	img.save(path);
}

ArtSaver::~ArtSaver()
{

}
