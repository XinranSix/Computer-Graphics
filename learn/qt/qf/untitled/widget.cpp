#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
      this->setWindowTitle("父窗口");
    this->sonWindown = new SonWidget();
    sonWindown->show();
    button1 = new QPushButton();
    button1->setText("隐藏父窗口 显示子窗口");
    button1->setParent(this);

    connect(button1,&QPushButton::clicked,this,&Widget::button_cb);
    connect(sonWindown,&SonWidget::show_hide_signal,this,&Widget::signal_cb);
}

Widget::~Widget()
{
}

void Widget::button_cb()
{
    this->hide();
    this->sonWindown->show();
}

void Widget::signal_cb()
{
    this->show();
    this->sonWindown->hide();
}

