#include "ui_widget.h"
#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_btnGetChars_clicked() {
  QString str = ui->editStr->text();
  if (str.isEmpty()) {
    return;
  }
  ui->plainTextEdit->clear();
  for (qint16 i = 0; i < str.size(); ++i) {
    QChar ch = str.at(i);
    char16_t uniCode = ch.unicode();
    QString chStr(ch);
    QString info =
        chStr + QString::asprintf("\t, Unicode 编码 = 0x%X", uniCode);
    ui->plainTextEdit->appendPlainText(info);
  }
}

void Widget::on_btnCharJudge_clicked() {
  QString str = ui->editChar->text();
  if (str.isEmpty()) {
    return;
  }
  QChar ch = str[0];
  char16_t uniCode = ch.unicode();
  QString chStr(ch);
  QString info =
      chStr + QString::asprintf("\t, Unicode 编码 = 0x%X\n", uniCode);
  ui->plainTextEdit->appendPlainText(info);
  ui->chkDigit->setChecked(ch.isDigit());
  ui->chkLetter->setChecked(ch.isUpper());
  ui->chkLetterOrNumber->setChecked(ch.isLetterOrNumber());
  ui->chkUpper->setChecked(ch.isUpper());
  ui->chkLower->setChecked(ch.isLower());
  ui->chkMark->setChecked(ch.isMark());
  ui->chkSpace->setChecked(ch.isSpace());
  ui->chkSymbol->setChecked(ch.isSymbol());
  ui->chkPunct->setChecked(ch.isPunct());
}

void Widget::on_btnConvLatin1_clicked() {
  QString str = "Dimple";
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(str);
  QChar chP = QChar('P');
  str[0] = chP;
  ui->plainTextEdit->appendPlainText("\n" + str);
}

void Widget::on_btnConvUTF16_clicked() {
  QString str = "Hello,北京";
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(str);
  str[6] = QChar(0x9752);
  str[7] = QChar::fromUcs2(0x5C9B);
  ui->plainTextEdit->appendPlainText("\n" + str);
}

void Widget::on_btnCompare_clicked() {
  QString str = "他们都来自于河南或河北";
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(str);
  QString HuStr = "河or湖";
  QChar He = QChar::fromUcs2(HuStr[0].unicode());
  QChar Hu = QChar(HuStr[3].unicode());
  for (qint16 i = 0; i < str.size(); ++i) {
    if (str[i] == He) {
      str[i] = Hu;
    }
    ui->plainTextEdit->appendPlainText("\n" + str);
  }
}

void Widget::on_btnClear_clicked() { ui->plainTextEdit->clear(); }
