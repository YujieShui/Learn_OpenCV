/*
 * @Description: 中值滤波
 * @Author: shuiyj
 * @Date: 2019-07-25 18:55:42
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

    cv::Mat dst1, dst2;

    cv::medianBlur(src, dst1, 5);
    cv::medianBlur(src, dst2, 15);

    cv::imshow("Ksize is 5", dst1);
    cv::imshow("Ksize is 15", dst2);

    cv::waitKey(0);

    return 0;
}