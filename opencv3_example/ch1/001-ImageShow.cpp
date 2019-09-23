#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src = cv::imread("images/1.jpg", cv::IMREAD_COLOR);

    cv::namedWindow("src", cv::WINDOW_NORMAL);

    cv::imshow("src", src);

    cv::waitKey(0);

    return 0;
}
