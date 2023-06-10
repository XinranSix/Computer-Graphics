#include "ui_widget.h"
#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_btnCal_clicked() {
  int num = ui->editNum->text().toInt();
  float price = ui->editPrice->text().toFloat();
  float total = num * price;
  QString str;
  str = str.setNum(total, 'f', 2);
  ui->editTotal->setText(str);
}

void Widget::on_btnDec_clicked() {
  int val = ui->editDec->text().toInt();
  QString str = QString::number(val, 16);
  str = str.toUpper();
  ui->editHex->setText(str);
  str = QString::number(val, 2);
  ui->editBin->setText(str);
}

void Widget::on_btnBin_clicked() {
  int val = ui->editBin->text().toInt(nullptr, 2);
  QString str = QString::number(val, 10);
  ui->editDec->setText(str);
  str = QString::number(val, 16);
  str = str.toUpper();
  ui->editHex->setText(str);
}

void Widget::on_btnHex_clicked() {
  int val = ui->editHex->text().toInt(nullptr, 16);
  QString str = QString::number(val, 10);
  ui->editDec->setText(str);
  str = QString::number(val, 2);
  ui->editBin->setText(str);
}

void Widget::on_btnDebug_clicked() {}
