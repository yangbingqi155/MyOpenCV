#include "stdafx.h"
/*  For description look into the help() function. */
#include "opencv2/core/core.hpp"
#include <iostream>

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



}