#include "Config.h"
 



using namespace iFish;

LoadType loadType = LoadType::Url;
CameraData cameraData;
ArtData artData;
PlannerData plannerData;


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

vector<CameraData> Config::getCamerasData() const

{

	return CamerasData;
}


ArtData Config::getArtData() const

{
	return artData;

}

PlannerData Config::getPlannerData() const

{
	return plannerData;


}

void ConfigParser::parse(ConfigPtr config, const string& configString) {
	switch(loadType)
	{
		case(LoadType::LocalFile):
		{
			parsingSuccessful = json.openLocal(configString);

			if (parsingSuccessful)
			{
				ofLogNotice("ofApp::setup") << json.getRawString(true);
			}
			else {
				ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
			}

			cameraData.width = json["CameraData"]["width"].asInt();
			cameraData.height = json["CameraData"]["height"].asInt();
			std::string trackColorMin = json["CameraData"]["trackColorMin"].asString();
			std::string trackColorMax = json["CameraData"]["trackColorMax"].asString();
			cameraData.trackUpdateMs = json["CameraData"]["trackUpdateMs"].asInt();
			cameraData.trackThresholdMin = json["CameraData"]["trackThresholdMin"].asInt();
			cameraData.trackThresholdMax = json["CameraData"]["trackThresholdMax"].asInt();

			artData.artDrawNumber = json["ArtData"]["artDrawNumber"].asInt();
			artData.artFboUpdateMs = json["ArtData"]["artFboUpdateMs"].asInt();
			std::string palletesPath = json["ArtData"]["palletesPath"].asString();

			plannerData.drawTimeMax = json["PlannerData"]["drawTimeMax"].asInt();
			plannerData.saveArtAtEndDay = json["PlannerData"]["saveArtAtEndDay"].asBool();
		}
	
		case(LoadType::Url):

		{
			parsingSuccessful = json.open(configString);

			if (parsingSuccessful)
			{
				ofLogNotice("ofApp::setup") << json.getRawString(true);
			}
			else {
				ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
			}

			cameraData.width = json["CameraData"]["width"].asInt();
			cameraData.height = json["CameraData"]["height"].asInt();
			std::string trackColorMin = json["CameraData"]["trackColorMin"].asString();
			std::string trackColorMax = json["CameraData"]["trackColorMax"].asString();
			cameraData.trackUpdateMs = json["CameraData"]["trackUpdateMs"].asInt();
			cameraData.trackThresholdMin = json["CameraData"]["trackThresholdMin"].asInt();
			cameraData.trackThresholdMax = json["CameraData"]["trackThresholdMax"].asInt();

			artData.artDrawNumber = json["ArtData"]["artDrawNumber"].asInt();
			artData.artFboUpdateMs = json["ArtData"]["artFboUpdateMs"].asInt();
			std::string palletesPath = json["ArtData"]["palletesPath"].asString();

			plannerData.drawTimeMax = json["PlannerData"]["drawTimeMax"].asInt();
			plannerData.saveArtAtEndDay = json["PlannerData"]["saveArtAtEndDay"].asBool();

		}

		case(LoadType::Resource):
		{
			parsingSuccessful = json.open(configString);

			if (parsingSuccessful)
			{
				ofLogNotice("ofApp::setup") << json.getRawString(true);
			}
			else {
				ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
			}

			cameraData.width = json["CameraData"]["width"].asInt();
			cameraData.height = json["CameraData"]["height"].asInt();
			std::string trackColorMin = json["CameraData"]["trackColorMin"].asString();
			std::string trackColorMax = json["CameraData"]["trackColorMax"].asString();
			cameraData.trackUpdateMs = json["CameraData"]["trackUpdateMs"].asInt();
			cameraData.trackThresholdMin = json["CameraData"]["trackThresholdMin"].asInt();
			cameraData.trackThresholdMax = json["CameraData"]["trackThresholdMax"].asInt();

			artData.artDrawNumber = json["ArtData"]["artDrawNumber"].asInt();
			artData.artFboUpdateMs = json["ArtData"]["artFboUpdateMs"].asInt();
			std::string palletesPath = json["ArtData"]["palletesPath"].asString();

			plannerData.drawTimeMax = json["PlannerData"]["drawTimeMax"].asInt();
			plannerData.saveArtAtEndDay = json["PlannerData"]["saveArtAtEndDay"].asBool();
		}

		case(LoadType::None):
		{
			ofLogNotice("ofApp::setup") << "There is no file to parse!";
		}

	
	}



}
