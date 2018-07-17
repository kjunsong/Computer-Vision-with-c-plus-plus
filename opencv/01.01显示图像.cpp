#include "stdafx.h"
#include <iostream>			    //输入输出头文件
#include <opencv2/core.hpp>	    //数据结构头文件
#include <opencv2/highgui.hpp>  //图形结构头文件


int main()
{
	cv::Mat image;				//创建一个空图像

	std::cout << "This image is " << image.rows << " * " << image.cols << std::endl;
	image = cv::imread("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg"); //读取输入图片
	std::cout << "This image has " << image.channels() << " channel(s)";          //用channels的方法检测通道数
	if (image.empty())			//错误处理
	{
		//未分配图像数据，empty方法返回true
	}
	cv::namedWindow("Original Image");	 //创建窗口
	cv::imshow("Original Image", image); //显示图像
	cv::waitKey(0);

	return 0;
}