#include "sonwidget.h"

SonWidget::SonWidget(QWidget *parent)
    : QWidget{parent}
{
    button2 = new QPushButton("隐藏子窗口 显示父窗口",this);
    this->setWindowTitle("子窗口");

    connect(button2,&QPushButton::clicked,this,&SonWidget::emit_mysignal);
}

void SonWidget::emit_mysignal()
{
    emit show_hide_signal(10);
}
