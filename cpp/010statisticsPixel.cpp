/*
 * @Description: 像素值统计
 * @Author: shuiyj
 * @Date: 2019-07-23 19:54:39
 * @LastEditTime: 2019-07-24 11:06:12
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/1.png");

    if (src.empty())
    {
        printf("could not load image");
        return -1;
    }

    cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", src);

    double minVal, maxVal;
    cv::Point minLoc, maxLoc;

    // 像素最小值,最大值
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::minMaxLoc(gray, &minVal, &maxVal, &minLoc, &maxLoc);
    printf("min: %.2f, max: %.2f \n", minVal, maxVal);
    printf("min loc: (%d, %d) \n", minLoc.x, minLoc.y);
    printf("max loc: (%d, %d)\n", maxLoc.x, maxLoc.y);

    // 彩色图像,三通道的均值与方差
    src = cv::imread("../images/2.jpg");
    cv::Mat means, stddev;
    cv::meanStdDev(src, means, stddev);
    printf("blue channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(0, 0), stddev.at<double>(0, 0));
    printf("green channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(1, 0), stddev.at<double>(1, 0));
    printf("red channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(2, 0), stddev.at<double>(2, 0));

    cv::waitKey(0);

    return 0;
}
