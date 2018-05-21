#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

namespace iFish
{

	enum class LoadType
	{
		None,
		LocalFile,
		Url,
		Resource

	};

	struct CameraData
	{
		int width;
		int height;
		vector<int> trackColorMin;
		vector<int> trackColorMax;
		int trackUpdateMs;
		int trackThresholdMin;
		int trackThresholdMax;
	};

	struct ArtData
	{
		int artDrawNumber;
		int artFboUpdateMs;
		vector<ofColor> palletes;
	};

	struct PlannerData
	{
		int drawTimeMax;
		bool saveArtAtEndDay;
	};

	typedef shared_ptr<class Config> ConfigPtr;



	class Config

	{

	public:

		Config();
		vector<CameraData> getCamerasData() const;
		ArtData getArtData() const;
		PlannerData getPlannerData() const;

		ofEvent<void> loadCompleteEvent;
		ofEvent<void> loadErrorEvent;

		virtual void load();


		virtual ~Config();

	private:

		vector<CameraData> CamerasData;
	};


	class ConfigController

	{

	public:

		ConfigController();
		void init(const string& path, LoadType type = LoadType::LocalFile);
		void onConfigLoadSuccess(string& rawConfig);
		void onConfigLoadError();

		virtual void load();
		virtual ~ConfigController();

	private:
		string configPath;
		ConfigLoader configLoader;
		ConfigParser configParser;
		ConfigPtr config;

	};

	class ConfigLoader

	{

	public:

		void load(const string& param, LoadType type = LoadType::LocalFile);

	};

	class ConfigParser

	{

	public:

		void parse(ConfigPtr config, const string& configString);

	private:
		ofxJSONElement json;
		bool parsingSuccessful;
	};

}
#pragma once
