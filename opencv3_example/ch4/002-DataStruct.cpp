#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Point point1 = Point(10, 8);

    Point point2;
    point2.x = 8;
    point2.y = 10;

    cout << point1 << endl;
    cout << point2 << endl;


    Size size = Size(10, 10);

    return 0;
}