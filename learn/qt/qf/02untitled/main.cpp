#include <QApplication>
#include "QWidget"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    // QWidget
    QWidget win;
    win.resize(400,300);
    win.setWindowTitle("hello qt");
    win.show();
    qDebug() << "hello";

    return a.exec();
}
