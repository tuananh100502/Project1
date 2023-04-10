#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Histogram.h"


using namespace cv;
using namespace std;

bool RedDevil2::Brightness_Adjustment(Mat templ, Mat sample)
{

	int* template_histogram = getHistogramCount(templ);
	int* sample_histogram = getHistogramCount(sample);

	int count = 0;

	for (int i = 5; i < HISTOGRAM - 5; i++) {
		if (abs(template_histogram[i] - sample_histogram[i]) >= 0.02 * template_histogram[i]) count++;
	}

	return count >= 200;
}