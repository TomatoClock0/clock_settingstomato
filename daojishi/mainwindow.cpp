#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include<QPainter>

int restofTime =0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timerrrr=new QTimer(this);
    timerrrr->setInterval(1000);

    connect(timerrrr,SIGNAL(timeout()), this, SLOT(lcdnumberDisplay()));

    connect(timer, SIGNAL(timeout()), this, SLOT(myslot()));
    connect(timer, SIGNAL(timeout()), timerrrr,SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//QMessageBox message(QMessageBox::NoIcon,"Title","content with icon");

void MainWindow::myslot()

{   //QMessageBox::NoIcon,"Title","content with icon";
    QMessageBox message(QMessageBox::NoIcon,"TomatoClock","番茄时间到");
    message.setIconPixmap(QPixmap("iccccon.PNG"));
    message.exec();
    //QMessageBox::warning(this, "timer", QObject::trUtf8("时间到!"));

    timer->stop();

}

void MainWindow::on_pushButton_clicked()

{

    QString str = ui->plainTextEdit->toPlainText();

    bool OK;

    int num = str.toInt(&OK, 10);

    restofTime=num;
    num *= 1000;
    timer->start(num);
    timerrrr->start();
}

void MainWindow:: lcdnumberDisplay(){  
    ui->lcdNumber->display(restofTime);
    restofTime--;
}
