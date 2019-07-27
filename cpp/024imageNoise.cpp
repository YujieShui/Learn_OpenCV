/*
 * @Description: 图像噪声
 * @Author: shuiyj
 * @Date: 2019-07-27 16:21:02
 */
#include <opencv2/opencv.hpp>
#include <iostream>

void add_salt_pepper_noise(cv::Mat &image);
void gaussian_noise(cv::Mat &image);

int main(int argc, char const *argv[])
{
    cv::Mat src = cv::imread("../images/lena.jpg");

    if (src.empty())
    {
        printf("could not load image");
        return -1;
    }

    cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", src);

    gaussian_noise(src);
    add_salt_pepper_noise(src);

    cv::waitKey(0);
    return 0;
}

void add_salt_pepper_noise(cv::Mat &image)
{
    cv::RNG  rng(12345);
    int h = image.rows;
    int w = image.cols;
    int nums = 10000;
    for (int i = 0; i < nums; i++) {
		int x = rng.uniform(0, w);
		int y = rng.uniform(0, h);
		if (i % 2 == 1) {
			image.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255);
		}
		else {
			image.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0);
		}
	}
	imshow("salt pepper", image);
}

void gaussian_noise(cv::Mat &image)
{
    cv::Mat noise = cv::Mat::zeros(image.size(), image.type());
	randn(noise, (15, 15, 15), (30, 30, 30));
	cv::Mat dst;
	add(image, noise, dst);
	imshow("gaussian noise", dst);
}