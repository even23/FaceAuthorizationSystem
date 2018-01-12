#pragma once
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "PhotoDAO.h"
#include "User.h"
#include "TanTriggs.h"

using namespace std;
using namespace cv;

class ImageManager
{
public:
	ImageManager(PhotoDAO* _photoDAO, string _directoryPath = PhotoDAO::PHOTO_DIR, cv::Size _goalSize = cv::Size(92, 112), bool _keepAspectRatio = true);
	~ImageManager();

	Mat processImage(Mat& image);

	bool processAndSaveImage(Mat& image, User* user, string& filename, string& directory);

	void convertToGrayScale(Mat& image);

	void equalizeHistogram(Mat& image);

	void tanTriggsPreprocessing(Mat& image);

	Mat resizeImage(Mat& image, cv::Size size = cv::Size(92, 112));

	bool compareHistograms(Mat a, Mat b);

	void processForHistogramComparison(Mat& mat);

private:
	PhotoDAO* photoDAO;

	string directoryPath;
	string commonDirectoryPath;
	cv::Size goalSize;
	bool keepAspectRatio;
};

