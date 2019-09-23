//---------------【边缘检测】----------------
// 描述：canny 函数用法示例
//-------------------------------------------

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat srcImage = cv::imread("images/1.jpg");
    cv::Mat srcImage1 = srcImage.clone();

    imshow("【原图】", srcImage);

    //---------------------------------------------------------------------
    // 转成灰度图、降噪、用 Canny、得到的边缘作为掩膜，拷贝原图到效果图上，得到彩色图像
    //---------------------------------------------------------------------
    cv::Mat dstImage, edge, grayImage;

    // 【1】创建与 src 同类型和大小的矩阵
    dstImage.create(srcImage.size(), srcImage1.type());

    // 【2】将原图像转换成灰度图像
    cv::cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);
    
    // 【3】使用 3x3 的内核降噪
    cv::blur(grayImage, edge, cv::Size(3, 3));

    // 【4】使用 canny 算子
    cv::Canny(edge, edge, 3, 9, 3);

    // 【5】将 g_dstImage 内错有元素设置为 0
    dstImage = cv::Scalar::all(0);

    // 【6】使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
    srcImage1.copyTo(dstImage, edge);

    //【7】显示效果图 
	imshow("【效果图】Canny边缘检测2", dstImage); 

    cv::waitKey(0);

    return 0;
}