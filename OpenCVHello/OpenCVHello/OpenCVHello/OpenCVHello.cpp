#include "stdafx.h"
/*  For description look into the help() function. */
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;


void Sharpen(const Mat& myImage,Mat& Result);

void main()
{

	/*Print Format*/
	//Point2f P(5,1);
	//cout << "Point (2D) = " << P << endl << endl;

	//Point3f P3f(2,3,1);
	//cout << "Point (3D) = " << P3f << endl << endl; 

	//vector<float> v;
	//v.push_back((float)CV_PI);
	//v.push_back(2);
	//v.push_back(3.01f);
	//cout << "Vector of floats via Mat =" << Mat(v) << endl << endl;



	

	//Mat I,J,K;
	//int divideWith=10;
	//cout << "Start Read:" << endl;
	//I=cv::imread("C:\\Users\\ybq_000\\Desktop\\test.jpg",IMREAD_COLOR);
	//uchar table[256];
	//for(int i=0;i<256;++i)
	//{
	//	table[i]=divideWith*(i/divideWith);
	//}
	//
	//Mat kern = (Mat_<char>(3,3) <<  0, -1,  0, 
 //                                  -1,  5, -1,
 //                                   0, -1,  0);
	//cv::filter2D(I,K,I.depth(),kern);
	////imshow("Output", K);

	//Sharpen(I,J);
	//imshow("Output", J);
	//	char* u;
	//cin>>u;
	



}

void Sharpen(const Mat& myImage,Mat& result)
{
	CV_Assert(myImage.depth()==CV_8U);
	result.create(myImage.size(),myImage.type());
	const int nChannels=myImage.channels();
	int i,j;
	for(i=1;i<myImage.rows-1;i++)
	{
		const uchar* previous=myImage.ptr<uchar>(i-1);
		const uchar* current=myImage.ptr<uchar>(i);
		const uchar* next=myImage.ptr<uchar>(i+1);

		uchar* output=result.ptr<uchar>(i);
		for(j=nChannels;j<nChannels*(myImage.cols-1);j++)
		{
			*output ++=saturate_cast<uchar>(current[j]*5-current[j-nChannels]-current[j+nChannels]-previous[j]-next[j]);
		}

	}
	result.row(0).setTo(Scalar(0));
	result.row(myImage.rows-1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(myImage.cols-1).setTo(Scalar(0));
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