#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void kmeans(Mat &src);
void rgb2hsv(float r, float g, float b, float &h, float &s, float &v);
float MAX3(float r, float g, float b);
float MIN3(float r, float g, float b);

int main(int argc, char **argv)
{

    String images_path = "./yellow/*.jpg";
    vector<String> images_list;
    glob(images_path, images_list);

    for (int i = 0; i < images_list.size(); ++i)
    {
        String image_name = images_list[i];
        Mat src = imread(image_name);

        if (src.empty())
        {
            printf("could not load image...\n");
            return -1;
        }

        cout << image_name << endl;
        kmeans(src);
    }
#if 0
    waitKey(0);
#endif
    return 0;
}

void kmeans(Mat &src)
{
#if 0
    namedWindow("input image", WINDOW_AUTOSIZE);
    imshow("input image", src);
#endif

    int width = src.cols;
    int height = src.rows;
    int dims = src.channels();

    // 初始化参数
    int sampleCount = width * height;
    int clusterCount = 3;
    Mat labels;
    Mat centers;

    // RGB 数据转换到样本数据
    Mat sample_data = src.reshape(3, sampleCount);
    Mat data;
    sample_data.convertTo(data, CV_32F);

    // 运行K-Means
    TermCriteria criteria = TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1);
    kmeans(data, clusterCount, labels, criteria, clusterCount, KMEANS_PP_CENTERS, centers);
    Mat card = Mat::zeros(Size(width, 50), CV_8UC3);
    vector<float> clusters(clusterCount);

    // 生成色卡比率
    for (int i = 0; i < labels.rows; i++)
    {
        clusters[labels.at<int>(i, 0)]++;
    }
    for (int i = 0; i < clusters.size(); i++)
    {
        clusters[i] = clusters[i] / sampleCount;
    }
    int x_offset = 0;

    // 绘制色卡
    for (int x = 0; x < clusterCount; x++)
    {
        Rect rect;
        rect.x = x_offset;
        rect.y = 0;
        rect.height = 50;
        rect.width = round(clusters[x] * width);
        x_offset += rect.width;
        float b = centers.at<float>(x, 0);
        float g = centers.at<float>(x, 1);
        float r = centers.at<float>(x, 2);
        rectangle(card, rect, Scalar(b, g, r), -1, 8, 0);

        float h = 0, s = 0, v = 0;
        // cout << "r = " << r << " g = " << g << " b = " << b << endl;
        rgb2hsv(r, g, b, h, s, v);
        cout << "r = " << r << " g = " << g << " b = " << b << endl;
        cout << "h = " << h << " s = " << s << " v = " << v << endl;
        if (h >= 100 && h <= 124 && s >= 43 && s <= 255 && v >= 46 && v <= 255)
        {
            cout << "blue" << endl;
        }
        else if((h >= 26 && h <= 34 && s >= 43 && s <= 255 && v >= 46 && v <= 255))
        {
            cout << "yellow" << endl;
        }
        else
        {
            cout << "not blue" << endl;
        }
    }
#if 0
    imshow("Image Color Card", card);
#endif
}

void rgb2hsv(float r, float g, float b, float &h, float &s, float &v)
{
    r = r/255.0;
    g = g/255.0;
    b = b/255.0;

    float max_val = MAX3(r, g, b);
    float min_val = MIN3(r, g, b);
    float diff = max_val - min_val;

    // 计算H
    if (max_val == min_val)
    {
        h = 0;
    }else if (max_val == r)
    {
        if (g >= b)
            h = 60 * ((g - b) / diff) + 0;
        else
            h = 60 * ((g - b) / diff) + 360;
    }else if (max_val == g)
    {
        h = 60 * ((b - r) / diff) + 120;
    }
    else if (max_val == b)
    {
        h = 60 * ((r - g) / diff) + 240;
    }

    if (max_val == 0)
    {
        s = 0;
    }
    else
    {
        s = (diff / max_val);
    }

    v = max_val;

    h = h/2;
    s = s*255.0;
    v = v*255.0;
}

float MAX3(float r, float g, float b)
{
    int bigger = r > g ? r : g;
    return bigger > b ? bigger : b;
}

float MIN3(float r, float g, float b)
{
    int smaller = r < g ? r : g;
    return smaller < b ? smaller : b;
}