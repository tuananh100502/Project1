#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "utils.h"

int* RedDevil::getHistogramCount(Mat src)
{
	int histogram[RedDevil::HISTOGRAM] = { 0 };

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			histogram[src.at<uchar>(i, j)]++;
		}

	return histogram;
}

int RedDevil::getMaxPixel(Mat src)
{
	int histogram[256] = {};
	int maxPos = 0;

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			histogram[src.at<uchar>(i, j)]++;
			if (histogram[src.at<uchar>(i, j)] > histogram[maxPos]) {
				maxPos = src.at<uchar>(i, j);
			}
		}
	return maxPos;
}

Mat RedDevil::scaleHistogram(Mat src, double rate)
{
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {

			src.at<uchar>(i, j) = src.at<uchar>(i, j) * rate > 255 ? 255 : (src.at<uchar>(i, j) * rate < 0 ? 0 : src.at<uchar>(i, j) * rate);

		}
	return src;
}








