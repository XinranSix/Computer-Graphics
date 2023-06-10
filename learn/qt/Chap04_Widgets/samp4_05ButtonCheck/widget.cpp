#include "ui_widget.h"
#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_btnAlign_Left_clicked() {}

void Widget::on_btnAlign_Center_clicked() {}

void Widget::on_btnAlign_Right_clicked() {}

void Widget::on_btnFont_Bold_clicked(bool checked) {}

void Widget::on_btnFont_Italic_clicked(bool checked) {}

void Widget::on_btnFont_UnderLine_clicked(bool checked) {}

void Widget::on_chkBox_Readonly_clicked(bool checked) {}

void Widget::on_chkbox_Enable_clicked(bool checked) {}

void Widget::on_chkBox_ClearButton_clicked(bool checked) {}

void Widget::on_radioBlack_clicked() {}

void Widget::on_radioRed_clicked() {}

void Widget::on_radioBlue_clicked() {}
