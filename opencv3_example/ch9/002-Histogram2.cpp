//---------------【颜色直方图】----------------
// 描述：一维直方图的绘制
//-------------------------------------------

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
    // 读入原图
    cv::Mat srcImage;
    srcImage = cv::imread("images/2.jpg", cv::IMREAD_COLOR);
    if(!srcImage.data){ printf("加载图片错误");}

    // 颜色直方图存储结构
    cv::MatND dstHist;
    int dims = 1;
    float hranges[] = {0, 255};
    const float *ranges[] = {hranges};
    int size = 256;
    int channels = 0;

    // 计算图像的直方图
    cv::calcHist(&srcImage, 1, &channels, cv::Mat(), dstHist, dims, &size, ranges);
	int scale = 1;

    cv::Mat dstImage(size * scale, size, CV_8U, cv::Scalar(0));

    // 获取最大值、最小值
    double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist,&minValue, &maxValue, 0, 0);  //  在cv中用的是cvGetMinMaxHistValue


    //【绘制出直方图
	int hpt = cv::saturate_cast<int>(0.9 * size);
	for(int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);           //   注意hist中是float类型    而在OpenCV1.0版中用cvQueryHistValue_1D
		int realValue = cv::saturate_cast<int>(binValue * hpt/maxValue);
		rectangle(dstImage,cv::Point(i*scale, size - 1), cv::Point((i+1)*scale - 1, size - realValue), cv::Scalar(255));
	}
	imshow("一维直方图", dstImage);
	cv::waitKey(0);
	return 0;
}