#pragma once
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

#include <iostream>
#include <stdio.h>

using namespace System;
using namespace cv;
using namespace face;

Mat processImage(Mat frame);
void detectAndDisplay(Mat frame, int a);