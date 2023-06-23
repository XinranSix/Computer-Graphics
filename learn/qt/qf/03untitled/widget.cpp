#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1600,800);
    button = new QPushButton(this);
    button->show();
    button->resize(300,200);
    button->move(100,100);
    button->setText("登录");
}

Widget::~Widget()
{
}

