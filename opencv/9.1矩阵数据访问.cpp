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
	cvInitMatHeader(&mat, 3, 3, CV_32FC2, data);

	int y = 2, x = 3;
	int nChannels = 2;
	for (y = 0; y < mat.rows; y++)
	{
		float* p_float = (float*)(mat.data.ptr + y * mat.step);//!!!
		for (x = 0; x < mat.cols; x++)
		{
			float value[2];
				value[0] = *(p_float + x * nChannels);
				value[1] = *(p_float + x * nChannels + 1);
			printf(" (%f %f) ", value[0], value[1]);
		}
		printf("\n");
	}

	return 0;
}

