//---------------------------------------------------
// 描述：图像腐蚀操作
// 
// 腐蚀是形态学基本运算，即将图像中的暗色部分“腐蚀”掉图像中的亮色部分
//---------------------------------------------------
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src = cv::imread("images/1.jpg", cv::IMREAD_COLOR);
    cv::imshow("原图", src);
    
    cv::Mat dst;
    // 返回制定形状和尺寸的内核矩阵
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
    cv::erode(src, dst, element);

    cv::imshow("腐蚀之后的图像", dst);

    cv::waitKey();

    return 0;
}