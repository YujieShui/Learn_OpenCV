//-------------------------------------------
// 描述：pyrUp 函数用法示例
//-------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat srcImage = cv::imread("images/6.jpg", cv::IMREAD_COLOR);
    if(!srcImage.data){ printf("读取图像失败。"); }
    cv::Mat tmpImage, dstImage;

    tmpImage = srcImage;

    cv::pyrUp(tmpImage, dstImage, cv::Size(srcImage.cols*2, srcImage.rows*2));

    cv::imshow("【原图】", srcImage);
    cv::imshow("【效果图】", dstImage);

    cv::waitKey(0);

    return 0;
}