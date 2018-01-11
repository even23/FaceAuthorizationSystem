#pragma once
#include "opencv2/objdetect.hpp"

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

	FaceDetectionManager();
	~FaceDetectionManager();

	// Funkcja zwracaj�ca znalezione na obrazie twarze w postaci wektora prostok�t�w.
	vector<Rect> detectFaces(Mat frame);
	// Wykorzystuje funkcj� detectFaces. Ponadto zapisuje znalezione twarze w zmiennej faces.
	Ptr<vector<Rect>>& detectAndSaveFaces(Mat frame);
	Ptr<vector<Rect>>& getFaces() {
		return faces;
	}

private:
	// Klasyfikator twarzy
	Ptr<CascadeClassifier> faceCascade;

	// Wykryte twarze
	Ptr<vector<Rect>> faces;
};

