#include "mywidget.h"
#include <QApplication> //QT头文件没有.h QApplication应用程序类，文件名和类名一样

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//有且只有一个应用程序类对象

    //w就是一个窗口类
    myWidget w; //MyWidget是一个窗口类，它继承于QWidget（QWidget是一个窗口基类）

    w.show(); //窗口创建默认是隐藏的，需要设置显示

    a.exec(); //让程序一直执行，等待事件发生（用户操作）
    return 0;
    //return a.exec();
}
