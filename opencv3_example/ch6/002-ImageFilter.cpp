//-----------------------【线性滤波 + 非线性滤波程序示例】---------------------------------
// 线性滤波
// 1. 方框滤波, boxFilter()
// 2. 均值滤波, blur()
// 3. 高斯滤波, GaussianBlur()
//
// 非线性滤波
// 1. 中值滤波,
// 2. 双边滤波,
// 函数参数的含义 | 卷积核大小的选取 | 回调函数 | TrackBar 的创建
//-------------------------------------------------------------------------

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3,
    g_dstImage4, g_dstImage5;

int g_nBoxFilterValue = 6;        // 方框滤波卷积核大小
int g_nMeanFilterValue = 10;      // 均值滤波卷积核大小
int g_nGaussianBlurValue = 6;     // 高斯滤波卷积核大小
int g_nMedianBlurValue = 10;      // 中值滤波卷积核代销
int g_nBilateralFilterValue = 10; // 双边滤波卷积核大小

// Trackebar 回调函数
static void on_BoxFilter(int, void *);
static void on_MeanFilter(int, void *);
static void on_GaussianBlur(int, void *);
static void on_MedianFilter(int, void *);
static void on_Bilateral(int, void *);

int main()
{

    // 读取原图
    g_srcImage = cv::imread("images/2.jpg", cv::IMREAD_COLOR);

    if (!g_srcImage.data)
    {
        printf("读取原图失败.");
    }

    // 拷贝 Mat
    g_dstImage1 = g_srcImage.clone();
    g_dstImage2 = g_srcImage.clone();
    g_dstImage3 = g_srcImage.clone();
    g_dstImage4 = g_srcImage.clone();
    g_dstImage5 = g_srcImage.clone();

    //==================【方框函数 boxFilter()】====================
    cv::namedWindow("【1】方框滤波", cv::WINDOW_NORMAL);
    cv::createTrackbar("卷积核尺寸", "【1】方框滤波", &g_nBoxFilterValue, 40, on_BoxFilter);
    on_BoxFilter(g_nBoxFilterValue, 0);

    //==================【均值滤波 blur()】====================
    cv::namedWindow("【2】均值滤波", cv::WINDOW_NORMAL);
    cv::createTrackbar("卷积核尺寸", "【2】均值滤波", &g_nMeanFilterValue, 40, on_MeanFilter);
    on_MeanFilter(g_nMeanFilterValue, 0);

    //==================【高斯滤波 GaussianBlur()】====================
    cv::namedWindow("【3】高斯滤波", cv::WINDOW_NORMAL);
    cv::createTrackbar("卷积核尺寸", "【3】高斯滤波", &g_nGaussianBlurValue, 40, on_GaussianBlur);
    on_GaussianBlur(g_nGaussianBlurValue, 0);

    //==================【中值滤波 medianBlur()】====================
    cv::namedWindow("【4】中值滤波", cv::WINDOW_NORMAL);
    cv::createTrackbar("卷积核尺寸", "【4】中值滤波", &g_nMedianBlurValue, 40, on_MedianFilter);
    on_GaussianBlur(g_nMedianBlurValue, 0);

    //==================【双边滤波 bilateralFilter()】====================
    cv::namedWindow("【5】双边滤波", cv::WINDOW_NORMAL);
    cv::createTrackbar("卷积核尺寸", "【5】双边滤波", &g_nBilateralFilterValue, 40, on_Bilateral);
    on_GaussianBlur(g_nBilateralFilterValue, 0);

    while (char(cv::waitKey(1)) != 'q')
        ;

    return 0;
}

static void on_BoxFilter(int, void *)
{
    // 方框滤波
    cv::boxFilter(g_srcImage, g_dstImage1, -1, cv::Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
    cv::imshow("【1】方框滤波", g_dstImage1);
}

static void on_MeanFilter(int, void *)
{
    // 均值滤波
    cv::blur(g_srcImage, g_dstImage2, cv::Size(g_nMeanFilterValue + 1, g_nMeanFilterValue + 1), cv::Point(-1, -1));
    cv::imshow("【2】均值滤波", g_dstImage2);
}

static void on_GaussianBlur(int, void *)
{
    // 高斯滤波
    cv::GaussianBlur(g_srcImage, g_dstImage3, cv::Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
    cv::imshow("【3】高斯滤波", g_dstImage3);
}

static void on_MedianFilter(int, void *)
{
    // 中值滤波
    cv::medianBlur(g_srcImage, g_dstImage4, g_nMedianBlurValue * 2 + 1);
    cv::imshow("【4】中值滤波", g_dstImage4);
}

static void on_Bilateral(int, void *)
{
    // 双边滤波
    cv::bilateralFilter(g_srcImage, g_dstImage5, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
    cv::imshow("【5】双边滤波", g_dstImage5);
}