/*
 * @Description: 创建 Mat 的几种方法
 * @Author: shuiyj
 * @Date: 2019-07-22 16:34:19
 * @LastEditTime: 2019-07-22 17:07:03
 * @LastEditors: Do not edit
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    cv::Mat src = cv::imread("../images/1.png");

    if (src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }

    cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", src);

    cv::Mat m1 = src.clone();

    cv::Mat m2;
    src.copyTo(m2);

    cv::Mat m3 = src;

    cv::Mat m4 = cv::Mat::zeros(src.size(), src.type());
    cv::Mat m5 = cv::Mat::zeros(cv::Size(512, 512), CV_8UC3);
    cv::Mat m6 = cv::Mat::ones(cv::Size(512, 512), CV_8UC3);

    // 创建卷积核的方法
    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0,
                                            -1, 5, -1,
                                            0, -1, 0);

    cv::waitKey(0);

    return 0;
}