#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"

int main()
{
	IplImage* img;
	img = cvLoadImage("D:\\Documents\\Pictures\\psb.jpg");
	//printf("nChannels is %d ", img -> nChannels); //三通道
	IplImage* b_img, *g_img, *r_img;

	b_img = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);//三通道分解成三个单个通道
	g_img = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	r_img = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);

	
	int y, x;
	for (y = 0; y < img->height; y++)
	{
		unsigned char* prow = (unsigned char*)(img->imageData + y * img->widthStep); //起始字节数+偏移字节

		unsigned char* brow = (unsigned char*)(b_img->imageData + y * b_img->widthStep);//指向B通道的第y行
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
	cvShowImage("r", r_img); //只表示取值大小，输出图像并不是红色

	cvWaitKey(0);
	
	return 0;
}

