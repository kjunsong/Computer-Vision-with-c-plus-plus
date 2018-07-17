#include "stdafx.h"
#include <iostream>			    //输入输出头文件
#include <opencv2/core.hpp>	    //数据结构头文件
#include <opencv2/highgui.hpp>  //图形结构头文件
#include<opencv2/opencv.hpp>    //cv::circle的头文件
//using namespace cv;			  //访问cv的一种方式
	
//回调函数 event:表示触发回调函数的鼠标事件类型  flags：表示事件发生时按下鼠标哪个键

void onMouse(int event, int x, int y, int flags, void*param);

int main()
{
	cv::Mat image;
	image = cv::imread("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg");
	cv::namedWindow("Original Image");
	//onMouse与窗口建立关联，同时把所显示的地址作为附加参数传给函数
	cv::setMouseCallback("Original Image", onMouse, reinterpret_cast<void *>(&image));

	cv::imshow("Original Image", image);
	cv::waitKey(0);
	return 0;
}

void onMouse(int event, int x, int y, int flags, void *param)
{
	cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
	
	switch (event)					//调度事件
	{
	case cv::EVENT_LBUTTONDOWN: //鼠标左键按下事件
		//显示像素
		std::cout << "at(" << x << "," << y << ") value is: " << static_cast<int>(im->at<uchar>(cv::Point(x, y))) << std::endl;
		break;
	}
}