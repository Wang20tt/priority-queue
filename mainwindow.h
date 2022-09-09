#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//包括了需要使用到的头文件，如定时器QTimer、媒体相关QMediaPlayer等等，
//头文件还需要定义的是private slots，私有槽（信号和槽相对应）下面写的是槽对应需要执行的函数，
//最后是private，私有变量对象，对应相关组件的调用。
#include <QMainWindow>
#include<work.h>

QT_BEGIN_NAMESPACE//QT定义的空间标识
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT//只有加入了Q_OBJECT，你才能使用QT中的signal(信号)和slot(插槽)机制。

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void newWork(int ss);
    void Working(int ss);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int D, L, N, Size, num, nw;
    Heap heap;
    work* w[100], *wo;
};
#endif // MAINWINDOW_H
