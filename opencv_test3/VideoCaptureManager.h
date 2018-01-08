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

ref class VideoCaptureManager
{
public:
	
	VideoCaptureManager(FaceDetectionManager* _aceDetectionManager, ImageManager* _imageManager);

	void display(Mat frame);
	void startCamera();
	Mat* getCurrentFrame() { return currentFrame; }

	bool getWithGrayScale() { return withGrayScale; }
	bool getWithHistogramEqualization () { return withHistogramEqualization; }
	bool getWithTanTriggs () { return withTanTriggs; }
	bool getWithFaceDetection () { return withFaceDetection; }

	void setWithGrayScale(bool a) { withGrayScale = a; }
	void setWithHistogramEqualization(bool a) { withHistogramEqualization = a; }
	void setWithTanTriggs(bool a) { withTanTriggs = a; }
	void setWithFaceDetection(bool a) { withFaceDetection = a; }

	void setIsStarted(bool a) { isStarted = a; }

private:
	VideoCapture* videoCapture;
	FaceDetectionManager* faceDetectionManager;
	ImageManager* imageManager;

	Mat* currentFrame;
	vector<Mat>* frameBuffer;
	int pos, newpos;
	int idx;

	bool isStarted;

	bool withGrayScale;
	bool withHistogramEqualization;
	bool withTanTriggs;
	bool withFaceDetection;
};

