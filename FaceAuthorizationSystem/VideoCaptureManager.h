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

// Klasa zarz�dcy kamery.
// Odpowiedzialna za przechwytywanie obrazu z kamery i wy�wietlaniu go na ekranie.
// Ob�suguje przetwarzanie obrazu wyj�ciowego.
ref class VideoCaptureManager
{
public:	
	VideoCaptureManager(FaceDetectionManager* _faceDetectionManager, ImageManager* _imageManager);
	~VideoCaptureManager();

	// Funkcja odpowidzialna za w��czenie kamery. Jest wywo�ywana w nowym w�tku.
	void startCamera();

	// Funkcja odpowiedzialna za wy�wietlanie przetworzonego obrazu na ekranie.
	void display(Mat frame);

	// Funkcja zwracaj�ca ostatnio przechwycon� klatk� z kamery.
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

	// Zmienna okre�laj�ca, czy kamera jest w�aczona, czyli czy jest uruchominy w�tek kamery.
	bool isStarted;

	// Zmienne okre�laj�ce jakie przetwarzanie ma by� wykonywane na wy�wietlanym obrazie.
	// Konwersja do skali szaro�ci
	bool withGrayScale;
	// Wyr�wnanie histogramu
	bool withHistogramEqualization;
	// Przetwarzanie Tana i Triggsa
	bool withTanTriggs;
	// Detakcja twarzy
	bool withFaceDetection;
};

