#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"

int main()
{
	IplImage* img;
	img = cvLoadImage("D:\\Documents\\Pictures\\psb.jpg");
	//printf("nChannels is %d ", img -> nChannels); //��ͨ��
	IplImage* b_img, *g_img, *r_img;

	b_img = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);//��ͨ���ֽ����������ͨ��
	g_img = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	r_img = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

	
	int y, x;
	for (y = 0; y < img->height; y++)
	{
		unsigned char* prow = (unsigned char*)(img->imageData + y * img->widthStep); //��ʼ�ֽ���+ƫ���ֽ�

		unsigned char* brow = (unsigned char*)(b_img->imageData + y * b_img->widthStep);//ָ��Bͨ���ĵ�y��
		unsigned char* grow = (unsigned char*)(g_img->imageData + y * g_img->widthStep);
		unsigned char* rrow = (unsigned char*)(r_img->imageData + y * r_img->widthStep);

		for (x = 0; x < img->width; x++)
		{
			brow[x] = prow[3 * x + 0];
			grow[x] = prow[3 * x + 1];
			rrow[x] = prow[3 * x + 2];
		}
	}

	cvNamedWindow("1");
	cvShowImage("1", img);

	cvNamedWindow("b");
	cvNamedWindow("g");
	cvNamedWindow("r");

	cvShowImage("b", b_img);
	cvShowImage("g", g_img);
	cvShowImage("r", r_img); //ֻ��ʾȡֵ��С�����ͼ�񲢲��Ǻ�ɫ

	cvWaitKey(0);
	
	return 0;
}

