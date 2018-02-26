#include "Config.h"

using namespace iFish;

Config::Config()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Config init");	
}

void Config::load()
{
	ofNotifyEvent(loadCompleteEvent, this);
}

Config::~Config()
{

}
