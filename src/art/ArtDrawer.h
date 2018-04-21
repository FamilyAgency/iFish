#pragma once
#include "ofMain.h"
#include "frames/BaseArt.h"
#include "../interface/TestArt1InterfaceLayout.h"
#include "ofFbo.h"


namespace iFish
{
	enum class ArtType
	{
		None,
		Art1,
		Art2,
		Art3
	};

	typedef ofPtr<class ArtDrawer> ArtDrawerPtr;

	class ArtDrawer : public Tracker
	{
	public:
		ArtDrawer();

		virtual void update();
		virtual void draw();
		virtual void init(ConfigPtr config);
		virtual void changeArt();
		
		virtual void changeColor();

		void addPointToArt(ofVec3f point);
		void clearArt();

		ofImage getArt();
		void updateFBO();

		virtual ~ArtDrawer();

	private:
		std::vector<BaseArtPtr> arts;
		BaseArtPtr currentArt;
		int currentArtIndex = 0;

		ofFbo fboHolst;

		uint16_t startTime, endTime;
	};
}

