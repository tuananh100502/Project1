#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Torn_detection.h"

using namespace cv;
using namespace std;

bool RedDevil2::Torn_detection(Mat sample)
{
	Mat shape;
	threshold(sample, shape, 250, 255, THRESH_BINARY_INV);

	int count = 0;
	for (int i = 0; i < shape.rows; i++)
		for (int j = 0; j < shape.cols; j++) {
			if (shape.at<uchar>(i, j) <= 10) count++;
		}

	return count > (double) 0.2 * shape.cols * shape.rows;
}
