#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 方法一：构造函数
    Mat M(3, 2, CV_8UC3, Scalar(0, 0, 255));
    cout << "M = " << endl << " " << M << endl;    

    // 方法二: create() 函数
    M.create(2,6, CV_8UC2);//释放内存重新创建图像
    cout << "M = " << endl << " " << M << endl;        

    // 方法三：Matlab 风格
    Mat Z = Mat::zeros(2,3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl;
    
    Mat O = Mat::ones(2, 3, CV_32F);
    cout << "O = " << endl << " " << O << endl;
    
    Mat E = Mat::eye(2, 3, CV_64F);
    cout << "E = " << endl << " " << E << endl;

    // 方法四: 都好分隔形式
    Mat C = (Mat_<double>(3, 3) << 0, 1, 3, 4, 5, 5, 1, 3, 4);
    cout << "C = " << endl << " " << C << endl;

    // 方法五: 为已存在的对象创建新的信息头
    Mat RowClone = C.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl;


    return 0;
}