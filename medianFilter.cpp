#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "medianFilter.h"

using namespace cv;
using namespace std;


void RedDevil::insertionSort(int window[])
{
	int temp, i, j;
	for (i = 0; i < 9; i++) {
		temp = window[i];
		for (j = i - 1; j >= 0 && temp < window[j]; j--)
		{
			window[j + 1] = window[j];
		}
		window[j + 1] = temp;
	}
}

Mat RedDevil::medianFilter(Mat src)
{
	int window[9];
	Mat dst = src.clone();

	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			dst.at<uchar>(y, x) = 0.0;

	for (int y = 1; y < src.rows - 1; y++)
		for (int x = 1; x < src.cols - 1; x++)
		{
			window[0] = src.at<uchar>(y - 1, x - 1);
			window[1] = src.at<uchar>(y, x - 1);
			window[2] = src.at<uchar>(y + 1, x - 1);
			window[3] = src.at<uchar>(y - 1, x);
			window[4] = src.at<uchar>(y, x);
			window[5] = src.at<uchar>(y + 1, x);
			window[6] = src.at<uchar>(y - 1, x + 1);
			window[7] = src.at<uchar>(y, x + 1);
			window[8] = src.at<uchar>(y + 1, x + 1);
			insertionSort(window);
			dst.at<uchar>(y, x) = window[4];
		}
	return dst;
}

