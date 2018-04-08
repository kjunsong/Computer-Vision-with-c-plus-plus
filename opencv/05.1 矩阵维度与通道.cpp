#include "stdafx.h"
#include <opencv2\opencv.hpp>

int main()
{
	float data[18] =
	{30,60,40,60,50,40,
	 67,88,23,23,45,56,
	 65,68,96,34,24,42
	};
	CvMat mat;
	cvInitMatHeader(&mat,3,6,CV_32FC1,data); //CV_32FC1£ºµ¥Í¨µÀ
	for (int y = 0; y < mat.rows; y++)
	{
		for (int x = 0; x < mat.cols; x++)
		{
			float value = cvGetReal2D(&mat,y,x);
			printf("%f ", value);
		}
		printf("\n");
	}
	return 0;
}

/*
30.000000 60.000000 40.000000 60.000000 50.000000 40.000000
67.000000 88.000000 23.000000 23.000000 45.000000 56.000000
65.000000 68.000000 96.000000 34.000000 24.000000 42.000000
请按任意键继续. . .
*/
