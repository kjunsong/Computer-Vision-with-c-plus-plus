#include "stdafx.h" 
#include "file.h"
#include <iostream>

#define F 1
int a = 2;  //未在file.h文件中定义，但是可以在mian.c文件中通过extern使用

void fun()  
{
	printf("%d\n", a);
}

void x_printf()
{
	printf("x\n");
}
