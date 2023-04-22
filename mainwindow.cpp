#include "mainwindow.h"
#include "myobject.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>

#define THREAD 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //, obj(new myobject)

{
    ui->setupUi(this);
    //connect(this->ui->pushButton,SIGNAL(pressed()),this,SLOT(progBarIncrease()));
#if THREAD


#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
#if THREAD
    ui->pushButton->setEnabled(false);

    cThread = new QThread;
    obj = new myobject;

    connect(cThread,SIGNAL(started()),obj,SLOT(DoWork()));
    connect(obj,SIGNAL(newValue()),this,SLOT(progBarIncrease()));

    connect(obj,SIGNAL(sendTimerValue(qint64)),this,SLOT(showElapsedTime(qint64)));
    connect(obj,SIGNAL(isFinished()),this,SLOT(pushButtonState()));
    connect (obj,SIGNAL(isFinished()),cThread, SLOT(quit()));
    connect(obj,SIGNAL(isFinished()),this,SLOT(pushButtonState()));
    connect (obj,SIGNAL(isFinished()),obj, SLOT(deleteLater()));
    connect(cThread,SIGNAL(finished()),cThread,SLOT(deleteLater()));


    //obj->DoSetup(*cThread);
    obj->moveToThread(cThread);
    cThread->start();

#else
    int x = 0;
    for(int i = 0; i < 100; i++)
    {
        while(x != 100000000)
        {
            x++;
        }
        x = 0;
        qDebug() << i;
        progBarIncrease();
    }
#endif
   // emit ui->pushButton->pressed();

}


void MainWindow::progBarIncrease()
{
    ui->progressBar->setValue(value++);
    if(100 == value)
    {
        ui->progressBar->setValue(0);
        value = 0;
    }
}

void MainWindow::pushButtonState()
{
    ui->pushButton->setEnabled(true);
}

void MainWindow::showElapsedTime(qint64 elapsedTime)
{
    qDebug()<<"Elapsed Time:"<<elapsedTime<<"ms";
}
