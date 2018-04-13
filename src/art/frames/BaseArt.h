#pragma once
#include "ofMain.h"
#include "../../config/Config.h"


namespace iFish
{
	typedef ofPtr<class BaseArt> BaseArtPtr;

	class BaseArt
	{
	public:
		BaseArt();
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void init(ConfigPtr config);

		void addPoint(ofVec3f);
		void clear();

		void changeColor();

		void showBackground();

		virtual ~BaseArt();
		


	protected:
		// arts vector
		std::vector<std::vector<ofColor>> colors = {
			std::vector<ofColor>{
				ofColor(121, 108, 204),
				ofColor(86, 88, 201),
				ofColor(114, 80, 201),
				ofColor(214, 206, 240),
				ofColor(15, 29, 137)},
			std::vector<ofColor>{
				ofColor(105, 210, 231),
				ofColor(167, 219, 216),
				ofColor(224, 228, 204),
				ofColor(243, 134, 48),
				ofColor(250, 105, 0)},
			std::vector<ofColor>{
				ofColor(254, 67, 101),
				ofColor(252, 157, 154),
				ofColor(249, 205, 173),
				ofColor(200, 200, 169),
				ofColor(131, 175, 155)},
			std::vector<ofColor>{
				ofColor(236, 208, 120),
				ofColor(217, 91, 67),
				ofColor(192, 41, 66),
				ofColor(84, 36, 55),
				ofColor(83, 119, 122)},
					
			std::vector<ofColor>{
				ofColor(119, 79, 56),
				ofColor(224, 142, 121),
				ofColor(241, 212, 175),
				ofColor(236, 229, 206),
				ofColor(197, 224, 220)},
			std::vector<ofColor>{
				ofColor(232, 221, 203),
				ofColor(205, 179, 128),
				ofColor(3, 101, 100),
				ofColor(3, 54, 73),
				ofColor(3, 22, 52)},
			std::vector<ofColor>{
				ofColor(73, 10, 61),
				ofColor(189, 21, 80),
				ofColor(233, 127, 2),
				ofColor(248, 202, 0),
				ofColor(138, 155, 15)},
							
			std::vector<ofColor>{
				ofColor(85, 98, 112),
				ofColor(78, 205, 196),
				ofColor(199, 244, 100),
				ofColor(255, 107, 107),
				ofColor(196, 77, 88)}
		};
		int colorIt;

		std::vector<ofVec3f> points;
	};
}

