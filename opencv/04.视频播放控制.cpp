//视频播放控制
#include "stdafx.h"
#include<opencv2\opencv.hpp> 

CvCapture* capture = NULL;
int slider_position = 0;

int frame_count = 0;

void onTrackbarSlider(int pos)
{
	cvSetCaptureProperty(
		capture,
		CV_CAP_PROP_POS_FRAMES,
		pos
		);

	frame_count = pos;
}

int main()
{
	cvNamedWindow("show_avi");   //创建窗口
	capture = cvCreateFileCapture("C:/Users/俊松/Documents/baidudownload/day01视频/3_视频/01_为什么学习QT.mp4");
	
	//获取总帧数
	int frames = (int)cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FRAME_COUNT
		);

	if (frames > 0)  //设置滚动条
	{ 
		cvCreateTrackbar(
				"Position",        //滚动条名字
				"show_avi",		   //窗口名字	
				&slider_position,  //当前滚动条所在位置
				frames,            //总长度
				onTrackbarSlider   //拉动进度条就会执行此函数
				);
	}

	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
		{
			break;
		}

		cvShowImage("show_avi",frame);
		char c = cvWaitKey(33);

		if (c == 27)
		{
			break;
		}
		cvSetTrackbarPos("Position", "show_avi", frame_count);
		frame_count++;
	}
	cvShowImage("show_avi",NULL);
	cvWaitKey(0);

	return 0;
}

