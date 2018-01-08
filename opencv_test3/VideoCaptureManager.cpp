#include "VideoCaptureManager.h"



VideoCaptureManager::VideoCaptureManager(FaceDetectionManager* _faceDetectionManager, ImageManager* _imageManager)
{
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

	std::vector<Rect>* faces;
	Mat frame_result = frame.clone();
	if  (withGrayScale == true) {
		imageManager->convertToGrayScale(frame_result);
	}
	if (withHistogramEqualization == true) {
		imageManager->equalizeHistogram(frame_result);
	}
	if (withTanTriggs == true) {
		imageManager->tanTriggsPreprocessing(frame_result);
	}
	//-- Detect faces
	faces = faceDetectionManager->detectFaces(frame_result);

	for (size_t i = 0; i < faces->size(); i++)
	{
		Point a(faces->at(i).x, faces->at(i).y);
		Point b(faces->at(i).x + faces->at(i).width, faces->at(i).y + faces->at(i).height);
		rectangle(frame_result, a, b, Scalar(11, 215, 18), 2, 8, 0);
	}
	//-- Show what you got
	imshow("Camera", frame_result);
}

void VideoCaptureManager::startCamera()
{
	if (videoCapture.open(0))
	{
		do
		{
			videoCapture.read(currentFrame);
			if (!currentFrame.empty())
			{
				display(currentFrame);
			}
			else
			{
				printf(" --(!) No captured frame -- Break!"); break;
			}
		} while (isStarted == true);
	}
}
