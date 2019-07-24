/*
 * @Description: 图像翻转 
 * @Author: shuiyj
 * @Date: 2019-07-24
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

    cv::Mat dst;

    // X Flip 倒影
    cv::flip(src, dst, 0);
    cv::imshow("X Flip", dst);

    // Y Flip 镜像
    cv::flip(src, dst, 1);
    cv::imshow("Y Flip", dst);

    // XY Flip 对角
    cv::flip(src, dst, -1);
    cv::imshow("XY Flip", dst);

    cv::waitKey(0);

    return 0;
}
