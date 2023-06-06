#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *checkBoxUnderline;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBoxBold;

    QRadioButton *rBtnBalck;
    QRadioButton *rBtnBlue;
    QRadioButton *rBtnRed;

    QPlainTextEdit *plainTxtEdit;

    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;

    void initUI();
    void iniSignalSlots();
private slots:
    void on_checkUnderline(bool checked);
    void on_checkItalic(bool checked);
    void on_checkBold(bool checked);

    void on_setTextFontColor();
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
