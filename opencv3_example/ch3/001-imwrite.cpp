//---------------------------------------------------------------
//              描述：使用 imwrite() 保存一张图片
//---------------------------------------------------------------

#include <opencv2/opencv.hpp>
#include <vector>

void create(cv::Mat &mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {

            cv::Vec4b &rgba = mat.at<cv::Vec4b>(i, j);
            rgba[0] = UCHAR_MAX;
            rgba[1] = cv::saturate_cast<uchar>((float(mat.cols - j)) /
                                               ((float)mat.cols) * UCHAR_MAX);
            rgba[2] = cv::saturate_cast<uchar>((float(mat.rows - j)) /
                                               ((float)mat.rows) * UCHAR_MAX);
            rgba[3] = cv::saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
        }
    }
}

int main()
{
    // 创建带有 Alpha 通道的 Mat
    cv::Mat mat(480, 640, CV_8UC4);
    create(mat);

    std::vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    try
    {
        cv::imwrite("images/透明 Alpha 值图.png", mat, compression_params);
        cv::imshow("生成的 PNG 图", mat);

        fprintf(stdout, "PNG 图片保存的 alpha 数据保存完毕 \n 可以在 images 文件夹下查看由 imwrite() 生成的图片 \n");
        cv::waitKey(0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}