#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	VideoCapture capture("..\\..\\ROBOTIS Manipulator H.mp4");	//������Ƶ
	//VideoCapture capture("../../ROBOTIS Manipulator H.mp4");	//������Ƶ

	//��֡��ȡ��������
	while (1)
	{
		Mat frame;
		capture >> frame;	//��ȡ��ǰ֡

		//�ж��Ƿ񲥷����
		if (frame.empty())
		{
			break;
		}

		imshow("Video", frame);	//��ʾ��ǰ֡
		waitKey(30);
	}

	return 0;
}