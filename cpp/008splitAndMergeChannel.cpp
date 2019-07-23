/*
 * @Description: 分类与合并通道
 * @Author: shuiyj
 * @Date: 2019-07-23 18:47:45
 * @LastEditTime: 2019-07-23 18:58:50
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/1.png");

    if(src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }

    cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", src);

    std::vector<cv::Mat> mv;
    cv::Mat dst1, dst2, dst3;
    
    // 蓝色通道为 0
    cv::split(src, mv);
    mv[0] = cv::Scalar(0);
    cv::merge(mv, dst1);
    cv::imshow("dst1", dst1);

    // 绿色通道为 0
    cv::split(src, mv);
    mv[1] = cv::Scalar(0);
    cv::merge(mv, dst2);
    cv::imshow("dst2", dst2);

    // 红色通道为 0
    cv::split(src, mv);
    mv[2] = cv::Scalar(0);
    cv::merge(mv,dst3);
    cv::imshow("dst3", dst3);

    cv::waitKey(0);
    
    return 0;
}