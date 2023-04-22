#ifndef FILE_OPERATOR_H
#define FILE_OPERATOR_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QProgressBar>
#include <QDir>
#include <windows.h>

class file_operator : public QObject
{
    Q_OBJECT
public:
    explicit file_operator(QObject *parent = nullptr);
    void setTargetFileName(QString);
    unsigned int getFileSize();
    void setFileSize(qint64);
    void doSetup(QThread& cThread);
    QFile file;
    int output;
    inline int returnOutput() {return output;}


public slots:
    void parseFileInChunks();
    //void writeFileInChunks(int);


signals:

private:
    QString fileName;
    qint64 fileSize;
    QString targetFileName;

};

#endif // FILE_OPERATOR_H
