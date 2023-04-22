#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myobject.h"
//#include <file_operator.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void threadGarbageCollector(QThread);

signals:
    void newValue(int value);

private slots:
    void on_pushButton_clicked();
    void progBarIncrease();
    void pushButtonState();
    void showElapsedTime(qint64);

private:
    Ui::MainWindow *ui;
    int value{1};
    //file_operator* fileOp;
    myobject* obj{nullptr};
    QThread* cThread{nullptr};
};
#endif // MAINWINDOW_H
