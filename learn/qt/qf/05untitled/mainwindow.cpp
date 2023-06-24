#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600,400);
    QMenuBar *menubar1 = this->menuBar();
    QMenu*fileMenu = menubar1->addMenu("文件");
    QMenu*fileEdit= menubar1->addMenu("编辑");
    QAction*openFile=   fileMenu->addAction("打开");
    fileMenu->addSeparator();
    QAction*saveFile=   fileMenu->addAction("保存");

    QToolBar*toolBar =  this->addToolBar("");
    toolBar->addAction(openFile);
    toolBar->addAction(saveFile);

    QStatusBar*status =   this->statusBar();
    status->addWidget(new QLabel("状态"));

    QDockWidget*dockWidget = new QDockWidget("这是一个铆接部件",this);
    this->addDockWidget(Qt::TopDockWidgetArea,dockWidget);

    QTextEdit*edit = new QTextEdit("文本编辑器",this);
    this->setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}
