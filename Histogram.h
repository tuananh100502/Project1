#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "utils.h"

using namespace cv;
using namespace std;
using namespace RedDevil;

namespace RedDevil2 {
	bool Brightness_Adjustment(Mat templ, Mat sample);
}