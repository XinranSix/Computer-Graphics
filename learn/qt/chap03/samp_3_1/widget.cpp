#include "widget.h"
#include "ui_widget.h"
#include <QMetaProperty>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBoxBoy->setProperty("isBoy", true);
    ui->spinBoxGirl->setProperty("isBoy", false);

    boy = new QPerson("王小明");
    boy->setProperty("score", 95);
    boy->setProperty("age",19);
    boy->setProperty("sex", "Boy");
    connect(boy,&QPerson::ageChanged,this,&Widget::on_ageChanged);

    girl = new QPerson("翠花");
    girl->setProperty("score", 85);
    girl->setProperty("age",20);
    girl->setProperty("sex", "Girl");
    connect(girl,&QPerson::ageChanged,this,&Widget::on_ageChanged);

    connect(ui->spinBoxBoy,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoxGirl ,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spin_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
    QSpinBox* spinBox = qobject_cast<QSpinBox*>(sender());
    if (spinBox->property("isBoy").toBool()) {
        boy->setAge(spinBox->value());
    } else {
        girl->setAge(spinBox->value());
    }
}

void Widget::on_ageChanged(unsigned int value)
{
    Q_UNUSED(value)
    QPerson* aPerson = qobject_cast<QPerson*>(sender());
    QString aName = aPerson->property("name").toString();
    QString aSex = aPerson->property("sex").toString();
    unsigned aAge = aPerson->age();
    ui->textExit->appendPlainText(aName + "," + aSex + QString::asprintf(",年龄=%d",aAge));
}

void Widget::on_btnBoyInc_clicked()
{
    boy->incAge();
}

void Widget::on_btnGirlInc_clicked()
{
    girl->incAge();
}

void Widget::on_btnClassInfo_clicked()
{
    const QMetaObject *meta = girl->metaObject();
    ui->textExit->clear();
    ui->textExit->appendPlainText("==元信息对象==\n");
    ui->textExit->appendPlainText(QString("类命名：%1\n").arg(meta->className()));
ui->textExit->appendPlainText("property");
    for (int i = meta->propertyOffset(); i < meta->propertyCount();++i) {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue=boy->property(propName).toString();
        ui->textExit->appendPlainText(QString("属性名称：%1，属性值：%2").arg(propName).arg(propValue));
}
    ui->textExit->appendPlainText("");
ui->textExit->appendPlainText("classInfo");
    for (int i = meta->classInfoOffset();i<meta->classInfoCount();++i) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textExit->appendPlainText(QString("Name=%1, Value=%2").arg(classInfo.name()).arg(classInfo.value()));
}
}


