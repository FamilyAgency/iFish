#pragma once
#include "ofMain.h"
#include "frames/BaseArt.h"

namespace iFish
{
	enum class ArtType
	{
		None,
		Art1,
		Art2
	};

	typedef ofPtr<class ArtDrawer> ArtDrawerPtr;

	class ArtDrawer
	{
	public:
		ArtDrawer();
		virtual void update();
		virtual void draw();
		virtual void changeArt();

		virtual ~ArtDrawer();

	private:
		std::vector<BaseArtPtr> arts;
		BaseArtPtr currentArt;
		int currentArtIndex = 0;
	};
}

