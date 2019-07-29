/*
 * @Description: 二值图像联通组件寻找
 * @Author: shuiyj
 * @Date: 2019-07-29
 */
#include <opencv2/opencv.hpp>
#include <iostream>

cv::RNG rng(12345);
void connected_component_demo(cv::Mat &image);

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/rice.png");

    if (src.empty())
    {
        printf("could not load image");
        return -1;
    }

    cv::imshow("src", src);
    connected_component_demo(src);

    cv::waitKey(0);
    return 0;
}

void connected_component_demo(cv::Mat &image)
{
    // extract image
    cv::Mat gray, binary;
    cv::GaussianBlur(image, image, cv::Size(3, 3), 0);
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    
    cv::Mat labels = cv::Mat::zeros(image.size(), CV_32S);
	int num_labels = cv::connectedComponents(binary, labels, 8, CV_32S);
    std::vector<cv::Vec3b> colors(num_labels);

    // background color
    colors[0] = cv::Vec3b(0, 0, 0);

    // object color
    // background color
	colors[0] = cv::Vec3b(0, 0, 0);

	// object color
	for (int i = 1; i < num_labels; i++) {
		colors[i] = cv::Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
	}

	// render result
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	int w = image.cols;
	int h = image.rows;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int label = labels.at<int>(row, col);
			if (label == 0) continue;
			dst.at<cv::Vec3b>(row, col) = colors[label];
		}
	}
	imshow("ccla-demo", dst);
}