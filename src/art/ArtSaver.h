#pragma once
#include "ofMain.h"
#include "../interface/TestArt1InterfaceLayout.h"


namespace iFish
{
	typedef ofPtr<class ArtSaver> ArtSaverPtr;

	class ArtSaver
	{
	public:
		ArtSaver();

		ofEvent<void> artSaverSuccess;
		ofEvent<void> errorEvent;

		void saveArt(ofImage img, std::string path);

		virtual ~ArtSaver();
	};
}
