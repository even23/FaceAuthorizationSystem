#include "test.h"

Mat processImage(Mat frame)
{
	Mat frame_result;

	cvtColor(frame, frame_result, CV_BGR2GRAY);
	equalizeHist(frame_result, frame_result);

	return frame_result;
}

void detectAndDisplay(Mat frame, int a)
{
	cv::String face_cascade_name = "D:/OpenCV/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
	cv::String eyes_cascade_name = "D:/OpenCV/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;

	eyes_cascade.load(eyes_cascade_name);
	face_cascade.load(face_cascade_name);

	std::vector<Rect> faces;
	Mat frame_result = frame.clone();
	if (a == 1) {
		frame_result = processImage(frame);
	}
	//-- Detect faces
	face_cascade.detectMultiScale(frame_result, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		//Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		//ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

		Point a(faces[i].x, faces[i].y);
		Point b(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		rectangle(frame_result, a, b, Scalar(11, 215, 18), 2, 8, 0);

		Mat faceROI = frame_result(faces[i]);
		std::vector<Rect> eyes;

		//-- In each face, detect eyes
		//eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

		//for (size_t j = 0; j < eyes.size(); j++)
		//{
		//	Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
		//	int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
		//	circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
		//}
	}
	//-- Show what you got
	imshow("TEST", frame_result);
}