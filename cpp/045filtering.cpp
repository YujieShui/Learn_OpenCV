/*
 * @Description: 图像二值化与去噪
 * @Author: shuiyj
 * @Date: 2019-07-29
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/coins.jpg");

    if (src.empty())
    {
        printf("could not load image");
        return -1;
    }

    cv::imshow("src", src);

    // 去噪与二值化
    cv::Mat dst, gray, binary;
    pyrMeanShiftFiltering(src, dst, 10, 100);
	// GaussianBlur(src, dst, Size(3, 3), 0, 0);
	cvtColor(dst, gray, cv::COLOR_BGR2GRAY);
	threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	imshow("binary", binary);

	cv::waitKey(0);
	return 0;
}