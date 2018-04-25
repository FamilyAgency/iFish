#include "CameraTracker.h"

using namespace iFish;


CameraTracker::CameraTracker()
{
	CameraTracker(320, 240);
}

CameraTracker::CameraTracker(int width, int height)
{
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker init");

	this->width = width;
	this->height = height;
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker width = " + ofToString(width));
	ofLog(ofLogLevel::OF_LOG_NOTICE, "Camera Tracker height = " + ofToString(height));

    devicesID = { Front, Side };
    currentType = Front;
    vidGrabber.listDevices();
    vidGrabber.setDeviceID(Front);
    vidGrabber.setVerbose(true);
    vidGrabber.setup(width, height);

	colorImg.allocate(width, height);
	rgbImage[0].allocate(width, height);
	rgbImage[1].allocate(width, height);
	rgbImage[2].allocate(width, height);
	thresholdedImage.allocate(width, height);

	currentUpdate = 1;
	currentTrackPoints = &trackPointsArrayFirst;
	currentTrackTimes = &trackTimesArrayFirst;
	pointsNumStored = 0;
    objVelocity = 0.;
    currenttrackState = NoTracking;

	// Default values for tracking
    setTrackUpdate(0.);  // in milliseconds
    setTrackThreshold(50, width * height / 2);
    setTrackColor(ofVec3f(0, 0, 0), ofVec3f(255, 255, 255));
    setEpsilonUpdate(0.);
    setCameraRect(0, width, 0, height);
    setPositionCamera(ofPoint(0, 0));
}

void CameraTracker::setTrackColor(ofVec3f vecMin, ofVec3f vecMax)
{
    trackColorMin = vecMin;
    trackColorMax = vecMax;
}

void CameraTracker::setTrackUpdate(float time)
{
	trackUpdate = time;
}

void CameraTracker::setTrackThreshold(float min, float max)
{
	trackThresholdMin = min;
	trackThresholdMax = max;
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
	if (currentTrackPoints == &trackPointsArrayFirst)
	{
		if (trackPointsArrayFirst.size() == trackPointsArrayFirst.max_size() - 1)
		{
			trackPointsArraySecond.clear();
			currentTrackPoints = &trackPointsArraySecond;
			trackTimesArraySecond.clear();
			currentTrackTimes = &trackTimesArraySecond;
		}
	}
	else if (trackPointsArraySecond.size() == trackPointsArraySecond.max_size() - 1)
	{
		trackPointsArrayFirst.clear();
		currentTrackPoints = &trackPointsArrayFirst;
		trackTimesArrayFirst.clear();
		currentTrackTimes = &trackTimesArrayFirst;
	}

	pointsNumStored = trackPointsArrayFirst.size() + trackPointsArraySecond.size();
}

void CameraTracker::thresholdUpdate()
{
	// convert to hsb (if need more accurancy? i dunno)
	//colorImg.convertRgbToHsv();

	// store the three channels as grayscale images
	colorImg.convertToGrayscalePlanarImages(rgbImage[0], rgbImage[1], rgbImage[2]);

	// filter image based on the hue value were looking for
    // The equivalent statement to "get(x, y)" is "pixels[y*width+x]".
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            bool colorXY = true;
            for (int k = 0; k < 3; k++)
            {
                colorXY = colorXY && ofInRange(rgbImage[k].getPixels()[y*width+x], 
                    trackColorMin[k], trackColorMax[k]);
            }
            // is (x, y) in cameraRect:
            colorXY = colorXY && ofInRange(x, cameraRect[0], cameraRect[1]);
            colorXY = colorXY && ofInRange(y, cameraRect[2], cameraRect[3]);

            thresholdedImage.getPixels()[y*width + x] = colorXY ? 255 : 0;
        }
    }

	thresholdedImage.flagImageChanged();

	// find one blob
	contours.findContours(thresholdedImage, trackThresholdMin, trackThresholdMax, 1, false);

	if (contours.nBlobs > 0)
	{
		objLocation = contours.blobs[0].centroid;

        // add point to array if epsilon-distancy is reached
        if (getPointsNumStored() == 0 || objLocation.distance(getLastPoint()) >= epsilonDistance)
        {
            currentTrackPoints->push_back(objLocation);
            currentTrackTimes->push_back(ofGetElapsedTimeMillis());
            objVelocity = calculateVelocity();

            //ofLog(ofLogLevel::OF_LOG_NOTICE, "Velocity" + std::to_string(objVelocity));

            updateCurrentTrackValues();
        }
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
			ofCircle(positionCamera.x + contours.blobs[0].centroid.x, 
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
	// TODO: need to look what we can do for destructor
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

		velocity += velocity_x * velocity_x + 
            velocity_y * velocity_y + 
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

        trackColorMin[0] = std::max(0, red - acc);
        trackColorMax[0] = std::min(255, red + acc);
		trackColorMin[1] = std::max(0, green - acc);
		trackColorMax[1] = std::min(255, green + acc);
		trackColorMin[2] = std::max(0, blue - acc);
		trackColorMax[2] = std::min(255, blue + acc);
	}
}

void CameraTracker::setPositionCamera(const ofPoint& position)
{
	positionCamera = position;
}

const ofVec3f CameraTracker::getTrackColorMin() const
{
	return trackColorMin;
}

const ofVec3f CameraTracker::getTrackColorMax() const
{
	return trackColorMax;
}

ofVec3f CameraTracker::getLastPoint() const
{
    return currentTrackPoints->back();
}

std::vector<ofVec3f> CameraTracker::getAllPoints() const
{
    return *currentTrackPoints;
}

void CameraTracker::setCameraRect(int xmin, int xmax, int ymin, int ymax)
{
    cameraRect[0] = xmin;
    cameraRect[1] = xmax;
    cameraRect[2] = ymin;
    cameraRect[3] = ymax;
}

void CameraTracker::setEpsilonUpdate(float epsilonUpdate)
{
    this->epsilonDistance = epsilonUpdate;
}