//-------------------------------------------
// 描述：resize函数用法示例
//-------------------------------------------

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat srcImage = cv::imread("images/6.jpg", cv::IMREAD_COLOR);
    cv::Mat tmpImage, dstImage1, dstImage2;
    tmpImage = srcImage;

    cv::imshow("【原图】", srcImage);

    cv::resize(tmpImage, dstImage1, cv::Size(srcImage.cols /2, srcImage.rows/2), (0, 0), (0, 0), 3);
    cv::resize(tmpImage, dstImage2, cv::Size(srcImage.cols*2, srcImage.rows*2), (0, 0), (0, 0), 3);

    cv::imshow("【效果图1】", dstImage1);
    cv::imshow("【效果图2】", dstImage2);

    cv::waitKey(0);

    return 0;
}