/*
 * @Description: 像素的逻辑运算
 * @Author: shuiyj
 * @Date: 2019-07-23 11:46:10
 * @LastEditTime: 2019-07-23 18:59:20
 */
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
    // create image src1
    cv::Mat src1 = cv::Mat::zeros(cv::Size(500, 500), CV_8UC3);
    cv::Rect rect(100, 100, 100, 100);
    src1(rect) = cv::Scalar(0, 0, 255);
    cv::imshow("src1", src1);

    // create image src2
    cv::Mat src2 = cv::Mat::zeros(cv::Size(500, 500), CV_8UC3);
    rect.x = 150;
    rect.y = 150;
    src2(rect) = cv::Scalar(0, 255, 255);
    cv::imshow("src2", src2);

    // 逻辑操作
    cv::Mat dst1, dst2, dst3;
    cv::bitwise_and(src1, src2, dst1);
    cv::bitwise_xor(src1, src2, dst2);
    cv::bitwise_or(src1, src2, dst3);

    cv::imshow("dst1", dst1);
    cv::imshow("dst2", dst2);
    cv::imshow("dst3", dst3);

    // 取反操作
    cv::Mat src = cv::imread("../images/1.png");
    cv::Mat dst;

    cv::bitwise_not(src, dst);

    cv::imshow("src", src);
    cv::imshow("dst", dst);

    cv::waitKey(0);

    return 0;
}
