#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "sonwidget.h"
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    SonWidget *sonWindown;
    QPushButton*button1;

public slots:
    void button_cb();
    void signal_cb();
};
#endif // WIDGET_H
