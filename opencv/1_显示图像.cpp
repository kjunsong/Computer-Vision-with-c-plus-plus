// project_opencv.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2\opencv.hpp>

int main()
{
	//将图像文件加载至内存，以图像本来颜色加载，指针指向内存块
	IplImage* img = cvLoadImage("C:/Users/俊松/Documents/我的工作区/a.jpg", -1);
	cvNamedWindow("win");      //创建窗口
	cvShowImage("win", img);   //显示图像
	cvWaitKey(0);              //0：等待用户按键输入（停留时间过短，看不清图像）
							   //大于0：停留多少秒
	cvReleaseImage(&img);
	cvDestroyWindow("win");    //后面两语句：释放内存
    return 0;
}

