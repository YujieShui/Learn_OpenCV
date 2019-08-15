#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat dresult, eresult;
	Mat src = imread("../images/coins.jpg");
	imshow("input", src);
	// 结构元素3x3大小矩阵
	Mat se = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	// 腐蚀
	dilate(src, dresult, se, Point(-1, -1), 1, 0);
	// 膨胀
	erode(src, eresult, se, Point(-1, -1), 1, 0);
	
	imshow("dilate", dresult);
	imshow("erode", eresult);
	waitKey(0);
	return 0;
}