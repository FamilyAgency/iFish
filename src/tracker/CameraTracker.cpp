#include "CameraTracker.h"

using namespace iFish;


CameraTracker::CameraTracker()
{
	CameraTracker(320, 240);
}

CameraTracker::CameraTracker(int width_, int height_)
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker init");

	width = width_;
	height = height_;
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker width = " + ofToString(width));
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker height = " + ofToString(height));

	vidGrabber.setVerbose(true);
	vidGrabber.setup(width, height);

	colorImg.allocate(width, height);
	rgbImage[0].allocate(width, height);
	rgbImage[1].allocate(width, height);
	rgbImage[2].allocate(width, height);
	thresholdedImage.allocate(width, height);

	currentUpdate = 1;
	currentTrackPoints = &trackPoints_one;
	currentTrackTimes = &trackTimes_one;
	pointsNumStored = 0;

	// Default значения для трекинга
	trackUpdate = 0.;  // миллисекунды
	trackThreshold_min = 50;
	trackThreshold_max = width * height / 2;
	setTrackColor(0, 0, 0, 255, 255, 255);
	objVelocity = 0;
	positionCamera.set(0, 0);

	currenttrackState = NoTracking;
}

void CameraTracker::init(ConfigPtr config)
{

}

void CameraTracker::setTrackColor(unsigned int red_min, unsigned int green_min, \
																	unsigned int blue_min, unsigned int red_max, \
																	unsigned int green_max, unsigned int blue_max)
{
	trackColor_min[0] = red_min;
	trackColor_min[1] = green_min;
	trackColor_min[2] = blue_min;
	trackColor_max[0] = red_max;
	trackColor_max[1] = green_max;
	trackColor_max[2] = blue_max;
}

void CameraTracker::setTrackUpdate(float time_)
{
	trackUpdate = time_;
}

void CameraTracker::setTrackThreshold(float min_, float max_)
{
	trackThreshold_min = min_;
	trackThreshold_max = max_;
}

void CameraTracker::start()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker start");

	currenttrackState = Tracking;
}

void CameraTracker::stop()
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker stop");

	currenttrackState = NoTracking;
}

void CameraTracker::updateCurrentTrackValues()
{
	if (currentTrackPoints == &trackPoints_one)
	{
		if (trackPoints_one.size() == trackPoints_one.max_size() - 1)
		{
			trackPoints_two.clear();
			currentTrackPoints = &trackPoints_two;
			trackTimes_two.clear();
			currentTrackTimes = &trackTimes_two;
		}
	}
	else if (trackPoints_two.size() == trackPoints_two.max_size() - 1)
	{
		trackPoints_one.clear();
		currentTrackPoints = &trackPoints_one;
		trackTimes_one.clear();
		currentTrackTimes = &trackTimes_one;
	}

	pointsNumStored = trackPoints_one.size() + trackPoints_two.size();
}

void CameraTracker::thresholdUpdate()
{
	// convert to hsb
	//colorImg.convertRgbToHsv();

	// store the three channels as grayscale images
	colorImg.convertToGrayscalePlanarImages(rgbImage[0], rgbImage[1], rgbImage[2]);

	// filter image based on the hue value were looking for
	for (int i = 0; i < width*height; i++)
	{
		bool color_i = true;
		for (int k = 0; k < 3; k++)
		{
			color_i = color_i && ofInRange(rgbImage[k].getPixels()[i], \
																		trackColor_min[k], trackColor_max[k]);
		}
		thresholdedImage.getPixels()[i] = color_i ? 255 : 0;
	}
	thresholdedImage.flagImageChanged();

	// find one blob
	contours.findContours(thresholdedImage, trackThreshold_min, \
												trackThreshold_max, 1, false);

	if (contours.nBlobs > 0)
	{
		objLocation = contours.blobs[0].centroid;
		currentTrackPoints->push_back(objLocation);
		currentTrackTimes->push_back(ofGetElapsedTimeMillis());
		objVelocity = calculateVelocity();

		//ofLog(ofLogLevel::OF_LOG_NOTICE, "Velocity" + std::to_string(objVelocity));

		updateCurrentTrackValues();
	}
}

void CameraTracker::update()
{
	uint64_t currentTime = ofGetElapsedTimeMillis();

	if (trackUpdate == 0. || currentTime - currentUpdate * trackUpdate >= 0.)
	{
		if (trackUpdate > 0.)
		{
			currentUpdate++;
		}

		vidGrabber.update();
		if (vidGrabber.isFrameNew())
		{
			colorImg.setFromPixels(vidGrabber.getPixels());
			if (currenttrackState == Tracking)
			{
				thresholdUpdate();
			}
		}
	}
}

void CameraTracker::draw()
{
	ofSetColor(255, 255, 255);
	colorImg.draw(positionCamera);

	if (currenttrackState == Tracking)
	{
		contours.draw(positionCamera);

		// draw red circles for found blob
		ofSetColor(255, 0, 0);
		ofFill();
		if (contours.nBlobs == 1)
		{
			ofCircle(positionCamera.x + contours.blobs[0].centroid.x, \
							positionCamera.y + contours.blobs[0].centroid.y, 10);
		}
	}
}

void CameraTracker::clear()
{
	Tracker::clear();
}

CameraTracker::~CameraTracker()
{
	// TODO: посмотреть, что можно очистить?
}

float CameraTracker::calculateVelocity() const
{
	int i_min = 0;
	if (currentTrackPoints->size() > 3)
	{
		i_min = currentTrackPoints->size() - 3;
	}

	float velocity = 0.;
	int points_size = currentTrackPoints->size() - i_min;

	for (int i = currentTrackPoints->size() - 1; i >= i_min + 1; i--)
	{
		float delta_point_x = (*currentTrackPoints)[i].x - (*currentTrackPoints)[i - 1].x;
		float delta_point_y = (*currentTrackPoints)[i].y - (*currentTrackPoints)[i - 1].y;
		float delta_point_z = (*currentTrackPoints)[i].z - (*currentTrackPoints)[i - 1].z;

		float delta_time = (*currentTrackTimes)[i] - (*currentTrackTimes)[i - 1];

		float velocity_x = delta_point_x / delta_time;
		float velocity_y = delta_point_y / delta_time;
		float velocity_z = delta_point_z / delta_time;

		velocity += velocity_x * velocity_x + velocity_y * velocity_y + \
								velocity_z * velocity_z;
	}

	velocity = velocity / points_size;

	return velocity;
}

float CameraTracker::getVelocity() const
{
	return objVelocity;
}

unsigned int CameraTracker::getPointsNumStored() const
{
	return pointsNumStored;
}

void CameraTracker::setColorsFromMousePressed(int x, int y, int acc)
{
	if (currenttrackState == Tracking)
	{
		// calculate local mouse x, y in image
		x = x - int(positionCamera.x);
		y = y - int(positionCamera.y);

		// get color values on mouse position
		int red = rgbImage[0].getPixels()[y*width + x];
		int green = rgbImage[1].getPixels()[y*width + x];
		int blue = rgbImage[2].getPixels()[y*width + x];

		trackColor_min[0] = std::max(0, red - acc);
		trackColor_max[0] = std::min(255, red + acc);
		trackColor_min[1] = std::max(0, green - acc);
		trackColor_max[1] = std::min(255, green + acc);
		trackColor_min[2] = std::max(0, blue - acc);
		trackColor_max[2] = std::min(255, blue + acc);
	}
}

void CameraTracker::setPositionCamera(const ofPoint& position)
{
	positionCamera = position;
}

const unsigned int* CameraTracker::getTrackColorMin() const
{
	return trackColor_min;
}

const unsigned int* CameraTracker::getTrackColorMax() const
{
	return trackColor_max;
}