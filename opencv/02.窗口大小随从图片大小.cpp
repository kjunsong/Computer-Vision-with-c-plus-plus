//
#include "stdafx.h"
#include<opencv2\opencv.hpp>

int main()
{
	IplImage* image = cvLoadImage("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg");
	cvNamedWindow("win", CV_WINDOW_AUTOSIZE); 
		//设置为0（默认值）时窗口的大小不会因图像的大小而改变
		//设置CV_WINDOW_AUTOSIZE时，窗口会根据图像的实际大小自动进行拉伸或缩放。
	cvShowImage("win", image);
	cvWaitKey(0);

	cvReleaseImage(&image);
	cvDestroyWindow("win");
	return 0;
}


