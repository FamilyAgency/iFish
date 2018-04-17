#pragma once
#include "ofMain.h"
#include "../interface/TestArt1InterfaceLayout.h"
#include "../config/Config.h"

namespace iFish
{
	typedef ofPtr<class ArtSaver> ArtSaverPtr;

	class ArtSaver
	{
	public:
		ArtSaver();
		virtual void init(ConfigPtr config);

		ofEvent<void> artSaverSuccess;
		ofEvent<void> errorEvent;

		void saveArt(ofImage img);
	
		virtual ~ArtSaver();

	private:
		int numberOfSaveArt;

	};
}
