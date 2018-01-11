#include "VideoCaptureManager.h"

// Nazwa okna, w kt�rym zostanie pokazywany obraz z kamery.
string WINDOW_NAME = "Kamera";

VideoCaptureManager::VideoCaptureManager(FaceDetectionManager* _faceDetectionManager, ImageManager* _imageManager)
{
	videoCapture = new VideoCapture();
	currentFrame = new Mat();
	faceDetectionManager = _faceDetectionManager;
	imageManager = _imageManager;
	isStarted = false;

	withGrayScale = false;
	withHistogramEqualization = false;
	withTanTriggs = false;
	withFaceDetection = true;
}

VideoCaptureManager::~VideoCaptureManager()
{
	isStarted = false;
	delete videoCapture;
	delete currentFrame;
}

void VideoCaptureManager::display(Mat frame)
{
	// Wykonuj� operacje tylko na kopii klatki. 
	// Orygina� b�dzie wykorzystywany w trkacie detekcji oraz rozpoznawania twarzy.
	Mat frameResult = frame.clone();

	// Przetwarzanie klatki zale�nie od wybranych opcji.
	if  (withGrayScale == true) {
		imageManager->convertToGrayScale(frameResult);
	}
	if (withHistogramEqualization == true) {
		imageManager->equalizeHistogram(frameResult);
	}
	if (withTanTriggs == true) {
		imageManager->tanTriggsPreprocessing(frameResult);
	}
	if (withFaceDetection) {
		vector<Rect> faces;
		faces = faceDetectionManager->detectFaces(frameResult);

		for (size_t i = 0; i < faces.size(); i++)
		{
			Point a(faces.at(i).x, faces.at(i).y);
			Point b(faces.at(i).x + faces.at(i).width, faces.at(i).y + faces.at(i).height);
			Point middle((a.x + b.x) / 2, (a.y + b.y) / 2);
			Point q(middle.x - 112, middle.y - 112);
			Point w(middle.x + 112, middle.y + 112);
			// Ramka g��wna z wykryt� twarz�.
			rectangle(frameResult, a, b, Scalar(11, 215, 18), 2, 8, 0);
			// Ramka pomocnicza okre�laj�ca sugerowany rozmiar ramki g��wnej.
			rectangle(frameResult, q, w, Scalar(200, 15, 18), 2, 8, 0);
		}
	}
	// Wy�wietlenie przetworzonego obrazu z kameryw oknie.
	imshow(WINDOW_NAME, frameResult);
}

void VideoCaptureManager::startCamera()
{
	isStarted = true;

	if (videoCapture->open(0))
	{
		// G��wna p�tla w�tku kamery.
		do
		{
			// Je�li uda�o si� przechwyci� klatk� to j� wy�wietl.
			videoCapture->read(*currentFrame);
			if (!currentFrame->empty())
			{
				display(*currentFrame);
			}
			waitKey(10);
		} while (isStarted == true);

		// Zamknij okno, po sko�czeniu wy�wietlania.
		destroyWindow(WINDOW_NAME);
	}
}
