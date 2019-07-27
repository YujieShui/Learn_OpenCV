/*
 * @Description: 算数运算
 * @Author: shuiyj
 * @Date: 2019-07-27 14:07:11
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    cv::Mat src1 = cv::imread("../images/1.png");
    cv::Mat src2 = cv::imread("../images/2.jpg");

    if (src1.empty() || src2.empty())
    {
        printf("could not load image...\n");
        return -1;
    }

    // 图像的数据类型、通道数目、大小必须相同
    cv::resize(src2, src2, src1.size());

    cv::namedWindow("input1");
    cv::namedWindow("input2");
    cv::imshow("input1", src1);
    cv::imshow("input2", src2);

    int height = src1.rows;
    int width = src1.cols;

    int b1 = 0, g1 = 0, r1 = 0;
    int b2 = 0, g2 = 0, r2 = 0;
    int b = 0, g = 0, r = 0;

    cv::Mat result = cv::Mat::zeros(src1.size(), src1.type());
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            b1 = src1.at<cv::Vec3b>(row, col)[0];
            g1 = src1.at<cv::Vec3b>(row, col)[1];
            r1 = src1.at<cv::Vec3b>(row, col)[2];

            b2 = src2.at<cv::Vec3b>(row, col)[0];
            g2 = src2.at<cv::Vec3b>(row, col)[1];
            r2 = src2.at<cv::Vec3b>(row, col)[2];

            result.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(b1 + b2);
            result.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(g1 + g2);
            result.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(r1 + r2);
        }
    }
    cv::imshow("output", result);

    cv::Mat add_result = cv::Mat::zeros(src1.size(), src1.type());
	add(src1, src2, add_result);
	imshow("add_result", add_result);

	cv::Mat sub_result = cv::Mat::zeros(src1.size(), src1.type());
	subtract(src1, src2, sub_result);
	imshow("sub_result", sub_result);

	cv::Mat mul_result = cv::Mat::zeros(src1.size(), src1.type());
	multiply(src1, src2, mul_result);
	imshow("mul_result", mul_result);

	cv::Mat div_result = cv::Mat::zeros(src1.size(), src1.type());
	divide(src1, src2, div_result);
	imshow("div_result", div_result);

    cv::waitKey(0);

    return 0;
}