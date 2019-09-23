//---------------------------------------------------
// 描述：创建包围轮廓的圆形区域
//---------------------------------------------------
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
    // 初始化变量和随机值
    Mat image(600, 600, CV_8UC3);
    RNG& rng = theRNG();

    for(;;)
    {
        int count = rng.uniform(3, 103);
        vector<Point> points;

        // 随机生成点坐标
        for(int i = 0; i < count; i++)
        {
            Point point;
            point.x = rng.uniform(image.cols/4, image.cols*3/4);
            point.y = rng.uniform(image.rows/4, image.rows*3/4);

            points.push_back(point);
        }

        // 对给定的 2D 点集，寻找最小面积的包围圆
        Point2f center;
        float radius = 0;
        minEnclosingCircle(Mat(points), center, radius);

        //绘制出随机颜色的点
		image = Scalar::all(0);
		for( int i = 0; i < count; i++ )
			circle( image, points[i], 3, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), FILLED, LINE_AA );


		//绘制出最小面积的包围圆
		circle(image, center, cvRound(radius), Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 2, LINE_AA);

		//显示窗口
		imshow( "圆形包围示例", image );

		//按下ESC,Q,或者q，程序退出
		char key = (char)waitKey();
		if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
			break;
    }

    return 0;
}