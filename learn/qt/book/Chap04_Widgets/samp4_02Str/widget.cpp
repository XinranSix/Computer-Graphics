#include "ui_widget.h"
#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::showBoolInfo(QString str, bool CheckValue) {
  if (CheckValue) {
    ui->plainTextEdit->appendPlainText(str + "= true");
  } else {
    ui->plainTextEdit->appendPlainText(str + "= false");
  }
}

void Widget::on_pushButton_18_clicked() {
  ui->plainTextEdit->appendPlainText("\n===isNull()函数测试");
  QString str1, str2 = "";
  ui->plainTextEdit->appendPlainText("QString str1,str2="
                                     "");
  showBoolInfo("str1.isNull()", str1.isNull());
  showBoolInfo("str1.isEmpty()", str1.isEmpty());
  showBoolInfo("\nstr2.isNull()", str2.isNull());
  showBoolInfo("str2.inEmpty()", str2.isEmpty());
  str2.clear();
  ui->plainTextEdit->appendPlainText("\nstr2.clear()后");
  showBoolInfo("\nstr2.isNull()", str2.isNull());
  showBoolInfo("str2.inEmpty()", str2.isEmpty());
}

void Widget::on_btnClearText_clicked() { ui->plainTextEdit->clear(); }

void Widget::on_pushButton_23_clicked() {
  ui->plainTextEdit->appendPlainText("\n===first(), last()函数测试");
  QString str1 = ui->comboBox1->currentText();
  QString str2 = ui->comboBox2->currentText();
  ui->plainTextEdit->appendPlainText("str1= " + str1);
  ui->plainTextEdit->appendPlainText("str2= " + str2);

  int N = str1.lastIndexOf(str2);
  QString str3 = str1.first(N + 1);
  ui->plainTextEdit->appendPlainText(str3);
  str3 = str1.last(str1.size() - N - 1);
  ui->plainTextEdit->appendPlainText(str3);
}

void Widget::on_pushButton_20_clicked()
{
  ui->plainTextEdit->appendPlainText("\n===front, back()函数测试");

}

