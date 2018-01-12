#include "App.h"



App::App()
{
	userDao = new UserDAO();
	photoDao = new PhotoDAO();
	imageManager = new ImageManager(photoDao);
	faceDetectionManager = new FaceDetectionManager(imageManager);
	videoCaptureManager = gcnew VideoCaptureManager(faceDetectionManager, imageManager);
	faceRecognitionManager = new FaceRecognitionManager(userDao, photoDao, imageManager);
	//activeUser =  &(*userDao->getUsers()->begin());
	takenPhoto = new Mat();
	photoBoxImage = new Mat();
	trainRecognizer();
	verified = false;
}


App::~App()
{
	delete faceRecognitionManager;
	delete videoCaptureManager;
	delete faceDetectionManager;
	delete imageManager;
	delete photoDao;
	delete userDao;
}

bool App::savePhoto(string& filename, string& directory)
{
	//vector<Rect>* faces = faceDetectionManager->detectAndSaveFaces(frame);

	//if (faceDetectionManager->getFaces()->size() == 0)
	//{
	//	cout << "No faces found. The detector did not find any faces!";
	//	return false;
	//}
	//else
	//{
	//	frame = frame.clone();
	//	Mat faceRegion;
	//	for (vector<Rect>::iterator face = faces->begin(); face != faces->end(); ++face)
	//	{
	//		result = frame(*face);
	//		faceRegion = result.clone();
	//		if (!imageManager->processAndSaveImage(faceRegion, activeUser)) {
	//			cout << "Failed. Could not process and save the image!";
	//			return false;
	//		}
	//		//result = imageManager->resizeImage(result, Size(184, 224));
	//		//result = faceRegion;
	//		//faceRecognitionManager->prepareTrainingExample();
	//	}
	//}
	//return true;

	if (takenPhoto->rows != 0) {
		if (imageManager->processAndSaveImage(*takenPhoto, activeUser, filename, directory)) {
			if (activeUser != nullptr) {
				faceRecognitionManager->update();
			}
			return true;
		}
	}
	return false;
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
	if (typedPassword.size() == 0 && takenPhoto->rows == 0) {
		return false;
	}
	else if (typedPassword.size() > 0 && typedPassword == user->getPassword()) {
		//takenPhoto.release();
		activeUser = user;
		return true;
	}
	else if (takenPhoto->rows != 0) {
		Mat photo = imageManager->processImage(*takenPhoto);
		int prediction = predict(photo);
		//int prediction = predict(faceRecognitionManager->testImages->at(0));
		if (prediction == user->getId()) {
			//takenPhoto.release();
			activeUser = user;
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}

void App::logout()
{
	activeUser = nullptr;
}

bool App::takePhoto()
{
	Mat faceRegion;
	Mat frame = videoCaptureManager->getCurrentFrame()->clone();
	Ptr<vector<Rect>> faces = faceDetectionManager->detectAndSaveFaces(frame);
	takenPhoto->release();
	if (faces->size() == 0)
	{
		return false;
	}
	else
	{
			Rect face = faces->back();
			//if (photoBoxImage != nullptr) {
			//	delete photoBoxImage;
			//}
			//photoBoxImage = new Mat(frame(face));
			//faceRegion = photoBoxImage->clone();
			//faceRegion = imageManager->processImage(faceRegion);
			//if (takenPhoto != nullptr) {
			//	delete takenPhoto;
			//}
			//takenPhoto = new Mat(faceRegion);

			faceRegion = frame(face);
			takenPhoto = new Mat(faceRegion);


				//= new Mat(imageManager->tan_triggs_preprocessing(faceRegion));
			//normalize(*takenPhoto, *takenPhoto, 0.0, 1.0, CV_MINMAX, CV_64F);
			//image.convertTo(image, CV_8U, 255, 0);
			//result = imageManager->resizeImage(result, Size(184, 224));
		//}
		return true;
	}

}

void App::removePhoto()
{
	if (takenPhoto->rows != 0) {
		takenPhoto->release();
	}
}

void App::removeUser()
{
	User* user = activeUser;

	userDao->removeUser(user);
	if (user->getPhotos() > 0) {
		int id = user->getId();
		photoDao->removeUserPhotos(id);
		faceRecognitionManager->removeUserImages(id);
	}
	delete user;
}

int App::verifyHuman()
{
	Mat frame = videoCaptureManager->getCurrentFrame()->clone();
	int result = faceDetectionManager->verifyEyes(frame);
	if (result == 1) {
		if (imageManager->compareHistograms(frame, *takenPhoto)) {
			verified = true;
			return 1;
		}
		else {
			return 3;
		}
	}
	else {
		verified = false;
		return result;
	}

}
