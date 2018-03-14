//
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"

int slider_position = 0;

void on_changed(int pos)
{
	printf("slider_position is %d\n", slider_position);
}

int main()
{
	cvNamedWindow("show_avi");   //��������
	//CvCapture* capture = cvCreateFileCapture("F:\\BaiduYunDownload\\arm����\\03 - ARM׼����������Ϥ������3.avi");
	//CvCapture* capture = cvCreateCameraCapture(-1); //������ͷ
	
	cvCreateTrackbar(
			"Position",        //����������
			"show_avi",		   //��������	
			&slider_position,  //��ǰ����������λ��
			400,               //�ܳ���
			on_changed         //�����������ͻ�ִ�д˺���
			);
	
	cvShowImage("show_avi",NULL);
	cvWaitKey(0);

	return 0;
}

