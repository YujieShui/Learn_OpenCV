//---------------【颜色直方图】----------------
// 描述：H-S二维直方图的绘制
//-------------------------------------------

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat srcImage, hsvImage;
    srcImage = cv::imread("images/1.jpg", cv::IMREAD_COLOR);
    if(!srcImage.data){ printf("加载图片错误");}
    cv::cvtColor(srcImage, hsvImage, cv::COLOR_BGR2HSV);

    // 将色调量化为30个等级，将饱和度量化为32个等级
    int hueBinNum = 30;        // 色调的直方图 bin 的数量
    int saturationBinNum = 32; // 饱和度直方图 bin 的数量
    int histSize[] = {hueBinNum, saturationBinNum};
    // 定义色调的变化范围为0到179
    float hueRanges[] = {0, 180};
    //定义饱和度的变化范围为0（黑、白、灰）到255（纯光谱颜色）
    float saturationRanges[] = {0, 256};
    const float *ranges[] = {hueRanges, saturationRanges};
    cv::MatND dstHist;
    //参数准备，calcHist函数中将计算第0通道和第1通道的直方图
    int channels[] = {0, 1};

    cv::calcHist(&hsvImage, //输入的数组
             1,         //数组个数为1
             channels,  //通道索引
             cv::Mat(),     //不使用掩膜
             dstHist,   //输出的目标直方图
             2,         //需要计算的直方图的维度为2
             histSize,  //存放每个维度的直方图尺寸的数组
             ranges,    //每一维数值的取值范围数组
             true,      // 指示直方图是否均匀的标识符，true表示均匀的直方图
             false);    //累计标识符，false表示直方图在配置阶段会被清零

    double maxValue = 0;                    //最大值
    cv::minMaxLoc(dstHist, 0, &maxValue, 0, 0); //查找数组和子数组的全局最小值和最大值存入maxValue中
    int scale = 10;
    cv::Mat histImg = cv::Mat::zeros(saturationBinNum * scale, hueBinNum * 10, CV_8UC3);

    // 双层循环，进行直方图绘制
    for (int hue = 0; hue < hueBinNum; hue++)
        for (int saturation = 0; saturation < saturationBinNum; saturation++)
        {
            float binValue = dstHist.at<float>(hue, saturation); //直方图组距的值
            int intensity = cvRound(binValue * 255 / maxValue);  //强度

            //正式进行绘制
            rectangle(histImg, cv::Point(hue * scale, saturation * scale),
                      cv::Point((hue + 1) * scale - 1, (saturation + 1) * scale - 1),
                      cv::Scalar::all(intensity), cv::FILLED);
        }

    imshow("素材图", srcImage);
    imshow("H-S 直方图", histImg);

    cv::waitKey();

    return 0;
}