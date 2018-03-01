#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	VideoCapture capture(0);	//������ͷ������Ƶ
	/*VideoCapture capture;
	capture.open(0)*/

	Mat edges;  //��ȡ��Եͼ��

	//ѭ����ʾÿһ֡
	while (true)
	{
		Mat frame;
		capture >> frame;	//����ͼ��

		cvtColor(frame, edges, COLOR_BGR2GRAY);	//BGR��ɫͼת��Ϊ�Ҷ�ͼ

		//��ֵ�˲���3X3�ں�
		blur(edges, edges, Size(7, 7));

		//Canny��Ե��ȡ
		Canny(edges, edges, 0, 40, 3);
		
		//ͼ����ʾ
		imshow("camera original", frame);
		imshow("camera canny", edges);
		if (waitKey(30) > 0)
		{
			break;
		}
	}

	return 0;
}