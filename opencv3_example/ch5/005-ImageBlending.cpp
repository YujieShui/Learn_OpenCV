#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

bool ROI_AddImage();
bool LinearBleading();

int main()
{

    if(ROI_AddImage() && LinearBleading())
    {
        std::cout << "图像融合成功" << std::endl;
    }

    cv::waitKey(0);

    return 0;
}


//--------------------------------------------------------------------
// 函数名: ROI_AddImage()
// 描述: 选取图像 ROI，用新的图像代替这个 ROI
//--------------------------------------------------------------------
bool ROI_AddImage()
{
    cv::Mat srcImage = cv::imread("images/dota_pa.jpg", cv::IMREAD_COLOR);
    cv::Mat logoImage = cv::imread("images/dota_logo.jpg", cv::IMREAD_COLOR);

    if(!srcImage.data)
    {
        printf("读取 srcImage 失败。");
        return false;
    }

    if(!logoImage.data)
    {
        printf("读取 logoImage 失败。");
        return false;
    }

    // 从 srcImage 中选取 ROI 区域
    cv::Mat imageROI = srcImage(cv::Rect(200, 250, logoImage.cols, logoImage.rows));
    
    // 掩膜（必须是灰度图）
    cv::Mat mask = cv::imread("images/data_log.jpg", cv::IMREAD_GRAYSCALE);

    // 将掩膜拷贝到 ROI
    logoImage.copyTo(imageROI, mask);

    cv::namedWindow("利用 ROI 实现图像叠加示例窗口");
    cv::imshow("利用 ROI 实现图像叠加示例窗口", srcImage);

    return true;

}

//--------------------------------------------------------------------
// 函数名: LinearBleading()
// 描述: cv::addWeighted() 函数实现线性融合
//--------------------------------------------------------------------
bool LinearBleading()
{
    double alphaValue = 0.5;
    double betaValue;
    cv::Mat srcImage1, srcImage2, dstImage;

    srcImage1 = cv::imread("images/mogu.jpg", cv::IMREAD_COLOR);
    srcImage2 = cv::imread("images/rain.jpg", cv::IMREAD_COLOR);

    if(!srcImage1.data)
    {
        printf("读取 srcImage1 失败。");
        return false;
    }

    if(!srcImage2.data)
    {
        printf("读取 srcImage2 失败。");
        return false;
    }

    // 做图像混合加权操作
    betaValue = (1.0 - alphaValue);
    cv::addWeighted(srcImage1, alphaValue, srcImage2, betaValue, 0.0, dstImage);

    cv::namedWindow("图像加权融合", cv::WINDOW_NORMAL);
    cv::imshow("图像加权融合", dstImage);

    return true;
}