//--------------------------------------------------------------------
// 描述: 调整图像的对比度和亮度 p131
//--------------------------------------------------------------------

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

static void ContrastAndBright(int, void *);

int g_nContrastValue; //对比度值
int g_nBrightValue;   //亮度值
cv::Mat g_srcImage, g_dstImage;

int main()
{
    system("color 2F");

    // 读取图像
    g_srcImage = cv::imread("images/7.jpg", cv::IMREAD_COLOR);
    if (!g_srcImage.data)
        std::cout << "g_srcImage 读取失败." << std::endl;
    g_dstImage = cv::Mat(g_srcImage.size(), g_srcImage.type());

    // 设置对比度和亮度初值
    g_nContrastValue = 80;
    g_nBrightValue = 80;

    // 创建窗口
    cv::namedWindow("【效果图窗口】", cv::WINDOW_FULLSCREEN);

    // 创建轨迹条
    cv::createTrackbar("对比度", "【效果图窗口】", &g_nContrastValue, 300, ContrastAndBright);
    cv::createTrackbar("亮 度", "【效果图窗口】", &g_nBrightValue, 200, ContrastAndBright);

    //调用回调函数
    ContrastAndBright(g_nContrastValue, 0);
    ContrastAndBright(g_nBrightValue, 0);

    //输出一些帮助信息
    std::cout << std::endl
              << "\t运行成功，请调整滚动条观察图像效果\n\n"
              << "\t按下“q”键时，程序退出\n";

    //按下“q”键时，程序退出
    while (char(cv::waitKey(1)) != 'q')
        ;
    return 0;

    return 0;
}

/**
 * 描述: 改变图像对比度和亮度的回调函数 
 **/
static void ContrastAndBright(int, void *)
{
    // 创建窗口
    cv::namedWindow("【原始图窗口】", 1);

    // 三个for循环，执行运算 g_dstImage(i,j) = a*g_srcImage(i,j) + b
    for (int y = 0; y < g_srcImage.rows; y++)
    {
        for (int x = 0; x < g_srcImage.cols; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                g_dstImage.at<cv::Vec3b>(y, x)[c] =
                    cv::saturate_cast<uchar>((g_nContrastValue * 0.01) * (g_srcImage.at<cv::Vec3b>(y, x)[c]) + g_nBrightValue);
            }
        }
    }

    // 显示图像
    imshow("【原始图窗口】", g_srcImage);
    imshow("【效果图窗口】", g_dstImage);
}
