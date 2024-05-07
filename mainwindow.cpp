#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->installEventFilter(this);                 //主页面设置事件过滤器
    ui->plainTextEdit->installEventFilter(this);    //文本框设置事件过滤器
    ui->plainTextEdit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ui->plainTextEdit->appendPlainText("鼠标点击");
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ui->plainTextEdit->appendPlainText("鼠标双击");     //此句话被过滤掉了
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->plainTextEdit)
    {
       if(event->type() == QEvent::MouseButtonDblClick)
       {
           ui->plainTextEdit->appendPlainText("过滤plainTextEdit双击事件");
           return true;
       }
    }
    if(obj == this)
    {
       if(event->type() == QEvent::MouseButtonDblClick)
       {
           ui->plainTextEdit->appendPlainText("过滤主页面双击事件");
           return true;
       }
    }
    return QMainWindow::eventFilter(obj,event);
}

