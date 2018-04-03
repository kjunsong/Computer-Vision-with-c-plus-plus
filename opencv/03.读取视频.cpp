//
#include "stdafx.h"
#include<opencv2\opencv.hpp>

int main()
{
	cvNamedWindow("avi");   //创建窗口
	CvCapture* capture = cvCreateFileCapture("F:\\BaiduYunDownload\\arm开发\\03 - ARM准备工作及熟悉开发板3.avi");
	//CvCapture* capture = cvCreateCameraCapture(-1); //读摄像头
	IplImage* frame;

	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame) break;

		cvShowImage("avi",frame);
		char c = cvWaitKey(33);  //播放帧率 33毫秒播放一帧 
		if (c == 27)			 //按下esc键
			break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("avi");
	return 0;
}

