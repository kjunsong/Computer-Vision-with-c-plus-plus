//OpenCV_����ʶ��
#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include "cxcore.h"

void displaydetection(IplImage* pInpImg, CvSeq* pFaceRectSeq, char* FileName);

int main(int argc, char** argv)
{
	IplImage* pInpImg = 0;
	CvHaarClassifierCascade* pCascade = 0;      //ָ�������ļ��л�ȡ�ķ�����  
	CvMemStorage* pStorage = 0;                 //�洢��⵽����������  
	CvSeq* pFaceRectSeq;                        //�������ռ�⺯�����ص�һϵ�еİ��������ľ�������  
/*
	if (argc<2)
	{
		printf("missing name of image file!\n");
		return -1;
	}*/
	
	//��ʼ��  
	pInpImg = cvLoadImage("D:\\Documents\\�ҵĹ�����\\�Ƽ��ı�����\\I.jpg", 1);//D:\\Documents\\�ҵĹ�����\\С������ͷ\\1.jpg
	pStorage = cvCreateMemStorage(0);           //����Ĭ�ϴ���64k�Ķ�̬�ڴ�����  
	//���ط���������������������ʶ��Ч����õ�ģ���ļ�������ʶ��������⣩
	pCascade = (CvHaarClassifierCascade*)cvLoad("F:\\opencv\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml"); 
	/**/
	if (!pInpImg || !pStorage || !pCascade)
	{
		printf("initialization failed:%s\n", (!pInpImg) ? "can't load image file" : (!pCascade) ? "can't load haar-cascade---make sure path is correct" : "unable to allocate memory for data storage", argv[1]);
		return -1;
	}

	//�������  
	pFaceRectSeq = cvHaarDetectObjects(pInpImg, pCascade, pStorage,
		1.2, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(40, 40));
	//����⵽�������Ծ��ο�����  
	displaydetection(pInpImg, pFaceRectSeq, argv[1]);

	cvReleaseImage(&pInpImg);
	cvReleaseHaarClassifierCascade(&pCascade);
	cvReleaseMemStorage(&pStorage);
	return 0;
}

void displaydetection(IplImage* pInpImg, CvSeq* pFaceRectSeq, char* FileName)
{
	int i;
	cvNamedWindow("haar window", 1);
	printf("the number of face is %d", pFaceRectSeq->total);
	for (i = 0; i<(pFaceRectSeq ? pFaceRectSeq->total : 0); i++)
	{
		CvRect* r = (CvRect*)cvGetSeqElem(pFaceRectSeq, i);
		CvPoint pt1 = { r->x, r->y };
		CvPoint pt2 = { r->x + r->width, r->y + r->height };

		//      cvSetImageROI(pInpImg,*r);  
		//      IplImage* dst=cvCreateImage(cvSize(92,112),pInpImg->depth,pInpImg->nChannels);  
		//      cvResize(pInpImg,dst,CV_INTER_LINEAR);  
		//      cvSaveImage("lian.jpg",dst);  
		cvRectangle(pInpImg, pt1, pt2, CV_RGB(0, 255, 0), 3, 4, 0);
	}
	cvShowImage("haar window", pInpImg);
	//  cvResetImageROI(pInpImg);  
	cvWaitKey(0);
	cvDestroyWindow("haar window");
}
