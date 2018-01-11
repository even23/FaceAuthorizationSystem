#pragma once
//#include "opencv2/core.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"

#include "FaceDetectionManager.h"
#include "ImageManager.h"

//#include <iostream>
//#include <stdio.h>

using namespace System;
using namespace cv;

// Klasa zarz¹dcy kamery.
// Odpowiedzialna za przechwytywanie obrazu z kamery i wyœwietlaniu go na ekranie.
// Ob³suguje przetwarzanie obrazu wyjœciowego.
ref class VideoCaptureManager
{
public:	
	VideoCaptureManager(FaceDetectionManager* _faceDetectionManager, ImageManager* _imageManager);
	~VideoCaptureManager();

	// Funkcja odpowidzialna za w³¹czenie kamery. Jest wywo³ywana w nowym w¹tku.
	void startCamera();

	// Funkcja odpowiedzialna za wyœwietlanie przetworzonego obrazu na ekranie.
	void display(Mat frame);

	// Funkcja zwracaj¹ca ostatnio przechwycon¹ klatkê z kamery.
	Mat* getCurrentFrame() { return currentFrame; }

	bool getWithGrayScale() { return withGrayScale; }
	bool getWithHistogramEqualization () { return withHistogramEqualization; }
	bool getWithTanTriggs () { return withTanTriggs; }
	bool getWithFaceDetection () { return withFaceDetection; }
	bool getIsStarted() { return isStarted; }

	void setWithGrayScale(bool a) { withGrayScale = a; }
	void setWithHistogramEqualization(bool a) { withHistogramEqualization = a; }
	void setWithTanTriggs(bool a) { withTanTriggs = a; }
	void setWithFaceDetection(bool a) { withFaceDetection = a; }	
	void setIsStarted(bool a) { isStarted = a; }

private:
	VideoCapture* videoCapture;
	FaceDetectionManager* faceDetectionManager;
	ImageManager* imageManager;

	// Ostatnio przechwycona klatka
	Mat* currentFrame;

	// Zmienna okreœlaj¹ca, czy kamera jest w³aczona, czyli czy jest uruchominy w¹tek kamery.
	bool isStarted;

	// Zmienne okreœlaj¹ce jakie przetwarzanie ma byæ wykonywane na wyœwietlanym obrazie.
	// Konwersja do skali szaroœci
	bool withGrayScale;
	// Wyrównanie histogramu
	bool withHistogramEqualization;
	// Przetwarzanie Tana i Triggsa
	bool withTanTriggs;
	// Detakcja twarzy
	bool withFaceDetection;
};

