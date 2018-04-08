//Ð´ÈëaviÎÄ¼þ
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include"cxcore.h"
#include <stdlib.h>
#include <stdio.h>

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

