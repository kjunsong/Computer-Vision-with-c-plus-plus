//
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include "cxcore.h"

int main()
{
	cvNamedWindow("avi");   //��������
	CvCapture* capture = cvCreateFileCapture("F:\\BaiduYunDownload\\arm����\\03 - ARM׼����������Ϥ������3.avi");
	//CvCapture* capture = cvCreateCameraCapture(-1); //������ͷ
	IplImage* frame;

	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame) break;

		cvShowImage("avi",frame);
		char c = cvWaitKey(33);  //����֡�� 33���벥��һ֡ 
		if (c == 27)			 //����esc��
			break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("avi");
	return 0;
}

