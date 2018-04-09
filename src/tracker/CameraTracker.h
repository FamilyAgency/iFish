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
		CameraTracker(int width_, int height_);

		void start();
		void stop();

		virtual void update() override;
		virtual void draw() override;
		virtual void clear() override;

		virtual ~CameraTracker();

		float getVelocity() const;
		unsigned int getPointsNumStored() const;
		const unsigned int* getTrackColorMin() const;
		const unsigned int* getTrackColorMax() const;

		void setTrackColor(const unsigned int red_min, const unsigned int green_min, \
											const unsigned int blue_min, const unsigned int red_max, \
											const unsigned int green_max, const unsigned int blue_max);
		void setTrackColorAccuracy(const unsigned int acc);
		void setTrackUpdate(const float time);
		void setTrackThreshold(const float min_, const float max_);
		void setColorsFromMousePressed(const int x, const int y, const int acc = 30);
		void setPositionCamera(const ofPoint& position);

	private:
		void thresholdUpdate();
		void updateCurrentTrackValues();
		float calculateVelocity() const;

		ofVideoGrabber vidGrabber;  // камера
		// vector<Camera> - массив камер; TODO: использовать listDevices()
		enum cameraType { Front, Side };
		cameraType currentType;

		ofxCvColorImage	colorImg;  // текущее цветное изображение
		ofxCvGrayscaleImage rgbImage[3];  // текущее черно-белое изображение по каналам
		ofxCvGrayscaleImage thresholdedImage;  // текущее пороговое изображение

		ofxCvContourFinder contours;  // "контуры"


		// цвет, который трекаем в диапазонах RGB от минимума до максимума
		// редактируется через метод SetTrackColor
		unsigned int trackColor_min[3];
		unsigned int trackColor_max[3];

		float trackThreshold_min, trackThreshold_max;  // размеры объекта для трекинга
		int cameraRect[4];  // TODO: прямоугольник в пространстве, который нужно привести к вьюпорту

		ofVec3f objLocation;  // текущая позиция объекта
		float objVelocity;  // скорость объекта

		enum trackState { Tracking, NoTracking };  // состояния трекинга
		trackState currenttrackState;  // текущее состояние трекинга

		int width, height;

		float trackUpdate;  // как частo фиксируем позицию (в миллисекундах)
		uint64_t currentUpdate;

		unsigned int pointsNumStored;  // количество точек, которые хранятся
		std::vector<ofVec3f> trackPoints_one;
		std::vector<ofVec3f> trackPoints_two;
		std::vector<ofVec3f>* currentTrackPoints;

		std::vector<uint64_t> trackTimes_one;
		std::vector<uint64_t> trackTimes_two;
		std::vector<uint64_t>* currentTrackTimes;


		ofPoint positionCamera;  // положение камеры в приложении
	};

}