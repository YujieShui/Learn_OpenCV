//---------------------------------------------------
// 描述：图像边缘检测
//
// 使用 Canny 实现
//---------------------------------------------------
 
 #include <opencv2/highgui/highgui.hpp>
 #include <opencv2/imgproc/imgproc.hpp>

/**
 * Canny 进行边缘检测的步骤：
 * 1. 读入图像 src
 * 2. 创建与 src 同类型大小的矩阵 dst
 * 3. 彩色图像转成灰度图像 
 * 4. 图像降噪， 用 blur
 * 5. 使用 Canny 算子
 * 6. 显示图片
 **/
 int main()
 {
    cv::Mat src = cv::imread("images/3.jpg", cv::IMREAD_COLOR);
    cv::Mat dst, gray, edge;

    dst.create(src.size(), src.type());
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::blur(gray, edge, cv::Size(7, 7));
    cv::Canny(edge, edge, 3, 9, 3);

    cv::imshow("src", src);
    cv::imshow("gray", gray);
    cv::imshow("边缘检测结果", edge);

    cv::waitKey(0);

     return 0;
 }