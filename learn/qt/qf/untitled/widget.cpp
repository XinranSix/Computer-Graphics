#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton*p = new QPushButton("关闭",this);
    connect(p, &QPushButton::clicked,this,&QWidget::close);
}

Widget::~Widget()
{

}
