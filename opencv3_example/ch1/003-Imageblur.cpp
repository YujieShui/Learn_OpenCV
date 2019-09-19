//---------------------------------------------------
// 描述：图像模糊操作
//
// 使用均值滤波实现图像模糊功能
//---------------------------------------------------
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src = cv::imread("images/3.jpg", cv::IMREAD_COLOR);

    cv::Mat dst;

    // 使用均值滤波
    cv::blur(src, dst, cv::Size(7, 7));

    cv::imshow("src", src);
    cv::imshow("模糊之后的图像", dst);

    cv::waitKey(0);

    return 0;
}