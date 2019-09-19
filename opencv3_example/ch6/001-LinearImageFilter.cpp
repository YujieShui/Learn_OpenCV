//-----------------------【线性滤波程序示例】---------------------------------
// 1. 方框滤波, boxFilter()
// 2. 均值滤波, blur()
// 3. 高斯滤波, GaussianBlur()
// 
// 函数参数的含义 | 卷积核大小的选取 | 回调函数 | TrackBar 的创建
//-------------------------------------------------------------------------

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;
int g_nBoxFilterValue = 3;    // 方框滤波参数值
int g_nMeanFilterValue = 3;   // 均值滤波参数值
int g_nGaussianBlurValue = 3; // 高斯滤波参数值

// Trackebar 回调函数
static void on_BoxFilter(int, void *);
static void on_MeanFilter(int, void *);
static void on_GaussianBlur(int, void *);

int main()
{
    // 载入原图
    g_srcImage = imread("images/1.jpg", IMREAD_COLOR);

    if (!g_srcImage.data)
    {
        printf("原图读取失败.\n");
        return -1;
    }

    // 克隆原图到 Mat 类型中
    g_dstImage1 = g_srcImage.clone();
    g_dstImage2 = g_srcImage.clone();
    g_dstImage3 = g_srcImage.clone();

    // 显示原图
    namedWindow("【0】原图", WINDOW_NORMAL);
    imshow("【0】原图", g_srcImage);

    //==================【方框函数 boxFilter()】====================
    namedWindow("【1】方框滤波", WINDOW_NORMAL);
    createTrackbar("卷积核尺寸", "【1】方框滤波", &g_nBoxFilterValue, 40, on_BoxFilter);
    on_BoxFilter(g_nBoxFilterValue, 0);

    //==================【均值函数 blur()】====================
    namedWindow("【2】均值滤波", WINDOW_NORMAL);
    createTrackbar("卷积核尺寸", "【2】均值滤波", &g_nMeanFilterValue, 40, on_MeanFilter);
    on_MeanFilter(g_nMeanFilterValue, 0);

    //==================【高斯滤波 GaussianBlur()】====================
    namedWindow("【3】高斯滤波", WINDOW_NORMAL);
    createTrackbar("卷积核尺寸", "【3】高斯滤波", &g_nGaussianBlurValue, 40, on_GaussianBlur);
    on_GaussianBlur(g_nGaussianBlurValue, 0);

    // 按下 'q' 退出程序
    while (char(waitKey(1)) != 'q')
        ;

    return 0;
}

/**
 * 描述：方框滤波操作的回调函数 
 **/
static void on_BoxFilter(int, void *)
{
    // 方框滤波操作
    boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
    imshow("【1】方框滤波", g_dstImage1);
}

static void on_MeanFilter(int, void *)
{
    // 均值滤波操作
    blur(g_srcImage, g_dstImage2, Size(g_nMeanFilterValue + 1, g_nMeanFilterValue + 1), Point(-1, -1));
    imshow("【2】均值滤波", g_dstImage2);
}

static void on_GaussianBlur(int, void *)
{
    // 高斯滤波操作
    GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
    imshow("【3】高斯滤波", g_dstImage3);
}