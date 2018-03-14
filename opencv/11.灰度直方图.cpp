//����һάֱ��ͼ 
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include "cxcore.h"

IplImage* DrawHist(CvHistogram* hist, float scalex = 1, float scaley = 1)
{
	float histMax = 0;
	cvGetMinMaxHistValue(hist , 0, &histMax, 0);//���ֱ��ͼ���ֵ

	IplImage* imgHist = cvCreateImage(cvSize(256*scalex, 64*scaley), 8 , 1);
	cvZero(imgHist);

	for (int i = 0; i < 255; i++)
	{
		float histValue = cvQueryHistValue_1D(hist, i); //1D:1ά ��ȡbinֵ
		float nextValue = cvQueryHistValue_1D(hist, i+1);

		CvPoint pt1 = cvPoint(    i * scalex, 64 * scaley);
		CvPoint pt2 = cvPoint((i + 1)*scalex, 64 * scaley);
		CvPoint pt3 = cvPoint((i + 1)*scalex, 64 * scaley - (nextValue / histMax) * 64 * scaley);
		CvPoint pt4 = cvPoint(      i*scalex, 64 * scaley - (histValue / histMax) * 64 * scaley);

		//������亯���������
		int numPts = 5;
		CvPoint pts[5];
		pts[0] = pt1;
		pts[1] = pt2;
		pts[2] = pt3;
		pts[3] = pt4;
		pts[4] = pt1;

		cvFillConvexPoly(imgHist, pts, numPts, cvScalar(255)); //���������������

	}
	return imgHist;
}
int main()
{
	IplImage* src = cvLoadImage("D:\\Documents\\Pictures\\�����.jpg");

	
	cvNamedWindow("һά");
	cvShowImage("һά", src);

	int dims = 1;
	int size = 256;
	float range[] = {0, 255};
	float* ranges[] = {range};

	CvHistogram* hist;

	hist = cvCreateHist(dims, &size, CV_HIST_ARRAY, ranges, 1);  //
	cvClearHist(hist);

	IplImage* imgRed = cvCreateImage(cvGetSize(src), 8, 1);
	IplImage* imgGreen = cvCreateImage(cvGetSize(src), 8, 1);
	IplImage* imgBlue = cvCreateImage(cvGetSize(src), 8, 1);

	cvSplit(src, imgBlue, imgGreen, imgRed, NULL); //Դͼ��ֽ�Ϊ�ĸ�ͨ��

	cvCalcHist(&imgBlue, hist, 0, 0); //ֱ��ͼ
	IplImage* histBlue = DrawHist(hist);
	cvClearHist(hist);

	cvCalcHist(&imgGreen, hist, 0, 0);
	IplImage* histGreen = DrawHist(hist);
	cvClearHist(hist);
	
	cvCalcHist(&imgRed, hist, 0, 0);
	IplImage* histRed = DrawHist(hist);
	cvClearHist(hist);

	cvNamedWindow("B");
	cvNamedWindow("G");
	cvNamedWindow("R");

	cvShowImage("B", histBlue);
	cvShowImage("G", histGreen);
	cvShowImage("R", histRed);

	cvWaitKey(0);
	
	return 0;
}

