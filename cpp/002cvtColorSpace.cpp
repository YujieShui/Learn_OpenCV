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

    cv::namedWindow("color", cv::WINDOW_AUTOSIZE);
    cv::imshow("color", src);

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    
    cv::namedWindow("gray", cv::WINDOW_AUTOSIZE);
    cv::imshow("gray", src);

    cv::waitKey();

    return 0;
}