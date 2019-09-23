//----------------------------------------------------------
// 描述：
// 1. 图像载入与显示
// 2. 图像融合，将 logo 添加到原图上
//----------------------------------------------------------

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    //-------------------【图像载入和显示三部曲】-------------------
    // 1. imread() 载入图像
    // 2. namedWindow() 载入窗体
    // 3. imshow() 组合窗体和图像后显示图像
    // 4. waiKey(0) 表示按任意键停止显示图像
    // 
    // 注：图像读取方式、窗体效果可以使用参数控制
    //----------------------------------------------------------
    
    cv::Mat girl = cv::imread("images/girl.jpg", cv::IMREAD_COLOR);
    cv::Mat image = cv::imread("images/dota.jpg", cv::IMREAD_COLOR);
    cv::Mat logo = cv::imread("images/dota_logo.jpg", cv::IMREAD_COLOR);

    cv::namedWindow("【1】动漫图", cv::WINDOW_NORMAL);
    cv::namedWindow("【2】原画图", cv::WINDOW_NORMAL);
    cv::namedWindow("【3】logo 图", cv::WINDOW_NORMAL);

    cv::imshow("【1】动漫图", girl);
    cv::imshow("【2】原画图", image);
    cv::imshow("【3】logo 图", logo);
    cv::imshow("【3】logo 图", logo);


    //-------------------【图像融合】-------------------
    // 将 logo 添加到原图上
    //----------------------------------------------------------

    // 保存图像 ROI
    cv::Mat imageROI;
    // 方法 1 
    imageROI = image(cv::Rect(800, 350, logo.cols, logo.rows));
    // 方法 2
    // imageROI = image(cv::Range(350, 350+logo.rows), cv::Range(800, 800+logo.cols));
    
    // 将 logo 添加到原图上
    cv::addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

    cv::namedWindow("【4】原图加 logo", cv::WINDOW_NORMAL);
    cv::imshow("【4】原图加 logo", image);

    cv::waitKey(0);

    return 0;
}