#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxlayout>

void Dialog::initUI() {
    checkBoxUnderline = new QCheckBox(tr("Underline"));
    checkBoxItalic= new QCheckBox(tr("Italic"));
    checkBoxBold= new QCheckBox(tr("Bold"));
    QHBoxLayout *HLayout1 = new QHBoxLayout();
    HLayout1->addWidget(checkBoxUnderline);
    HLayout1->addWidget(checkBoxItalic);
    HLayout1->addWidget(checkBoxBold);

    rBtnBalck = new QRadioButton("Black");
    rBtnBlue= new QRadioButton("Blue");
    rBtnRed= new QRadioButton("Red");
    QHBoxLayout *HLayout2 = new QHBoxLayout();
    HLayout2->addWidget(rBtnBalck);
    HLayout2->addWidget(rBtnBlue);
    HLayout2->addWidget(rBtnRed);

    plainTxtEdit =new QPlainTextEdit();
    QFont font = plainTxtEdit->font();
    font.setPixelSize(20);
    plainTxtEdit->setFont(font);
    plainTxtEdit->setPlainText("Hello World\n\nThis is Arxibye!");

    btnOK = new QPushButton("OK");
    btnCancel= new QPushButton("Cancel");
    btnClose= new QPushButton("Close");
    QHBoxLayout *HLayout3 = new QHBoxLayout();
    HLayout3->addStretch();
    HLayout3->addWidget(btnOK);
    HLayout3->addWidget(btnCancel);
    HLayout3->addStretch();
    HLayout3->addWidget(btnClose);


    QVBoxLayout *VLayout = new QVBoxLayout();
    VLayout->addLayout(HLayout1);
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTxtEdit);
    VLayout->addLayout(HLayout3);
    setLayout(VLayout);
}

void Dialog::iniSignalSlots()
{
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));

    connect(checkBoxUnderline,SIGNAL(clicked(bool)),this,SLOT(on_checkUnderline(bool)));
    connect(checkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_checkItalic(bool)));
    connect(checkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_checkBold(bool)));

    connect(rBtnBalck,SIGNAL(clicked()),this,SLOT(on_setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(on_setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(on_setTextFontColor()));
}

void Dialog::on_checkUnderline(bool checked)
{
    QFont font = plainTxtEdit->font();
    font.setUnderline(checked);
    plainTxtEdit->setFont(font);
}

void Dialog::on_checkItalic(bool checked)
{
    QFont font = plainTxtEdit->font();
    font.setItalic(checked);
    plainTxtEdit->setFont(font);
}

void Dialog::on_checkBold(bool checked)
{
    QFont font = plainTxtEdit->font();
    font.setBold(checked);
    plainTxtEdit->setFont(font);
}

void Dialog::on_setTextFontColor()
{
    QPalette plet = plainTxtEdit->palette();
    if (rBtnBalck->isChecked()) {
        plet.setColor(QPalette::Text, Qt::black);
    } else if (rBtnBlue->isChecked()) {
        plet.setColor(QPalette::Text, Qt::blue);
    } else if (rBtnRed->isChecked()) {
        plet.setColor(QPalette::Text, Qt::red);
    } else {
        plet.setColor(QPalette::Text, Qt::black);
    }

    plainTxtEdit->setPalette(plet);
}


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->initUI();
    this->iniSignalSlots();
}

Dialog::~Dialog()
{
}

