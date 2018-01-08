#include "VideoCaptureManager.h"

string windowName = "Kamera";

VideoCaptureManager::VideoCaptureManager(FaceDetectionManager* _faceDetectionManager, ImageManager* _imageManager)
{
	videoCapture = new VideoCapture();
	currentFrame = new Mat();
	faceDetectionManager = _faceDetectionManager;
	isStarted = false;

	withGrayScale = false;
	withHistogramEqualization = false;
	withTanTriggs = false;
	withFaceDetection = true;
}

void VideoCaptureManager::display(Mat frame)
{
	cv::String face_cascade_name = "cascades/haarcascade_frontalface_alt.xml";

	vector<Rect>* faces;
	Mat frameResult = frame.clone();
	if  (withGrayScale == true) {
		frameResult = imageManager->convertToGrayScale(frameResult);
	}
	if (withHistogramEqualization == true) {
		frameResult = imageManager->equalizeHistogram(frameResult);
	}
	if (withTanTriggs == true) {
		frameResult = imageManager->tanTriggsPreprocessing(frameResult);
	}
	if (withFaceDetection) {
		faces = faceDetectionManager->detectFaces(frameResult);

		for (size_t i = 0; i < faces->size(); i++)
		{
			Point a(faces->at(i).x, faces->at(i).y);
			Point b(faces->at(i).x + faces->at(i).width, faces->at(i).y + faces->at(i).height);
			rectangle(frameResult, a, b, Scalar(11, 215, 18), 2, 8, 0);
		}
	}
	imshow(windowName, frameResult);
}

void VideoCaptureManager::startCamera()
{
	isStarted = true;
	int c;
	if (videoCapture->open(0))
	{
		do
		{
			videoCapture->read(*currentFrame);
			if (!currentFrame->empty())
			{
				display(*currentFrame);
			}
			waitKey(10);
		} while (isStarted == true);
		destroyWindow(windowName);
	}
}
