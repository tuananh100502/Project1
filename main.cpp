#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Histogram.h"
#include "medianFilter.h"
#include "USM.h"
#include "GaussianFilter.h"
#include "Torn_detection.h"

using namespace cv;
using namespace std;
using namespace RedDevil2;

int main(int argc, char** argv)
{
    // Load the two input images
    Mat real_money = imread("C:/Users/PC/Downloads/real_currency3.jpg", IMREAD_COLOR);
    Mat fake_money = imread("C:/Users/PC/Downloads/fake_currency5.jpg", IMREAD_COLOR);
    Mat torn_money = imread("C:/Users/PC/Downloads/torn_dirty_banknote.jpg", IMREAD_COLOR);

    //Resize images
    Size size(480, 320);
    resize(real_money, real_money, size);
    resize(fake_money, fake_money, size);
    resize(torn_money, torn_money, size);
    
    //Gaussian Filter
    GaussianFilter(fake_money);
    
    //Brightness Adjustment
    if (Brightness_Adjustment(real_money, fake_money)) {
        fake_money = scaleHistogram(fake_money, (double)getMaxPixel(real_money) / getMaxPixel(fake_money));
    }

  //Find differences
    Mat diff = real_money - fake_money;
    diff = RedDevil::medianFilter(diff);
    threshold(diff, diff, 70, 255, THRESH_BINARY);

    imshow("real_money", real_money);
    imshow("fake_momey", fake_money);
    imshow("result", diff);

   //Torn_dirty money
    if (Torn_detection(torn_money)) {

        Mat torn_money_clone = torn_money.clone();
        threshold(torn_money_clone, torn_money_clone, 250, 255, THRESH_BINARY_INV);

        threshold(torn_money, torn_money, 250, 0, THRESH_TOZERO_INV);
        Mat missingPieces = real_money - torn_money_clone;

        Mat restore = torn_money + missingPieces;
        restore = RedDevil::medianFilter(restore);
        restore = RedDevil::USM(restore, 1, 0.5, 5);
        imshow("", restore);
    }

    waitKey(0);
    return 0;
}
