#include "ImageManager.h"

ImageManager::ImageManager(PhotoDAO * _photoDAO, string _directoryPath, Size _goalSize, bool _keepAspectRatio)
{
	photoDAO = _photoDAO;
	directoryPath = _directoryPath;
	commonDirectoryPath = _directoryPath + "temp";
	goalSize = _goalSize;
	keepAspectRatio = _keepAspectRatio;
}

ImageManager::~ImageManager()
{
}

Mat ImageManager::processImage(Mat& image)
{
	Mat result = resizeImage(image);
	
	convertToGrayScale(result);
	equalizeHistogram(result);
	tanTriggsPreprocessing(result);
	return result;
}

bool ImageManager::processAndSaveImage(Mat& image, User* user, string& filename, string& path)
{
	//string path;
	if (user != nullptr) {
		path = directoryPath + to_string(user->getId());
	}
	else {
		path = commonDirectoryPath;
	}
	//int userId = user->getId();
	//string path = directoryPath + to_string(userId);

	string folderCreateCommand = "mkdir " + path;
	system(folderCreateCommand.c_str());

	Mat result = processImage(image);
	
	filename = photoDAO->addPhoto(user);
	return imwrite(path + "\\" + filename, result);
}

void ImageManager::convertToGrayScale(Mat & image)
{
	if (image.channels() != 1) {
		cvtColor(image, image, CV_BGR2GRAY);
	}
}

void ImageManager::equalizeHistogram(Mat & image)
{
	equalizeHist(image, image);
}

void ImageManager::tanTriggsPreprocessing(Mat & image)
{
	image = tan_triggs_preprocessing(image);
	normalize(image, image, 0.0, 1.0, CV_MINMAX, CV_64F);
	image.convertTo(image, CV_8U, 255, 0);
}

Mat ImageManager::resizeImage(Mat & image, Size size)
{
	Mat resized;
	Size originalSize = image.size();
	Size goalSize = size;
	if (keepAspectRatio)
	{
		float ratio = static_cast<float>(goalSize.height) / originalSize.height;
		Size newSize((int)(originalSize.width * ratio), (int)(originalSize.height * ratio));

		if (newSize.height != goalSize.height) newSize.height = goalSize.height;

		resize(image, resized, newSize);

		if (resized.size().width != goalSize.width)
		{
			int delta = goalSize.width - resized.size().width;

			if (delta < 0)
			{
				Rect clipRect(std::abs(delta) / 2, 0, goalSize.width, resized.size().height);
				resized = resized(clipRect);
			}
		}
	}
	else
		resize(image, resized, goalSize);

	return resized;
}

bool ImageManager::compareHistograms(Mat a, Mat b)
{
	Mat x = resizeImage(a.clone());
	Mat y = resizeImage(b.clone());

	//cvtColor(x, x, COLOR_BGR2HSV);
	//cvtColor(y, y, COLOR_BGR2HSV);

	MatND xHist;
	MatND yHist;
	int imgCount = 1;
	int dims = 3;
	const int sizes[] = { 60,60,60 };
	const int channels[] = { 0,1,2 };
	float range[] = { 0,256 };
	const float *ranges[] = { range, range, range };

	//int dims = 2;
	//int h_bins = 50; int s_bins = 60;
	//int sizes[] = { h_bins, s_bins };
	//float h_ranges[] = { 0, 180 };
	//float s_ranges[] = { 0, 256 };
	//const float* ranges[] = { h_ranges, s_ranges };
	//int channels[] = { 0, 1 };


	calcHist(&x, imgCount, channels, Mat(), xHist, dims, sizes, ranges);
	normalize(xHist, xHist, 0, 1, NORM_MINMAX, -1, Mat());
	calcHist(&y, imgCount, channels, Mat(), yHist, dims, sizes, ranges);
	normalize(yHist, yHist, 0, 1, NORM_MINMAX, -1, Mat());

	double result = compareHist(xHist, yHist, CV_COMP_CHISQR);

	if (result < 300) {
		return true;
	}
	else {
		return false;
	}


}

void ImageManager::processForHistogramComparison(Mat & mat)
{
	mat = resizeImage(mat);
	convertToGrayScale(mat);
	//equalizeHistogram(mat);
}
