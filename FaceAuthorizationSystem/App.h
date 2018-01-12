#pragma once

#include "FaceRecognitionManager.h"
#include "FaceDetectionManager.h"
#include "ImageManager.h"
#include "LoginSession.h"
#include "VideoCaptureManager.h"



ref class App
{
public:
	App();
	~App();

	//bool writeCsv();
	bool savePhoto(string& filename, string& directory);
	void trainRecognizer();
	int predict(Mat frame);
	void test();

	bool login(string login, string typedPassword);
	void logout();

	bool takePhoto();

	VideoCaptureManager^ getVideoCaptureManager() { return videoCaptureManager; }
	Mat* getPhotoBoxImage() { return photoBoxImage; }
	Mat* getTakenPhoto() { return takenPhoto; }
	User* getActiveUser() { return activeUser; }

	UserDAO* getUserDAO() { return userDao; }

	void removePhoto();
	void removeUser();

	bool getVerified() { return verified; }
	void setVerified(bool a) { verified = a; }

	bool verifyHuman();
private:
	//VideoCapture capture;

	UserDAO* userDao;
	PhotoDAO* photoDao;
	FaceRecognitionManager* faceRecognitionManager;
	FaceDetectionManager* faceDetectionManager;
	ImageManager* imageManager;
	User* activeUser;
	LoginSession* loginSession;
	VideoCaptureManager^ videoCaptureManager;
	Mat* takenPhoto;
	Mat* photoBoxImage;
	bool verified;
};

