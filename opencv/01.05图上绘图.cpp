#include "stdafx.h"
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image;
	image = cv::imread("C:/Users/俊松/Documents/我的工作区/科技改变生活/1.jpg");
	cv::circle(image, cv::Point(100,100), 78, 0, 3);  //88:半径 0:颜色(这里是黑色) 3:厚度
	cv::putText(image, "This is a woman", cv::Point(5, 40), 
				cv::FONT_HERSHEY_PLAIN,	//字体类型		
				1.5,					//字体大小	
				255,					//字体颜色
				2);						//字体厚度

	cv::namedWindow("IMAGE");
	cv::imshow("IMAGE", image);
	cv::waitKey(0);

    return 0;
}