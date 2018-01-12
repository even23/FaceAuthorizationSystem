#include "faceDetectionManager.h"

String FaceDetectionManager::FACE_CASCADE_NAME = "cascades/haarcascade_frontalface_alt.xml";
String FaceDetectionManager::EYES_CASCADE_NAME = "cascades/haarcascade_eye_tree_eyeglasses.xml";

FaceDetectionManager::FaceDetectionManager(ImageManager* _imageManager)
{
	imageManager = _imageManager;
	faceCascade = new CascadeClassifier();
	// Inicjalizacja klasyfikatora twarzy z pliku FACE_CASCADE_NAME.
	faceCascade->load(FACE_CASCADE_NAME);
	eyesCascade = new CascadeClassifier();
	eyesCascade->load(EYES_CASCADE_NAME);
	faces = new vector<Rect>();
}

FaceDetectionManager::~FaceDetectionManager()
{
}

vector<Rect> FaceDetectionManager::detectFaces(Mat frame)
{
	vector<Rect> faces;
	faceCascade->detectMultiScale(frame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	return faces;
}

Ptr<vector<Rect>>& FaceDetectionManager::detectAndSaveFaces(Mat frame)
{
	faces = new vector<Rect>(detectFaces(frame));
	return faces;
}

int FaceDetectionManager::verifyEyes(Mat& frame)
{
	vector<Rect> faces = detectFaces(frame);
	vector<Rect> eyes;
	Rect face = faces.back();
	frame = frame(face);
	Mat faceFrame = frame.clone(); 
	imageManager->convertToGrayScale(faceFrame);
	imageManager->equalizeHistogram(faceFrame);
	eyesCascade->detectMultiScale(faceFrame, eyes, 1.1, 4, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	if (eyes.size() == 1) {
		// warunek na znalezienia prawego oka
		if ((face.width/2) > (eyes[0].x + eyes[0].width / 2)) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (eyes.size() == 0) {
		return 0;
	}
	else {
		return 2;
	}
}
