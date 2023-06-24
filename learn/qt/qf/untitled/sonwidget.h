#ifndef SONWIDGET_H
#define SONWIDGET_H

#include <QWidget>
#include <QPushButton>

class SonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SonWidget(QWidget *parent = nullptr);
    QPushButton*button2;
signals:
    void show_hide_signal(int a);
public slots:
    void emit_mysignal();
};

#endif // SONWIDGET_H
