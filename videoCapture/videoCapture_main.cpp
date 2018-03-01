#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	VideoCapture capture("..\\..\\ROBOTIS Manipulator H.mp4");	//读入视频
	//VideoCapture capture("../../ROBOTIS Manipulator H.mp4");	//读入视频

	//逐帧读取，并播放
	while (1)
	{
		Mat frame;
		capture >> frame;	//读取当前帧

		//判断是否播放完毕
		if (frame.empty())
		{
			break;
		}

		imshow("Video", frame);	//显示当前帧
		waitKey(30);
	}

	return 0;
}