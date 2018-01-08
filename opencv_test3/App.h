#pragma once

#include "FaceRecognitionManager.h"
#include "FaceDetectionManager.h"
#include "ImageManager.h"
#include "LoginSession.h"

class App
{
public:
	App();
	~App();

	//bool writeCsv();
	bool savePhoto(Mat frame, Mat& result);
	void trainRecognizer();
	int predict(Mat frame);
	void test();

	bool login(string login, string typedPassword);

	bool takePhoto(Mat frame, Mat & result);

private:
	//VideoCapture capture;

	UserDAO* userDao;
	PhotoDAO* photoDao;
	FaceRecognitionManager* faceRecognitionManager;
	FaceDetectionManager* faceDetectionManager;
	ImageManager* imageManager;
	User* activeUser;
	LoginSession* loginSession;
	cv::Mat takenPhoto;
};

