//��Ƶ���ſ���
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"

CvCapture* capture = NULL;
int slider_position = 0;

int frame_count = 0;

void onTrackbarSlider(int pos)
{
	cvSetCaptureProperty(
		capture,
		CV_CAP_PROP_POS_FRAMES,
		pos
		);

	frame_count = pos;
}

int main()
{
	cvNamedWindow("show_avi");   //��������
	capture = cvCreateFileCapture("F:\\BaiduYunDownload\\arm����\\03 - ARM׼����������Ϥ������3.avi");
	
	//��ȡ��֡��
	int frames = (int)cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FRAME_COUNT
		);

	if (frames > 0)  //���ù�����
	{ 
		cvCreateTrackbar(
				"Position",        //����������
				"show_avi",		   //��������	
				&slider_position,  //��ǰ����������λ��
				frames,            //�ܳ���
				onTrackbarSlider   //�����������ͻ�ִ�д˺���
				);
	}

	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
		{
			break;
		}

		cvShowImage("show_avi",frame);
		char c = cvWaitKey(33);

		if (c == 27)
		{
			break;
		}
		cvSetTrackbarPos("Position", "show_avi", frame_count);
		frame_count++;
	}
	cvShowImage("show_avi",NULL);
	cvWaitKey(0);

	return 0;
}

