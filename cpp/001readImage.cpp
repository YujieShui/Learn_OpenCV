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