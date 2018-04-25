#pragma once
#include "ofMain.h"
#include "Tracker.h"

#include "ofxOpenCv.h"

namespace iFish
{
	typedef ofPtr<class CameraTracker> CameraTrackerPtr;

	class CameraTracker : public Tracker
	{
	public:
		CameraTracker();
		CameraTracker(int width, int height);

		void start();
		void stop();

		virtual void update() override;
		virtual void draw() override;
		virtual void clear() override;

		virtual ~CameraTracker();

		float getVelocity() const;
		unsigned int getPointsNumStored() const;
		const ofVec3f getTrackColorMin() const;
		const ofVec3f getTrackColorMax() const;

		void setTrackColor(ofVec3f vec3fMin, ofVec3f vec3fMax);
		void setTrackUpdate(const float time);
		void setTrackThreshold(const float min, const float max);
		void setColorsFromMousePressed(const int x, const int y, const int acc = 30);
		void setPositionCamera(const ofPoint& position);
        void setCameraRect(int xmin, int xmax, int ymin, int ymax);
        void setEpsilonUpdate(float epsilonUpdate);

        virtual ofVec3f getLastPoint() const;
        virtual std::vector<ofVec3f> getAllPoints() const;

	private:
		void thresholdUpdate();
		void updateCurrentTrackValues();
		float calculateVelocity() const;

		ofVideoGrabber vidGrabber;  // camera
        std::vector<int> devicesID;  // use listDevices() to find out
		enum cameraType { Front, Side };
		cameraType currentType;

		ofxCvColorImage	colorImg;  // current colored image
		ofxCvGrayscaleImage rgbImage[3];  // current non-colored image (3 channels: R, G and B)
		ofxCvGrayscaleImage thresholdedImage;  // current thresholded image

		ofxCvContourFinder contours;


		// colors that we are tracking in RGB values from min to max
		// it can be changed by method SetTrackColor
        ofVec3f trackColorMin, trackColorMax;

		float trackThresholdMin, trackThresholdMax;  // object's size for tracking
		int cameraRect[4];  // rectangle to viewport: (xmin, xmax, ymin, ymax)

		ofVec3f objLocation;  // current position of object
		float objVelocity;  // currect velocity of object

		enum trackState { Tracking, NoTracking };
		trackState currenttrackState;

		int width, height;

		float trackUpdate;  // how soon track is updated (in milliseconds)
        float epsilonDistance;  // how long should object move to update currentTrackPoints
		uint64_t currentUpdate;

		unsigned int pointsNumStored;  // num of points stored in arrays currently
		std::vector<ofVec3f> trackPointsArrayFirst;
		std::vector<ofVec3f> trackPointsArraySecond;
		std::vector<ofVec3f>* currentTrackPoints;

		std::vector<uint64_t> trackTimesArrayFirst;
		std::vector<uint64_t> trackTimesArraySecond;
		std::vector<uint64_t>* currentTrackTimes;


		ofPoint positionCamera;  // camera position in application
	};

}