//RGB中亮度——灰度值
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include "cxcore.h"

int main()
{
	IplImage* src = cvLoadImage("D:\\Documents\\Pictures\\psb.jpg");

	IplImage* dst = cvCreateImage(cvSize(255, 255), 8, 3);

	for (int y = dst->height - 1; y > 0; y--)
	{
		cvSet2D(dst, y, dst->height - y, cvScalar(255-y, 255-y, 0));
	}

	cvNamedWindow("dst");
	cvShowImage("dst",dst);
	
	cvNamedWindow("一维");
	cvShowImage("一维", src);
	cvWaitKey(0);
	
	return 0;
}

