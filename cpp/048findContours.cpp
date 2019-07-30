/*
 * @Description: 二值图像分析—轮廓发现
 * @Author: shuiyj
 * @Date: 2019-07-30
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/coins.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
	}
	cv::imshow("input", src);

    // 去噪与二值化
    cv::Mat dst, gray, binary;
    cv::GaussianBlur(src, dst, cv::Size(3, 3), 0, 0);
    cv::cvtColor(dst, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::imshow("binary", binary);
    cv::imwrite("../result/binary.png", binary);

    // 轮廓发现与绘制
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(binary, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point());
    for (size_t t = 0; t < contours.size(); t++) {
		drawContours(src, contours, t, cv::Scalar(0, 0, 255), 2, 8);
	}
	cv::imshow("contours", src);

    cv::waitKey(0);

    return 0;
}