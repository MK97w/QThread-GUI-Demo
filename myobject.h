#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>

class myobject : public QObject
{
    Q_OBJECT
public:
    explicit myobject(QObject *parent = nullptr);
    void DoSetup(QThread &cThread);
    ~myobject();

signals:
    void newValue();
    void isFinished();
    void destroyThreadObject();
    void sendTimerValue(qint64);

public slots:
    void DoWork();


};

#endif // MYOBJECT_H
