/*
 * @Description: OpenCV 遍历图像
 * @Author: shuiyj
 * @Date: 2019-07-27 11:39:52
 */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    cv::Mat src = cv::imread("../images/1.png");

    if (src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }

    cv::namedWindow("input");
    cv::imshow("input", src);

    // 直接读取
    int h = src.rows;
    int w = src.cols;
    int ch = src.channels();

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if (ch == 3)
            {
                cv::Vec3b bgr = src.at<cv::Vec3b>(row, col);
                bgr[0] = 255 - bgr[0];
                bgr[1] = 255 - bgr[1];
                bgr[2] = 255 - bgr[2];
                src.at<cv::Vec3b>(row, col) = bgr;
            }

            if (ch == 1)
            {
                int gray = src.at<uchar>(row, col);
                src.at<uchar>(row, col) = 255 - gray;
            }
        }
    }

    cv::imshow("output", src);

    // 指针遍历
    cv::Mat result = cv::Mat::zeros(src.size(), src.type());
    int blue = 0, green = 0, red = 0;
    int gray;

    for (int row = 0; row < h; row++)
    {
        uchar *curr_row = src.ptr<uchar>(row);
        uchar *result_row = result.ptr<uchar>(row);
        for (int col = 0; col < w; col++)
        {
            if (ch == 3)
            {
                blue = *curr_row++;
                green = *curr_row++;
                red = *curr_row++;

                *result_row++ = blue;
                *result_row++ = green;
                *result_row++ = red;
            }
            else if (ch == 1)
            {
                gray = *curr_row++;
                *result_row++ = gray;
            }
        }
    }

    imshow("result", result);

    cv::waitKey(0);

    return 0;
}