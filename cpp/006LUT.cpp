/*
 * @Description: Look Up Table(LUT)查找表 
 * @Author: shuiyj
 * @Date: 2019-07-22 17:08:36
 * @LastEditTime: 2019-07-22 19:20:54
 * @LastEditors: Do not edit
 */
#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * @description: 自定义 LUT, 将 0~126 映射为 0,将 127~255 映射为 255
 * @param {cv::Mat} 
 * @return: 
 */
void customColorMap(cv::Mat &image);

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/2.jpg");

    if (src.empty())
    {
        printf("could not load images ...\n");
        return -1;
    }

    cv::Mat grey, dst;

    // 使用 OpenCV 的 LUT
    cv::applyColorMap(src, dst, cv::COLORMAP_HOT);

    cv::imshow("src", src);
    cv::imshow("colorMap", dst);

    cv::cvtColor(src, grey, cv::COLOR_BGR2GRAY);
    cv::imshow("grey", grey);
    customColorMap(grey);

    cv::waitKey(0);

    return 0;
}

void customColorMap(cv::Mat &image)
{
    int lut[256];
    for (int i = 0; i < 256; i++)
    {
        if(i < 127)
        {
            lut[i] = 0;
        }else
        {
            lut[i] = 255;
        }
    }

    int h = image.rows;
    int w = image.cols;

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            int pv = image.at<uchar>(row, col);
            image.at<uchar>(row, col) = lut[pv];
        }
    }

    cv::imshow("customColorMap", image);
}