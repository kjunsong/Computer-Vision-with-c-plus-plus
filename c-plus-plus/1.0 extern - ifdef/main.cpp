// project_opencv.cpp: 定义控制台应用程序的入口点。
// 
#include "stdafx.h"
#include "file.h"

extern int a;       //修饰符extern在用在变量或者函数的声明之前，用来说明此变量/函数是在别处定义的，要在此处引用
extern void fun();

int main()
{
	float x, s;
	x_printf();
	//printf("input x:");
	//scanf("%f", x);
	fun();
	printf("%d\n", a);

#ifdef F
	printf("yes\n");
#else
	printf("no\n");
#endif

	return 0;
}
