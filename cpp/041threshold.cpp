/*
 * @Description: 基本阈值操作
 * @Author: shuiyj
 * @Date: 2019-07-26
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

    // 转换为灰度图像
    int T = 127;
    cv::Mat gray, binary;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    for (int i = 0; i < 5; i++)
    {
        cv::threshold(gray, binary, T, 255, i);
        cv::imshow(cv::format("binart_%d", i), binary);
    }

    cv::waitKey(0);

    return 0;
}