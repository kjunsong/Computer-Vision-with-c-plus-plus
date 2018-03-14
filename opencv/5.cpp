//
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"

int slider_position = 0;

void on_changed(int pos)
{
	printf("slider_position is %d\n", slider_position);
}

int main()
{
	cvNamedWindow("show_avi");   //创建窗口
	//CvCapture* capture = cvCreateFileCapture("F:\\BaiduYunDownload\\arm开发\\03 - ARM准备工作及熟悉开发板3.avi");
	//CvCapture* capture = cvCreateCameraCapture(-1); //读摄像头
	
	cvCreateTrackbar(
			"Position",        //滚动条名字
			"show_avi",		   //窗口名字	
			&slider_position,  //当前滚动条所在位置
			400,               //总长度
			on_changed         //拉动进度条就会执行此函数
			);
	
	cvShowImage("show_avi",NULL);
	cvWaitKey(0);

	return 0;
}

