#pragma once
#include "ofMain.h"
#include "frames/BaseArt.h"
#include "../interface/TestArt1InterfaceLayout.h"


namespace iFish
{
	enum class ArtType
	{
		None,
		Art1,
		Art2
	};

	typedef ofPtr<class ArtDrawer> ArtDrawerPtr;

	class ArtDrawer : public Tracker
	{
	public:
		ArtDrawer();

		virtual void update();
		virtual void draw();
		virtual void changeArt();
		
		void addPointToArt(ofVec3f point);
		void clearArt();

		virtual ~ArtDrawer();

	private:
		std::vector<BaseArtPtr> arts;
		BaseArtPtr currentArt;
		int currentArtIndex = 0;
	};
}

