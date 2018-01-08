#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

#pragma once
class FaceDetectionManager
{
public:
	static cv::String FACE_CASCADE_NAME;
	static cv::String EYES_CASCADE_NAME;

	FaceDetectionManager();
	~FaceDetectionManager();

	vector<Rect>* detectFaces(Mat frame);
	vector<Rect>* getFaces() {
		return faces;
	}

private:
	Ptr<CascadeClassifier> faceCascade;
	Ptr<CascadeClassifier> eyesCascade;

	//Mat frame;
	vector<Rect>* faces;
};

