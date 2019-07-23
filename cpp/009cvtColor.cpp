/*
 * @Description: 颜色空间转换
 * @Author: shuiyj
 * @Date: 2019-07-23 19:14:29
 * @LastEditTime: 2019-07-23 19:41:28
 * @LastEditors: Do not edit
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

    // BGR to HSV
    cv::Mat hsv;
    cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);
    cv::imshow("hsv", hsv);

    // RGB to YUV
    cv::Mat yuv;
    cv::cvtColor(src, yuv, cv::COLOR_BGR2YUV);
    cv::imshow("yuv", yuv);

    // RGB to YUV
    cv::Mat ycrcb;
    cv::cvtColor(src, ycrcb, cv::COLOR_BGR2YCrCb);
    cv::imshow("ycrcb", ycrcb);

    cv::Mat src2 = cv::imread("../images/2.jpg");
    cv::imshow("src2", src2);
    cv::cvtColor(src2, hsv, cv::COLOR_BGR2HSV);
    cv::Mat mask;
    cv::inRange(hsv, cv::Scalar(35, 43, 46), cv::Scalar(99, 255, 255), mask);
    cv::imshow("mask", mask);

    cv::waitKey(0);

    return 0;
}
