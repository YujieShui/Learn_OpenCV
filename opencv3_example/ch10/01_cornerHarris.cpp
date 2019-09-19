//------------------------------------------------------
// 描述：cornerHarris函数用法示例
//------------------------------------------------------

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
    Mat srcImage = imread("images/1.jpg", IMREAD_GRAYSCALE);
    imshow("原始图", srcImage);

    //进行Harris角点检测找出角点
    Mat cornerStrength;
    cornerHarris(srcImage, cornerStrength, 2, 3, 0.01);

	//对灰度图进行阈值操作，得到二值图并显示  
	Mat harrisCorner;  
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);  
	imshow("角点检测后的二值效果图", harrisCorner);  

	waitKey(0);  
	return 0;  
}