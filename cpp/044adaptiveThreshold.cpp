/*
 * @Description: 自适应阈值算法
 * @Author: shuiyj
 * @Date: 2019-07-27 16:55:35
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/lena.jpg");

    if (src.empty())
    {
        printf("could not load image");
        return -1;
    }

    cv::imshow("src", src);

    cv::Mat gray, binary;
    // 转换为灰度图像
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    // 自适应阈值与二值化
    cv::adaptiveThreshold(gray, binary, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 25, 10);

    imshow("binary", binary);

	cv::waitKey(0);

    return 0;
}