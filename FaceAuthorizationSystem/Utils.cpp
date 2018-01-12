#include "Utils.h"

Bitmap^ Utils::mat2Bitmap(Mat & colorImage) {
	System::IntPtr ptr(colorImage.ptr());
	Bitmap^ b;
	switch (colorImage.type())
	{
	case CV_8UC3: // non-grayscale images are correctly displayed here
		b = gcnew Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			Imaging::PixelFormat::Format24bppRgb, ptr);
		break;
	case CV_8UC1: // grayscale images are incorrectly displayed here 
		b = gcnew Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			Imaging::PixelFormat::Format8bppIndexed, ptr);
		break;
	default:
		b = gcnew Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			Imaging::PixelFormat::Format24bppRgb, ptr);
		break;
	}
	return b;
}

char * Utils::string2Char(System::String^ str) {	// Marshal method
	char* strs = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	return strs;
}

System::String^ Utils::char2String(std::string str) {
	System::String^ clistr = gcnew System::String(str.c_str());
	return clistr;
}

//Mat Utils::norm_0_255(InputArray _src) {
//	Mat src = _src.getMat();
//	// Create and return normalized image:
//	Mat dst;
//	switch (src.channels()) {
//	case 1:
//		cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
//		break;
//	case 3:
//		cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
//		break;
//	default:
//		src.copyTo(dst);
//		break;
//	}
//	return dst;
//}