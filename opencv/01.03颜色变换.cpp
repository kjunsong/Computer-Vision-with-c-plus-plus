#include "stdafx.h"
#include <iostream>			    //输入输出头文件
#include <opencv2/core.hpp>	    //数据结构头文件
#include <opencv2/highgui.hpp>  //图形结构头文件
//using namespace cv;			  //访问cv的一种方式
	
int main()
{
	cv::Mat image;
	cv::Mat result;
	//读取一个图像文件将其转换为灰色图像
	//image = cv::imread("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg", cv::IMREAD_GRAYSCALE);
	//读取一个图像文件将其转换为三通道彩色图像
	image = cv::imread("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg", cv::IMREAD_COLOR);
	cv::namedWindow("Original Image");
	cv::imshow("Original Image", image);
	cv::waitKey(0);

	return 0;
}