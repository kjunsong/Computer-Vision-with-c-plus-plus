#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

    void sendSlot(); //发送常函数 定义一个槽

signals:
    /*信号必须由signals关键字来声明
     * 信号没有返回值，但可以有参数
     * 信号就是函数声明，只需声明，无需定义
     * 使用：emit mySignal();
    */
    void mySignal();

public slots:

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
