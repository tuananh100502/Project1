#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

namespace RedDevil {
	static const int HISTOGRAM = 256;
	int* getHistogramCount(Mat src);

	int getMaxPixel(Mat src);
	Mat scaleHistogram(Mat src, double rate);
	
}