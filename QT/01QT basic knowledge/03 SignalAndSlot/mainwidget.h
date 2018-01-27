#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h" //子窗口头文件

class MainWidget : public QWidget //这个类是自动生成的
{
    Q_OBJECT  //是一个宏来的

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void mySlot();
    void changeWin();
    void dealSub();

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidget w;

};

#endif // MAINWIDGET_H
