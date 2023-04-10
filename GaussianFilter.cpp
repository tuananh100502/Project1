#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "GaussianFilter.h"

using namespace cv;
using namespace std;

void GaussianFilter(Mat image) {
	int rows = image.rows;
	int cols = image.cols;
	for (int i = 0; i < rows; i++)
	{
		Vec3b* ptr = image.ptr<Vec3b>(i);
		for (int j = 0; j < cols; j++)
		{
			Vec3b pixel = ptr[j];
		}
	}
	//imshow("Truoc Gaussian Filter", image);
	Mat image_Gauss = image.clone();
	GaussianBlur(image, image_Gauss, Size(9, 9), 0, 0);
	for (int i = 0; i < rows; i++)
	{
		Vec3b* ptr = image_Gauss.ptr<Vec3b>(i);
		for (int j = 0; j < cols; j++)
		{
			Vec3b pixel = ptr[j];
		}
	}
	//imshow("Sau Gaussian Filter", image_Gauss);
}
