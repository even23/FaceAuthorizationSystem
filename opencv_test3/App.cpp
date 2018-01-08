#include "App.h"



App::App()
{
	userDao = new UserDAO();
	photoDao = new PhotoDAO();
	imageManager = new ImageManager(photoDao);
	faceDetectionManager = new FaceDetectionManager();
	videoCaptureManager = new VideoCaptureManager(faceDetectionManager, imageManager);
	faceRecognitionManager = new FaceRecognitionManager(userDao, photoDao, imageManager);
	activeUser = &*(userDao->getUsers()->begin());
	takenPhoto = Mat();
	trainRecognizer();
}


App::~App()
{
	delete faceRecognitionManager;
	delete faceDetectionManager;
	delete imageManager;
	delete photoDao;
	delete userDao;
}

bool App::savePhoto(Mat frame, Mat& result)
{
	vector<Rect>* faces = faceDetectionManager->detectFaces(frame);

	if (faceDetectionManager->getFaces()->size() == 0)
	{
		cout << "No faces found. The detector did not find any faces!";
		return false;
	}
	else
	{
		frame = frame.clone();
		Mat faceRegion;
		for (vector<Rect>::iterator face = faces->begin(); face != faces->end(); ++face)
		{
			result = frame(*face);
			faceRegion = result.clone();
			if (!imageManager->processAndSaveImage(faceRegion, activeUser)) {
				cout << "Failed. Could not process and save the image!";
				return false;
			}
			//result = imageManager->resizeImage(result, Size(184, 224));
			//result = faceRegion;
			//faceRecognitionManager->prepareTrainingExample();
		}
	}
	return true;
}

void App::trainRecognizer()
{
	faceRecognitionManager->trainRecognizer();
}

int App::predict(Mat frame)
{
	//Mat faceRegion;
	//vector<Rect>* faces = faceDetectionManager->detectFaces(frame);
	//if (faceDetectionManager->getFaces()->size() == 0)
	//{
	//	cout << "No faces found. The detector did not find any faces!";
	//	return -1;
	//}
	//else
	//{
	//	frame = frame.clone();
	//	for (vector<Rect>::iterator face = faces->begin(); face != faces->end(); ++face)
	//	{
	//		faceRegion = frame(*face);
	//		faceRegion = imageManager->processImage(faceRegion);
	//	}
	//}	
	//return faceRecognitionManager->predict(faceRegion);
	return faceRecognitionManager->predict(frame);
}

void App::test() {
	faceRecognitionManager->test();
}

bool App::login(string login, string typedPassword) {
	User* user = userDao->getUserByLogin(login);
	if (user == nullptr) {
		return false;
	}
	if (typedPassword.size() == 0 && takenPhoto.rows == 0) {
		return false;
	}
	else if (typedPassword.size() > 0 && typedPassword == user->getPassword()) {
		//takenPhoto.release();
		return true;
	}
	else if (takenPhoto.rows != 0) {
		int prediction = predict(takenPhoto);
		//int prediction = predict(faceRecognitionManager->testImages->at(0));
		if (prediction == user->getId()) {
			//takenPhoto.release();
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}

bool App::takePhoto(Mat frame, Mat& result)
{
	Mat faceRegion;
	vector<Rect>* faces = faceDetectionManager->detectFaces(frame);
	if (faceDetectionManager->getFaces()->size() == 0)
	{
		cout << "No faces found. The detector did not find any faces!";
		takenPhoto.release();
		return false;
	}
	else
	{
		frame = frame.clone();
		for (vector<Rect>::iterator face = faces->begin(); face != faces->end(); ++face)
		{
			result = frame(*face);
			faceRegion = result.clone();
			takenPhoto = imageManager->processImage(faceRegion);
			result = imageManager->resizeImage(faceRegion, Size(184, 224));
		}
		return true;
	}

}
