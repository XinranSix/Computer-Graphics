#include "widget.h"
#include <QMetaClassInfo>
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    boy = new TPerson("王小明", this);
    boy->setProperty("score", 95);
    boy->setProperty("age", 10);
    boy->setProperty("sex", "Boy");
    connect(boy, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));

    girl = new TPerson("张小丽", this);
    girl->setProperty("score", 81);
    girl->setProperty("age", 20);
    girl->setProperty("sex", "Girl");
    connect(girl, &TPerson::ageChanged, this, &Widget::do_ageChanged);

    ui->spinBoy->setProperty("isBoy", true);
    ui->spinGirl->setProperty("isBoy", false);
    connect(ui->spinGirl, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
    connect(ui->spinBoy, &QSpinBox::valueChanged, this, &Widget::do_spinChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_ageChanged(int value)
{
    Q_UNUSED(value)
    TPerson *person = qobject_cast<TPerson *>(sender());
    QString hisName = person->property("name").toString();
    QString hisSex = person->property("sex").toString();
    int hisAge = person->age();
    QString str = QString("%1, %2, 年龄=%3").arg(hisName).arg(hisSex).arg(hisAge);
    qDebug(str.toStdString().c_str());
    ui->textEdit->appendPlainText(str);
}

void Widget::do_spinChanged(int arg1)
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if (spinBox->property("isBoy").toBool()) {
        boy->setAge(arg1);
    } else {
        girl->setAge(arg1);
    }
}

void Widget::on_btnClassInfo_clicked()
{
    QObject *obj = boy;
    const QMetaObject *meta = obj->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("property");
    for (int i = meta->propertyOffset(); i < meta->propertyCount(); ++i) {
        const char *propName = meta->property(i).name();
        QString propValue = obj->property(propName).toString();
        QString str = QString("属性名称=%1，属性值=%2").arg(propName).arg(propValue);
        ui->textEdit->appendPlainText(str);
    }
    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");
    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); ++i) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->appendPlainText(
            QString("Name=%1; Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}
