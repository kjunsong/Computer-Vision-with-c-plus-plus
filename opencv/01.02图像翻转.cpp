#include "stdafx.h"
#include <iostream>			    //输入输出头文件
#include <opencv2/core.hpp>	    //数据结构头文件
#include <opencv2/highgui.hpp>  //图形结构头文件

int main()
{
	cv::Mat image;
	cv::Mat result;
	image = cv::imread("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg");
	cv::flip(image, result, 0);	//正数：水平、0：垂直、负数：水平和垂直
	cv::namedWindow("Original Image");
	cv::namedWindow("Result");
	cv::imshow("Original Image", image);
	cv::imshow("Result", result);
	cv::waitKey(0);

	return 0;
}
