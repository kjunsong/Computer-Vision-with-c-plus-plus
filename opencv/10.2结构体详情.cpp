#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include"cxcore.h"

int main()
{
	IplImage* img;
	img = cvLoadImage("D:\\Documents\\Pictures\\psb.jpg");
	
	CvRect rect;  //一个矩形区域
	rect.x = 107;
	rect.y = 13;
	rect.width = 160;
	rect.height = 140;

	cvSetImageROI(img, rect);
	//cvResetImageROI(img);  //取消选中ROI区域

	cvNamedWindow("ROI");
	cvShowImage("ROI", img);
	cvWaitKey(0);

	
	return 0;
}

