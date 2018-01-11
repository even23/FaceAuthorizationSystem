#include "faceDetectionManager.h"

String FaceDetectionManager::FACE_CASCADE_NAME = "cascades/haarcascade_frontalface_alt.xml";

FaceDetectionManager::FaceDetectionManager()
{
	faceCascade = new CascadeClassifier();
	// Inicjalizacja klasyfikatora twarzy z pliku FACE_CASCADE_NAME.
	faceCascade->load(FACE_CASCADE_NAME);
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
