#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

bool MultiChannelBlending();

int main()
{

    MultiChannelBlending();
    cv::waitKey(0);

    return 0;
}

//------------------------------------------
// 描述：多通道混合的函数
//------------------------------------------
bool MultiChannelBlending()
{
    cv::Mat srcImage, logoImage;
    std::vector<cv::Mat> channels;

    srcImage = cv::imread("images/dota_pa.jpg", cv::IMREAD_COLOR);
    logoImage = cv::imread("images/dota_logo.jpg", cv::IMREAD_GRAYSCALE);

    if (!srcImage.data)
    {
        printf("读取 srcImage 失败。");
        return false;
    }

    if (!logoImage.data)
    {
        printf("读取 logoImage 失败。");
        return false;
    }

    // split() 分离通道
    cv::split(srcImage, channels);

    //------------------------------------------------
    // 蓝色通道混合
    //------------------------------------------------

    cv::Mat imageBlueChannel = channels.at(0);

    // ROI 区域进行线性融合
    cv::addWeighted(imageBlueChannel(cv::Rect(500, 250, logoImage.cols, logoImage.rows)), 0.5,
                    logoImage, 0.5, 0, imageBlueChannel(cv::Rect(500, 250, logoImage.cols, logoImage.rows)));

    cv::namedWindow("【1】蓝色通道混合", cv::WINDOW_NORMAL);
    cv::imshow("【1】蓝色通道混合", imageBlueChannel);

    //------------------------------------------------
    // 绿色通道混合
    //------------------------------------------------

    srcImage = cv::imread("images/dota_pa.jpg", cv::IMREAD_COLOR);
    logoImage = cv::imread("images/dota_logo.jpg", cv::IMREAD_GRAYSCALE);

    cv::Mat imageGreenChannel = channels.at(1);
    cv::addWeighted(imageGreenChannel(cv::Rect(500, 250, logoImage.cols, logoImage.rows)), 0.5,
                    logoImage, 0.5, 0.0, imageGreenChannel(cv::Rect(500, 250, logoImage.cols, logoImage.rows)));

    cv::namedWindow("【2】绿色通道混合", cv::WINDOW_NORMAL);
    cv::imshow("【2】绿色通道混合", imageGreenChannel);

    //------------------------------------------------
    // 红色通道混合
    //------------------------------------------------

    srcImage = cv::imread("images/dota_pa.jpg", cv::IMREAD_COLOR);
    logoImage = cv::imread("images/dota_logo.jpg", cv::IMREAD_GRAYSCALE);

    cv::Mat imageRedChannel = channels.at(2);
    cv::addWeighted(imageRedChannel(cv::Rect(500, 250, logoImage.cols, logoImage.rows)), 0.5,
                    logoImage, 0.5, 0.0, imageRedChannel(cv::Rect(500, 250, logoImage.cols, logoImage.rows)));

    cv::namedWindow("【3】红色通道混合", cv::WINDOW_NORMAL);
    cv::imshow("【3】红色通道混合", imageRedChannel);

    return true;
}