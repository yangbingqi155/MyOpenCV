#include "stdafx.h"
/*  For description look into the help() function. */
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

void main()
{
	/*Print Format*/
	Point2f P(5,1);
	cout << "Point (2D) = " << P << endl << endl;

	Point3f P3f(2,3,1);
	cout << "Point (3D) = " << P3f << endl << endl; 

	vector<float> v;
	v.push_back((float)CV_PI);
	v.push_back(2);
	v.push_back(3.01f);
	cout << "Vector of floats via Mat =" << Mat(v) << endl << endl;

	
	Mat I,J;
	int divideWith=10;
	cout << "Start Read:" << endl;
	I=cv::imread("C:\\Users\\ybq_000\\Desktop\\iphone5.jpg",IMREAD_COLOR);
	uchar table[256];
	for(int i=0;i<256;++i)
	{
		table[i]=divideWith*(i/divideWith);
	}
	cout << "End Read:" << endl;
	cout << "Rows of I:" << I.channels()* I.rows << endl;
	cout << "Cols of I:" << I.cols << endl;
}

//the first method ,C Style
Mat& ScanImageReduceC(Mat& I,const uchar* const table)
{
	CV_Assert(I.depth()==sizeof(uchar));
	int cols=I.channels()*I.rows;
	int rows=I.rows;
	if(I.isContinuous())
	{
		cols*=rows;
		rows=1;
	}
	int i,j;
	uchar* p;
	for(i=0;i++;i<rows){
		p=I.ptr(i);
		for(j=0;j++;j<cols){
			p[j]=table[p[j]];
		}
	}
	return I;
}