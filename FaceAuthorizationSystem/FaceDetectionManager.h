#pragma once
#include "opencv2/objdetect.hpp"

#include "ImageManager.h"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


// Klasa zarz�dcy detekcji twarzy.
// Odpowiedzialna za wykrywanie twarzy na obrazach.
class FaceDetectionManager
{
public:
	// �cie�ka do kaskady klasyfikator�w cech Haaro-podobnych do wykrywania twarzy.
	static cv::String FACE_CASCADE_NAME;
	static cv::String EYES_CASCADE_NAME;

	FaceDetectionManager(ImageManager* imageManager);
	~FaceDetectionManager();

	// Funkcja zwracaj�ca znalezione na obrazie twarze w postaci wektora prostok�t�w.
	vector<Rect> detectFaces(Mat frame);
	// Wykorzystuje funkcj� detectFaces. Ponadto zapisuje znalezione twarze w zmiennej faces.
	Ptr<vector<Rect>>& detectAndSaveFaces(Mat frame);
	Ptr<vector<Rect>>& getFaces() {
		return faces;
	}

	int verifyEyes(Mat& frame);

private:
	ImageManager* imageManager;

	// Klasyfikator twarzy
	Ptr<CascadeClassifier> faceCascade;

	// Klasyfikator oczu
	Ptr<CascadeClassifier> eyesCascade;

	// Wykryte twarze
	Ptr<vector<Rect>> faces;
};

