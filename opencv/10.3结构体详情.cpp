#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include"cxcore.h"

int main()
{
	IplImage* img;
	img = cvLoadImage("D:\\Documents\\Pictures\\psb.jpg");
	IplImage* sub_img = cvLoadImage("D:\\Documents\\Pictures\\�����.jpg");


	//ע�͵Ĵ��룺Ϊ���ú���ʵ�ֵģ�Ҳ�����Լ�д����ʵ��
	CvRect rect;
	rect.x = 107;
	rect.y = 13;
	rect.width = sub_img->width;
	rect.height = sub_img->height;

	for (int y = 0; y < sub_img->height; y++)
	{
		unsigned char* subImgData = (unsigned char*)(sub_img->imageData + y*sub_img->widthStep);
		unsigned char* bigImgData = (unsigned char*)(img->imageData + (y + rect.y)*img->widthStep);
		for (int x = 0; x < sub_img->width; x++)
		{
			bigImgData[3 * (x + rect.x) + 0] = subImgData[3 * x + 0];
			bigImgData[3 * (x + rect.x) + 1] = subImgData[3 * x + 1];
			bigImgData[3 * (x + rect.x) + 2] = subImgData[3 * x + 2];
		}
	}
	cvNamedWindow("sub");
	cvShowImage("sub", img);
	cvWaitKey(0);
	/*
	CvRect rect;  //һ����������
	rect.x = 107;
	rect.y = 13;
	rect.width = sub_img->width;
	rect.height = sub_img->height;

	cvSetImageROI(img, rect);
	//cvResetImageROI(img);  //ȡ��ѡ��ROI����

	cvCopy(sub_img, img);   //sub_img������imgͼ����
	cvResetImageROI(img);

	cvNamedWindow("sub");
	cvShowImage("sub", sub_img);

	cvNamedWindow("ROI");
	cvShowImage("ROI", img);
	cvWaitKey(0);*/

	
	return 0;
}

