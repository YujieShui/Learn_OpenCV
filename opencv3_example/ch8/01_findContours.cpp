//------------------------------------------------------------
// 描述：基础轮廓查找——findContours + drawContours
//------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    // 载入灰度图像
    cv::Mat srcImage = cv::imread("images/1.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("【1】原图", srcImage);
    // 初始化结果图像
    cv::Mat dstImage = cv::Mat::zeros(cv::Size(srcImage.rows, srcImage.cols), CV_8UC3);

    srcImage = srcImage > 119;
    cv::imshow("【2】取阈值之后的原始图", srcImage);

    // 定义轮廓和层次
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;

    // 查找轮廓
    cv::findContours( srcImage, contours, hierarchy,cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE );

    // 遍历所有顶层的轮廓，以随机颜色绘制出每个连接组件颜色
    int index = 0;
    for( ; index >= 0; index = hierarchy[index][0] )
	{
		cv::Scalar color( rand()&255, rand()&255, rand()&255 );
		//此句代码的OpenCV2版为：
		//drawContours( dstImage, contours, index, color, CV_FILLED, 8, hierarchy );
		//此句代码的OpenCV3版为：
		cv::drawContours( dstImage, contours, index, color, cv::FILLED, 8, hierarchy );
	}

	//显示最后的轮廓图
	cv::imshow( "轮廓图", dstImage );
	cv::waitKey(0);

    return 0;
}