#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>

int main()
{
	//打开视频文件
	cv::VideoCapture capture("C:/Users/俊松/Documents/我的工作区/工程代码/cat.mp4");
	//检查视频是否成功打开
	if (!capture.isOpened())
		return 1;

	long t = static_cast<long>(capture.get(cv::CAP_PROP_FRAME_COUNT)); //获得视频文件的总帧数
	//printf("%ld\n",t);
	//double position = 100.0;	//跳转到第100帧					
	//capture.set(cv::CAP_PROP_POS_FRAMES, position);

	//取得帧速率
	double rate = capture.get(cv::CAP_PROP_FPS); //property:所有权
	bool stop(false);
	 
	cv::Mat frame;				//当前视频帧
	cv::namedWindow("Extracted Frame");
	int delay = 500 / rate;	//根据帧速率计算帧之间等待时间，单位为ms
								//循环遍历视频中的全部帧
	while (!stop)				//读取下一帧
	{
		if (!capture.read(frame))
			break;
		cv::imshow("Extracted Frame", frame); 
		//等待一段时间，或者通过按键停止
		if (cv::waitKey(delay) >= 0)
		{
			stop = true;
		}
	}
	//关闭视频
	//不是必须的，因为在cv::VideoCapture的析构函数会调用
	capture.release(); 
	return 0;
}