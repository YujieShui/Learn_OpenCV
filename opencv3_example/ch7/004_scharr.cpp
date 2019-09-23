//---------------【边缘检测】----------------
// 描述：laplacian 函数用法示例
//------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat grad_x, grad_y;
    cv::Mat abs_grad_x, abs_grad_y, dst;

    cv::Mat src = cv::imread("images/4.jpg", cv::IMREAD_COLOR);
    cv::imshow("【原始图】", src);

	cv::Scharr( src, grad_x, CV_16S, 1, 0, 1, 0, cv::BORDER_DEFAULT);
	cv::convertScaleAbs( grad_x, abs_grad_x );
	cv::imshow("【效果图】 X方向Scharr", abs_grad_x); 

	cv::Scharr( src, grad_y, CV_16S, 0, 1, 1, 0, cv::BORDER_DEFAULT );
	cv::convertScaleAbs( grad_y, abs_grad_y );
	cv::imshow("【效果图】Y方向Scharr", abs_grad_y); 

	addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst );

	imshow("【效果图】合并梯度后Scharr", dst); 

	cv::waitKey(0); 
	return 0; 
}