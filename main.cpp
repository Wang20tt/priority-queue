#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//创建一个QApplication类型的新实例，并调用该类的构造函数
    MainWindow w;
    srand(time(0));//随机数生成器进行初始化
    w.show();
    return a.exec();
}
