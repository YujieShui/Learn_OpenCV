/*
 * @Description: 读取一张图片
 * @Author: shuiyj
 * @Date: 2019-07-22 17:05:37
 * @LastEditTime: 2019-07-22 17:07:55
 * @LastEditors: Do not edit
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    cv::Mat src = cv::imread("../images/1.png", cv::IMREAD_COLOR);
    
    if(src.empty())
    {
        printf("could not load image..\n");
        return -1;
    }

    cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
    cv::imshow("input", src);

    cv::waitKey();

    return 0;
}