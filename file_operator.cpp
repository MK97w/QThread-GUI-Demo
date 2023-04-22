#include "file_operator.h"

file_operator::file_operator(QObject *parent)
    : QObject{parent}
{
}

void file_operator::setTargetFileName(QString name)
{
    targetFileName = name;
}
void file_operator::setFileSize(qint64 size)
{
    fileSize = size;
}
unsigned int file_operator::getFileSize()
{
    return fileSize;
}

void file_operator::doSetup(QThread& cThread)
{
    QDir dir("C:/Projects/test");
    QStringList filters;
    filters <<"test"<< "*.txt";
    dir.setNameFilters(filters);
    QFileInfoList list = dir.entryInfoList();
    QString name = list.at(0).absoluteFilePath();
    file.setFileName(name);
    setFileSize(file.size());
    connect(&cThread,SIGNAL(started()),this,SLOT(parseFileInChunks()));
}

void file_operator::parseFileInChunks()
{
/*    int value =250;
    int fileSize = 25000;
    while()
    output= ((value*100)/static_cast<int>(fileSize);
 */
    /*if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString line = in.readLine(250);
          output = ((value*100)/static_cast<int>(fileSize));
          value+=250;
       }
    }
*/

    for(int i = 0; i<100; i++)
    {
        qDebug()<<i<<Qt::endl;

    }
}
