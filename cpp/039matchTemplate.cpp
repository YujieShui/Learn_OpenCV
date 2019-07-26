/*
 * @Description: 模板匹配
 * @Author: shuiyj
 * @Date: 2019-07-26
 */
#include <opencv2/opencv.hpp>
#include <iostream>

const float t = 0.95;

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/llk.png");
    cv::Mat tpl = cv::imread("../images/llk_tpl.png");

    if (src.empty() || tpl.empty())
    {
        printf("could not load image");
        return -1;
    }

    cv::imshow("src", src);
    cv::imshow("template", tpl);

    int result_h = src.rows - tpl.rows + 1;
    int result_w = src.cols - tpl.cols + 1;
    cv::Mat result = cv::Mat::zeros(cv::Size(result_w, result_h), CV_32FC1);
    
    cv::matchTemplate(src, tpl, result, CV_TM_CCOEFF_NORMED);
    cv::imshow("result image", result);

    int h = result.rows;
	int w = result.cols;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			float v = result.at<float>(row, col);
			// printf("v = %.2f\n", v);
			if (v > t) {
				rectangle(src, cv::Point(col, row), cv::Point(col + tpl.cols, row + tpl.rows), cv::Scalar(255, 0, 0), 1, 8, 0);
			}
		}
	}
	imshow("template matched result", src);

    cv::waitKey(0);

    return 0;
}