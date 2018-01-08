#pragma once
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include "FaceDetectionManager.h"

#include <iostream>
#include <stdio.h>

using namespace System;
using namespace cv;
using namespace face;

class VideoCaptureManager
{
public:
	VideoCaptureManager(FaceDetectionManager* faceDetectionManager);

	void display(Mat frame);
	void startCamera();
	Mat getCurrentFrame() { return currentFrame; }
private:
	VideoCapture videoCapture;
	FaceDetectionManager* faceDetectionManager;

	Mat currentFrame;

	bool isStarted;

	bool withGrayscale;
	bool withHistogramEqualization;
	bool withTanTriggs;
	bool withFaceDetection;
};

