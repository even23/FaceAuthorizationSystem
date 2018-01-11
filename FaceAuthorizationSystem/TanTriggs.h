#pragma once
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

/*
* Copyright (c) 2012. Philipp Wagner <bytefish[at]gmx[dot]de>.
* Released to public domain under terms of the BSD Simplified license.
*/
Mat tan_triggs_preprocessing(InputArray src,
	float alpha = 0.1, float tau = 10.0, float gamma = 0.2, int sigma0 = 1,
	int sigma1 = 2);