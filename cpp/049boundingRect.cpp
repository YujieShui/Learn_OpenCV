/*
 * @Description: 二值图像分析—轮廓外接矩形
 * @Author: shuiyj
 * @Date: 2019-07-30
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/4.jpeg");
	if (src.empty()) {
		printf("could not load image...\n");
	}
    cv::namedWindow("input", cv::WINDOW_AUTOSIZE);
	cv::imshow("input", src);

    // 边缘检测
    cv::Mat dst, gray, binary;
    cv::Canny(src, binary, 80, 160, 3, false);
    cv::imshow("binary", binary);
    cv::imwrite("./result/binary.png", binary);

    cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	cv::dilate(binary, binary, k);

    // 轮廓发现与绘制
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(binary, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());
	for (size_t t = 0; t < contours.size(); t++) {
		// 最大外接轮廓
		Rect rect = boundingRect(contours[t]);
		rectangle(src, rect, Scalar(0, 0, 255), 1, 8, 0);

		// 最小外接轮廓
		RotatedRect rrt = minAreaRect(contours[t]);
		Point2f pts[4];
		rrt.points(pts);
        
		for (int i = 0; i < 4; i++) {
			line(src, pts[i % 4], pts[(i + 1) % 4], Scalar(0, 255, 0), 2, 8, 0);
		}
		Point2f cpt = rrt.center;
		circle(src, cpt, 2, Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow("contours", src);

	waitKey(0);

    return 0;
}