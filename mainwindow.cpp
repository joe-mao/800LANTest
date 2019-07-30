#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>

void mySleep(int msec)
{
    QDateTime reachTime = QDateTime::currentDateTime().addMSecs(msec);
    while(QDateTime::currentDateTime() < reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}


bool writeInformationToFileWithCurrentTime(QString strInformation, QString flag)
{
    //flag == "[SCPI]"表示写入仪器的指令
    //flag == "[RESPONSE]"表示仪器反馈给机台的信息
    QDateTime timeStart = QDateTime::currentDateTime();//获取系统现在时间
    QString str = timeStart.toString("yyyy-MM-dd hh:mm:ss.zzz");//显示设置格式
    QFile file("LAN.log");
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        return false;
    }
    QTextStream out(&file);

    out << str << " " << "[LAN]" << " " << "[" + flag + "]" << " " << strInformation<<"\n";

    file.close();
    return true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
