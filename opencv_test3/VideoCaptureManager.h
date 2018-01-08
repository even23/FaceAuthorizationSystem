#pragma once
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include "FaceDetectionManager.h"
#include "ImageManager.h"

#include <iostream>
#include <stdio.h>

using namespace System;
using namespace cv;
using namespace face;

class VideoCaptureManager
{
public:
	VideoCaptureManager(FaceDetectionManager* _aceDetectionManager, ImageManager* _imageManager);

	void display(Mat frame);
	void startCamera();
	Mat getCurrentFrame() { return currentFrame; }
private:
	VideoCapture videoCapture;
	FaceDetectionManager* faceDetectionManager;
	ImageManager* imageManager;

	Mat currentFrame;

	bool isStarted;

	bool withGrayScale;
	bool withHistogramEqualization;
	bool withTanTriggs;
	bool withFaceDetection;
};

