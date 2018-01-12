#pragma once

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
using namespace System::Runtime::InteropServices;
using namespace System::Drawing;

class Utils {
public:
	static System::Drawing::Bitmap^ mat2Bitmap(cv::Mat & colorImage);
	static char * string2Char(System::String^ str);
	static System::String^ char2String(std::string str);

	//static Mat norm_0_255(InputArray _src);
};