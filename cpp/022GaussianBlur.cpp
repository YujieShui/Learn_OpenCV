/*
 * @Description: 高斯模糊
 * @Author: shuiyj
 * @Date: 2019-07-25 18:42:04
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

    cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", src);

    cv::Mat dst;
    cv::GaussianBlur(src, dst, cv::Size(5, 5), 15, 0, 4);

    cv::imshow("gaussianBlur", dst);

    cv::waitKey(0);

    return 0;
}