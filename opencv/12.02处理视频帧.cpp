#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>

void canny(cv::Mat& image, cv::Mat& out);

int main()
{
	cv::VideoCapture capture("C:/Users/俊松/Documents/我的工作区/工程代码/cat.mp4");
	if (!capture.isOpened())
		return 1;

	long t = static_cast<long>(capture.get(cv::CAP_PROP_FRAME_COUNT)); //获得视频文件的总帧数
	double rate = capture.get(cv::CAP_PROP_FPS); //property:所有权
	bool stop(false);

	cv::Mat frame;				//当前视频帧
	cv::Mat out;
	cv::namedWindow("Extracted Frame");
	cv::namedWindow("Out Frame");
	int delay = 500 / rate;	//根据帧速率计算帧之间等待时间，单位为ms
							//循环遍历视频中的全部帧
	while (!stop)				//读取下一帧
	{
		if (!capture.read(frame))
			break;

		canny(frame, out);
		cv::imshow("Extracted Frame", frame);
		cv::imshow("Out Frame", out);
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

void canny(cv::Mat& img, cv::Mat& out)
{
	if (img.channels() == 3)		//转换为灰度图像
		cv::cvtColor(img, out, cv::COLOR_BGR2GRAY);
	cv::Canny(out, out, 100, 200);  //计算Canny边缘
	cv::threshold(out, out, 128, 255, cv::THRESH_BINARY_INV); //翻转图片
	//128:"lower"threshold
	//255:"upper"threshold
}
