#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "USM.h"

using namespace cv;
using namespace std;

Mat RedDevil::USM(Mat input, float radius, float amount, float thresh)
{
	Mat retbuf = input.clone();

	Mat blurred;
	cv::GaussianBlur(input, blurred, cv::Size(0, 0), radius);

	Mat unsharpMask;
	cv::subtract(input, blurred, unsharpMask);

	cv::blur(unsharpMask, unsharpMask, { 3,3 });

	for (int row = 0; row < input.rows; row++)
	{
		for (int col = 0; col < input.cols; col++)
		{

			if (norm(unsharpMask.at<uchar>(row, col)) >= thresh) {
				retbuf.at<uchar>(row, col) = input.at<uchar>(row, col) + amount * unsharpMask.at<uchar>(row, col);
			}
		}
	}

	return retbuf;

}