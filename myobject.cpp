#include "myobject.h"
#include <QDebug>

myobject::myobject(QObject *parent)
    : QObject{parent}
{
    qDebug()<<"my object constructed"<<Qt::endl;
}

void myobject::DoSetup(QThread &cThread)
{
    connect(&cThread,SIGNAL(started()),this,SLOT(DoWork()));
    connect(&cThread,SIGNAL(finished()),&cThread,SLOT(deleteLater()));
}
void myobject::DoWork()
{
    QElapsedTimer timer;
    timer.start();
    unsigned long x = 0;
    for(int i = 0; i < 100; i++)
    {
        while(x != 1000000)
        {
            x++;
        }
        x = 0;
        emit newValue();
        qDebug() << i;
    }
    emit sendTimerValue(timer.elapsed());
    emit isFinished();
    emit destroyThreadObject();
}

myobject::~myobject()
{
     qDebug()<<"my object destructed"<<Qt::endl;
}
