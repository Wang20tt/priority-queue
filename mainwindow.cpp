#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
//文件的主要功能包括了连接信号与槽的对应关系，初始化mainwindow.h文件中的变量对象，
//实现对应的槽函数的功能
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//对界面进行初始化,把在Qt设计器里面定义的信号和槽建立起来。
    D=ui->spinBox->value();
    Size=ui->spinBox_2->value();
    L=ui->spinBox_3->value();
    N=ui->spinBox_4->value();
    num=0, nw=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newWork(int ss)
{
    int n = rand() % (N+1);
    ui->textBrowser->append("\n*****新加入"+QString::number(n)+"个作业\n");
    for (int i = 0; i < n; i++)
    {
        int s, t;
        s = ss;
        t = rand() % L+ 1;
        w[nw++] = new work(s, t, num + i + 1);
        heap.insert(w[nw-1]);
        ui->textBrowser->append("作业"+QString::number(i+num+1)+",进入时间"+QString::number(s)
                                +",需执行时间"+QString::number(t)+"，优先级"+QString::number(w[nw-1]->p)+"\n");
    }
    num += n;
    ui->textBrowser->append( "\n***此时有"+QString::number(nw)+"个作业待处理。。。\n");
    for (int i = 0; i < nw; i++)
    {
        ui->textBrowser->append("作业"+QString::number(w[i]->num)+",进入时间"+QString::number(w[i]->s)
                                +",需执行时间"+QString::number(w[i]->t)+"，优先级"+QString::number(w[i]->p)+"\n");
    }
     ui->textBrowser->append("\n");
}

void MainWindow:: Working(int ss)
{
    if (wo==NULL) {
        wo = heap.top();
        if (wo==NULL)
        {
           ui->textBrowser->append("程序执行时间为" +QString::number(ss)+",现在没有作业\n");
            return;
        }
        for(int i=0;i<nw;i++){
            if (w[i]->num == (*wo).num)//w[n]里面存储的按照产生的顺序,heap里面按照优先级
            {
                for (int j = i + 1; j < nw; j++)
                    w[j - 1] = w[j];
                nw--;
                break;
            }
        }
        heap.del();
        ui->textBrowser->append("\n***开始执行作业"+QString::number((*wo).num)+",进入时间"+QString::number((*wo).s)+",需执行时间"+QString::number((*wo).t)+"，优先级"+
                                QString::number((*wo).p)+"\n");
    }
    if (wo->s + wo->ti + wo->t == ss)
    {
        ui->textBrowser->append("***程序运行时间为"+QString::number(ss)+"作业"+QString::number(wo->num )+"处理完毕，用时"+QString::number(wo->t)+"，等待"+
                                QString::number((*wo).ti)+"\n");
        delete wo;
        wo = NULL;
    }
    else ui->textBrowser->append("程序执行时间为"+QString::number(ss)+",正在执行作业"+QString::number(wo->num )+"...\n");
    for (int i = 0; i < nw; i++)
        w[i]->update(1, 1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("");//只可浏览不可编辑
    D=ui->spinBox->value();
    Size=ui->spinBox_2->value();
    L=ui->spinBox_3->value();
    N=ui->spinBox_4->value();
    num=0, nw=0;
    newWork(0);
    for (int i = 1; i < Size; i++)
    {
        if (i % D == 0) {
            newWork(i);
        }
        Working(i);
    }
    int ss = Size;
    while (heap.size()!=0&&wo!=NULL)
    {
        Working(ss++);
    }
}
