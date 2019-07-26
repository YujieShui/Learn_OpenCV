/*
 * @Description: OTSU二值寻找算法
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

    cv::Mat gray, binary;
    // 转换为灰度图像
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    // 自动阈值查找与二值化
    double t = cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    printf("threshold : %.2f\n", t);

    cv::imshow("binary", binary);

    cv::waitKey(0);

    return 0;
}