//---------------【边缘检测】----------------
// 描述：laplacian 函数用法示例
//------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src, src_gray, dst, abs_dst;

    // 载入原图像
    src = cv::imread("images/3.jpg", cv::IMREAD_COLOR);;
    cv::imshow("【原图】", src);

    // 使用高斯滤波降噪
    cv::GaussianBlur(src, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

    // 转换为灰度图
    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

    // 使用 Laplacian 函数
    cv::Laplacian(src_gray, dst, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT);

    //【6】计算绝对值，并将结果转换成8位
	convertScaleAbs( dst, abs_dst );

	//【7】显示效果图
	cv::imshow( "【效果图】图像Laplace变换", abs_dst );

	cv::waitKey(0); 

    return 0;
}