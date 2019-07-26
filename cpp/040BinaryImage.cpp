/*
 * @Description: 二值图像
 * @Author: shuiyj
 * @Date: 2019-07-26
 */
#include <opencv2/opencv.hpp>
#include <iostream>

const float t = 0.95;

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
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Scalar m =  cv::mean(gray);
    int t = m[0];
    binary = cv::Mat::zeros(src.size(), CV_8UC1);

    // 直接读取图像像素
    int height = src.rows;
    int width = src.cols;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int pv = gray.at<uchar>(row, col);
            binary.at<uchar>(row, col) = pv > t ? 255 : 0;
        }        
    }
    
    cv::imshow("binary", binary);
    cv::waitKey(0);

    return 0;
}