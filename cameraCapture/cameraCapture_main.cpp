#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	VideoCapture capture(0);	//从摄像头读入视频
	/*VideoCapture capture;
	capture.open(0)*/

	Mat edges;  //提取边缘图像

	//循环显示每一帧
	while (true)
	{
		Mat frame;
		capture >> frame;	//读入图像

		cvtColor(frame, edges, COLOR_BGR2GRAY);	//BGR彩色图转换为灰度图

		//均值滤波，3X3内核
		blur(edges, edges, Size(7, 7));

		//Canny边缘提取
		Canny(edges, edges, 0, 40, 3);
		
		//图像显示
		imshow("camera original", frame);
		imshow("camera canny", edges);
		if (waitKey(30) > 0)
		{
			break;
		}
	}

	return 0;
}