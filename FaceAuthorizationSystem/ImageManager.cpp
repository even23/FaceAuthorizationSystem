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

bool ImageManager::processAndSaveImage(Mat& image, User* user)
{
	string path;
	if (user != nullptr) {
		path = directoryPath + to_string(user->getId());
	}
	else {
		path = commonDirectoryPath;
	}
	//int userId = user->getId();
	//string path = directoryPath + to_string(userId);

	//string folderCreateCommand = "mkdir " + path;
	//system(folderCreateCommand.c_str());

	Mat result = processImage(image);

	string filename = photoDAO->addPhoto(user);
	if (user != nullptr) {
		user->addPhoto();
	}

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
