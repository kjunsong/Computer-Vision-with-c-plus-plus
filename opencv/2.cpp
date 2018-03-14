//
#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"

int main()
{
	IplImage* image = cvLoadImage("D:\\Documents\\Pictures\\s1.jpg");
	cvNamedWindow("window", CV_WINDOW_AUTOSIZE);
	cvShowImage("window",image);
	cvWaitKey(0);

	cvReleaseImage(&image);
	cvDestroyWindow("window");

	return 0;
}

