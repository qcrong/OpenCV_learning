//显示创建Mat对象的七种方法
//这里只选取了感觉比较实用的几种
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//使用Mat()构造函数
	Mat m(3, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M=" << endl << m << endl << endl;	//Mat运算符<<只对二维矩阵有效

	//为已存在的IplImage指针创建信息头
	IplImage *img = cvLoadImage("../../test.jpg");
	Mat mtx = cvarrToMat(img);	//IplImage转为Mat
	imshow("image show", mtx);
	waitKey(1000);

	//利用Create()函数，进行初始化，但是不能为矩阵赋初始值
	Mat m2;
	m2.create(4, 4, CV_8UC1);
	randu(m2, Scalar::all(0), Scalar::all(255));   //随机赋值
	cout << "M2=" << endl << m2 << endl << endl;

	//采用Matlab式初始化方式，对于运算矩阵，建议采用这种初始化方式
	//zeros(),ones(),eye()
	Mat E = Mat::eye(4, 4, CV_64FC1);
	cout << "E=" << endl << E << endl << endl;

	//对于小矩阵可使用逗号分隔式初始化函数
	Mat C = (Mat_<double>(3, 3) << 0, -1, -2, -3, 5, 1, 2, 3, 6);
	cout << "C=" << endl << C << endl << endl;

	//拷贝已有矩阵row(),col()
	Mat RowClone = C.row(1).clone();
	cout << "RowClone=" << endl << RowClone << endl << endl;

	//矩阵按元素访问
	cout << "C(1,2)= " << C.at<double>(1, 2) << endl << endl;

	return 0;
}