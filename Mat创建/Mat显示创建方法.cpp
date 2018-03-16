//��ʾ����Mat��������ַ���
//����ֻѡȡ�˸о��Ƚ�ʵ�õļ���
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//ʹ��Mat()���캯��
	Mat m(3, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M=" << endl << m << endl << endl;	//Mat�����<<ֻ�Զ�ά������Ч

	//Ϊ�Ѵ��ڵ�IplImageָ�봴����Ϣͷ
	IplImage *img = cvLoadImage("../../test.jpg");
	Mat mtx = cvarrToMat(img);	//IplImageתΪMat
	imshow("image show", mtx);
	waitKey(1000);

	//����Create()���������г�ʼ�������ǲ���Ϊ���󸳳�ʼֵ
	Mat m2;
	m2.create(4, 4, CV_8UC1);
	randu(m2, Scalar::all(0), Scalar::all(255));   //�����ֵ
	cout << "M2=" << endl << m2 << endl << endl;

	//����Matlabʽ��ʼ����ʽ������������󣬽���������ֳ�ʼ����ʽ
	//zeros(),ones(),eye()
	Mat E = Mat::eye(4, 4, CV_64FC1);
	cout << "E=" << endl << E << endl << endl;

	//����С�����ʹ�ö��ŷָ�ʽ��ʼ������
	Mat C = (Mat_<double>(3, 3) << 0, -1, -2, -3, 5, 1, 2, 3, 6);
	cout << "C=" << endl << C << endl << endl;

	//�������о���row(),col()
	Mat RowClone = C.row(1).clone();
	cout << "RowClone=" << endl << RowClone << endl << endl;

	//����Ԫ�ط���
	cout << "C(1,2)= " << C.at<double>(1, 2) << endl << endl;

	return 0;
}