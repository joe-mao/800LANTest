#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

bool MainWindow::setUp()
{
    ViStatus nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS2:DEF 'S11'\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS2:DEF 'S11' FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS2:DEF 'S11' SUCCESS", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "DISP:MEAS2:FEED 1\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("DISP:MEAS2:FEED 1 FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("DISP:MEAS2:FEED 1 SUCCESS", "SCPI");

    mySleep(500);


    nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS3:DEF 'S12'\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS3:DEF 'S12' FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS3:DEF 'S12' SUCCESS", "SCPI");

    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "DISP:MEAS3:FEED 1\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("DISP:MEAS3:FEED 1 FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("DISP:MEAS3:FEED 1 SUCCESS", "SCPI");

    mySleep(500);


    //---------------------------------------------------------------------------------
    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS4:DEF 'S22'\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC2:MEAS4:DEF 'S22' FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC2:MEAS4:DEF 'S22' SUCCESS", "SCPI");

mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "DISP:MEAS4:FEED 1\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("DISP:MEAS4:FEED 1 FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("DISP:MEAS4:FEED 1 SUCCESS", "SCPI");

    mySleep(500);


    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS5:DEF 'S11'\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC2:MEAS5:DEF 'S11' FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC2:MEAS5:DEF 'S11' SUCCESS", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "DISP:MEAS5:FEED 1\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("DISP:MEAS5:FEED 1 FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("DISP:MEAS5:FEED 1 SUCCESS", "SCPI");

    mySleep(500);


    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS6:DEF 'S12'\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC2:MEAS6:DEF 'S12' FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC2:MEAS6:DEF 'S12' SUCCESS", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "DISP:MEAS6:FEED 1\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("DISP:MEAS6:FEED 1 FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("DISP:MEAS6:FEED 1 SUCCESS", "SCPI");

    mySleep(500);

    //-----------------------------------------------------------------------------

    nRetStatus = viPrintf(networkAnalyzer, "SENS1:FREQ:STAR 1710000000\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("SENS1:FREQ:STAR 1710MHz", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("SENS1:FREQ:STAR 1710MHz", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "SENS1:FREQ:STOP 1766000000\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("SENS1:FREQ:STAR 1766MHz", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("SENS1:FREQ:STAR 1766MHz", "SCPI");

    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "SENS2:FREQ:STAR 1805000000\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("SENS2:FREQ:STAR 1805MHz", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("SENS2:FREQ:STAR 1805MHz", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "SENS2:FREQ:STOP 1860000000\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("SENS2:FREQ:STAR 1860MHz", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("SENS2:FREQ:STAR 1860MHz", "SCPI");

    mySleep(500);

    //-------------------------------------------------------------------------------
    nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS1:MARK1 ON\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS1:MARK1 ON FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS1:MARK1 ON SUCCESS", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS2:MARK1 ON\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS2:MARK1 ON FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS2:MARK1 ON SUCCESS", "SCPI");
    mySleep(500);

    nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS3:MARK1 ON\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS3:MARK1 ON FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS3:MARK1 ON SUCCESS", "SCPI");


    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS4:MARK1 ON\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC2:MEAS4:MARK1 ON FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC2:MEAS4:MARK1 ON SUCCESS", "SCPI");

    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS5:MARK1 ON\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC2:MEAS5:MARK1 ON FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC2:MEAS5:MARK1 ON SUCCESS", "SCPI");

    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS6:MARK1 ON\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC2:MEAS6:MARK1 ON FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC2:MEAS6:MARK1 ON SUCCESS", "SCPI");

    return true;

}

bool MainWindow::measure()
{
    //MAX
    ViStatus nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS1:MARK1:FUNC:EXEC MAX\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS1:MARK1:FUNC:EXEC MAX FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS1:MARK1:FUNC:EXEC MAX", "SCPI");



    nRetStatus = viPrintf(networkAnalyzer, "CALCulate1:MEASure1:MARKer1:Y?\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALCulate1:MEASure1:MARKer1:Y? FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALCulate1:MEASure1:MARKer1:Y?", "SCPI");





    ViByte rdBuff1_MAX[255] = {};
    QString qstr1_MAX = "";
    qDebug()<<QDateTime::currentDateTime();

    mySleep(500);


    nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff1_MAX);
    qDebug()<<QDateTime::currentDateTime();
    //memset(rdBuff1, '\0', sizeof(rdBuff1));

    string str1_MAX = (char *)rdBuff1_MAX;
    qstr1_MAX = QString::fromStdString(str1_MAX);

//    //qDebug()<<qstr2;//"-6.68486099243E+001,+0.00000000000E+000"
    double MaxValue_1 = qstr1_MAX.split(',').at(0).toDouble();
//    //qDebug()<<"MAX"<<qstr2;
    writeInformationToFileWithCurrentTime(qstr1_MAX, "RESPONSE");
    qDebug()<<MaxValue_1;

  //  qDebug()<<qstr1;2



//    //MIN
    nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS1:MARK1:FUNC:EXEC MIN\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALC1:MEAS1:MARK1:FUNC:EXEC MIN FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALC1:MEAS1:MARK1:FUNC:EXEC MIN", "SCPI");



    nRetStatus = viPrintf(networkAnalyzer, "CALCulate1:MEASure1:MARKer1:Y?\n", 0);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("CALCulate1:MEASure1:MARKer1:Y? FAIL", "SCPI");
        return false;
    }
    writeInformationToFileWithCurrentTime("CALCulate1:MEASure1:MARKer1:Y?", "SCPI");





    ViByte rdBuff1_MIN[255] = {};
    QString qstr1_MIN = "";
    qDebug()<<QDateTime::currentDateTime();

    mySleep(500);


    nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff1_MIN);
    qDebug()<<QDateTime::currentDateTime();
    //memset(rdBuff1, '\0', sizeof(rdBuff1));

    string str1_MIN = (char *)rdBuff1_MIN;
    qstr1_MIN = QString::fromStdString(str1_MIN);

    double MinValue_1 = qstr1_MIN.split(',').at(0).toDouble();

    writeInformationToFileWithCurrentTime(qstr1_MIN, "RESPONSE");
    qDebug()<<MinValue_1;

    //--------------------------------------------------------------------------

    nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS2:MARK1:FUNC:EXEC MAX\n", 0);
        if(nRetStatus != VI_SUCCESS){
            writeInformationToFileWithCurrentTime("CALC1:MEAS2:MARK1:FUNC:EXEC MAX FAIL", "SCPI");
            return false;
        }
        writeInformationToFileWithCurrentTime("CALC1:MEAS2:MARK1:FUNC:EXEC MAX", "SCPI");



        nRetStatus = viPrintf(networkAnalyzer, "CALCulate1:MEASure2:MARKer1:Y?\n", 0);
        if(nRetStatus != VI_SUCCESS){
            writeInformationToFileWithCurrentTime("CALCulate1:MEASure2:MARKer1:Y? FAIL", "SCPI");
            return false;
        }
        writeInformationToFileWithCurrentTime("CALCulate1:MEASure2:MARKer1:Y?", "SCPI");



        ViByte rdBuff2_MAX[255] = {};
        QString qstr2_MAX = "";
        qDebug()<<QDateTime::currentDateTime();

        mySleep(500);


        nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff2_MAX);
        qDebug()<<QDateTime::currentDateTime();
        //memset(rdBuff1, '\0', sizeof(rdBuff1));

        string str2_MAX = (char *)rdBuff2_MAX;
        qstr2_MAX = QString::fromStdString(str2_MAX);

    //    //qDebug()<<qstr2;//"-6.68486099243E+001,+0.00000000000E+000"
        double MaxValue_2 = qstr2_MAX.split(',').at(0).toDouble();
    //    //qDebug()<<"MAX"<<qstr2;
        writeInformationToFileWithCurrentTime(qstr2_MAX, "RESPONSE");
        qDebug()<<MaxValue_2;

      //  qDebug()<<qstr1;2



    //    //MIN
        nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS2:MARK1:FUNC:EXEC MIN\n", 0);
        if(nRetStatus != VI_SUCCESS){
            writeInformationToFileWithCurrentTime("CALC1:MEAS2:MARK1:FUNC:EXEC MIN FAIL", "SCPI");
            return false;
        }
        writeInformationToFileWithCurrentTime("CALC1:MEAS2:MARK1:FUNC:EXEC MIN", "SCPI");



        nRetStatus = viPrintf(networkAnalyzer, "CALCulate1:MEASure2:MARKer1:Y?\n", 0);
        if(nRetStatus != VI_SUCCESS){
            writeInformationToFileWithCurrentTime("CALCulate1:MEASure2:MARKer1:Y? FAIL", "SCPI");
            return false;
        }
        writeInformationToFileWithCurrentTime("CALCulate1:MEASure2:MARKer1:Y?", "SCPI");





        ViByte rdBuff2_MIN[255] = {};
        QString qstr2_MIN = "";
        qDebug()<<QDateTime::currentDateTime();

        mySleep(500);


        nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff2_MIN);
        qDebug()<<QDateTime::currentDateTime();
        //memset(rdBuff1, '\0', sizeof(rdBuff1));

        string str2_MIN = (char *)rdBuff2_MIN;
        qstr2_MIN = QString::fromStdString(str2_MIN);

        double MinValue_2 = qstr2_MIN.split(',').at(0).toDouble();

        writeInformationToFileWithCurrentTime(qstr2_MIN, "RESPONSE");
        qDebug()<<MinValue_2;

        //----------------------------------------------------------------------------
        nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS3:MARK1:FUNC:EXEC MAX\n", 0);
            if(nRetStatus != VI_SUCCESS){
                writeInformationToFileWithCurrentTime("CALC1:MEAS3:MARK1:FUNC:EXEC MAX FAIL", "SCPI");
                return false;
            }
            writeInformationToFileWithCurrentTime("CALC1:MEAS3:MARK1:FUNC:EXEC MAX", "SCPI");



            nRetStatus = viPrintf(networkAnalyzer, "CALCulate1:MEASure3:MARKer1:Y?\n", 0);
            if(nRetStatus != VI_SUCCESS){
                writeInformationToFileWithCurrentTime("CALCulate1:MEASure3:MARKer1:Y? FAIL", "SCPI");
                return false;
            }
            writeInformationToFileWithCurrentTime("CALCulate1:MEASure3:MARKer1:Y?", "SCPI");


            ViByte rdBuff3_MAX[255] = {};
            QString qstr3_MAX = "";
            qDebug()<<QDateTime::currentDateTime();

            mySleep(500);


            nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff3_MAX);
            qDebug()<<QDateTime::currentDateTime();
            //memset(rdBuff1, '\0', sizeof(rdBuff1));

            string str3_MAX = (char *)rdBuff3_MAX;
            qstr3_MAX = QString::fromStdString(str3_MAX);

        //    //qDebug()<<qstr2;//"-6.68486099243E+001,+0.00000000000E+000"
            double MaxValue_3 = qstr3_MAX.split(',').at(0).toDouble();
        //    //qDebug()<<"MAX"<<qstr2;
            writeInformationToFileWithCurrentTime(qstr3_MAX, "RESPONSE");
            qDebug()<<MaxValue_3;

          //  qDebug()<<qstr1;2



        //    //MIN
            nRetStatus = viPrintf(networkAnalyzer, "CALC1:MEAS3:MARK1:FUNC:EXEC MIN\n", 0);
            if(nRetStatus != VI_SUCCESS){
                writeInformationToFileWithCurrentTime("CALC1:MEAS3:MARK1:FUNC:EXEC MIN FAIL", "SCPI");
                return false;
            }
            writeInformationToFileWithCurrentTime("CALC1:MEAS3:MARK1:FUNC:EXEC MIN", "SCPI");



            nRetStatus = viPrintf(networkAnalyzer, "CALCulate1:MEASure3:MARKer1:Y?\n", 0);
            if(nRetStatus != VI_SUCCESS){
                writeInformationToFileWithCurrentTime("CALCulate1:MEASure3:MARKer1:Y? FAIL", "SCPI");
                return false;
            }
            writeInformationToFileWithCurrentTime("CALCulate1:MEASure3:MARKer1:Y?", "SCPI");





            ViByte rdBuff3_MIN[255] = {};
            QString qstr3_MIN = "";
            qDebug()<<QDateTime::currentDateTime();

            mySleep(500);


            nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff3_MIN);
            qDebug()<<QDateTime::currentDateTime();
            //memset(rdBuff1, '\0', sizeof(rdBuff1));

            string str3_MIN = (char *)rdBuff3_MIN;
            qstr3_MIN = QString::fromStdString(str3_MIN);

            double MinValue_3 = qstr3_MIN.split(',').at(0).toDouble();

            writeInformationToFileWithCurrentTime(qstr3_MIN, "RESPONSE");
            qDebug()<<MinValue_3;


            //-------------------------------------------------------------------------------
            nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS4:MARK1:FUNC:EXEC MAX\n", 0);
                if(nRetStatus != VI_SUCCESS){
                    writeInformationToFileWithCurrentTime("CALC2:MEAS4:MARK1:FUNC:EXEC MAX FAIL", "SCPI");
                    return false;
                }
                writeInformationToFileWithCurrentTime("CALC2:MEAS4:MARK1:FUNC:EXEC MAX", "SCPI");



                nRetStatus = viPrintf(networkAnalyzer, "CALCulate2:MEASure4:MARKer1:Y?\n", 0);
                if(nRetStatus != VI_SUCCESS){
                    writeInformationToFileWithCurrentTime("CALCulate2:MEASure4:MARKer1:Y? FAIL", "SCPI");
                    return false;
                }
                writeInformationToFileWithCurrentTime("CALCulate2:MEASure4:MARKer1:Y?", "SCPI");





                ViByte rdBuff4_MAX[255] = {};
                QString qstr4_MAX = "";
                qDebug()<<QDateTime::currentDateTime();

                mySleep(500);


                nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff4_MAX);
                qDebug()<<QDateTime::currentDateTime();
                //memset(rdBuff1, '\0', sizeof(rdBuff1));

                string str4_MAX = (char *)rdBuff4_MAX;
                qstr4_MAX = QString::fromStdString(str4_MAX);

            //    //qDebug()<<qstr2;//"-6.68486099243E+001,+0.00000000000E+000"
                double MaxValue_4 = qstr4_MAX.split(',').at(0).toDouble();
            //    //qDebug()<<"MAX"<<qstr2;
                writeInformationToFileWithCurrentTime(qstr4_MAX, "RESPONSE");
                qDebug()<<MaxValue_4;

              //  qDebug()<<qstr1;2



            //    //MIN
                nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS4:MARK1:FUNC:EXEC MIN\n", 0);
                if(nRetStatus != VI_SUCCESS){
                    writeInformationToFileWithCurrentTime("CALC2:MEAS4:MARK1:FUNC:EXEC MIN FAIL", "SCPI");
                    return false;
                }
                writeInformationToFileWithCurrentTime("CALC2:MEAS4:MARK1:FUNC:EXEC MIN", "SCPI");



                nRetStatus = viPrintf(networkAnalyzer, "CALCulate2:MEASure4:MARKer1:Y?\n", 0);
                if(nRetStatus != VI_SUCCESS){
                    writeInformationToFileWithCurrentTime("CALCulate2:MEASure4:MARKer1:Y? FAIL", "SCPI");
                    return false;
                }
                writeInformationToFileWithCurrentTime("CALCulate2:MEASure4:MARKer1:Y?", "SCPI");





                ViByte rdBuff4_MIN[255] = {};
                QString qstr4_MIN = "";
                qDebug()<<QDateTime::currentDateTime();

                mySleep(500);


                nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff4_MIN);
                qDebug()<<QDateTime::currentDateTime();
                //memset(rdBuff1, '\0', sizeof(rdBuff1));

                string str4_MIN = (char *)rdBuff4_MIN;
                qstr4_MIN = QString::fromStdString(str4_MIN);

                double MinValue_4 = qstr4_MIN.split(',').at(0).toDouble();

                writeInformationToFileWithCurrentTime(qstr4_MIN, "RESPONSE");
                qDebug()<<MinValue_4;



                //-------------------------------------5-------------------------------------------------
                nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS5:MARK1:FUNC:EXEC MAX\n", 0);
                    if(nRetStatus != VI_SUCCESS){
                        writeInformationToFileWithCurrentTime("CALC2:MEAS5:MARK1:FUNC:EXEC MAX FAIL", "SCPI");
                        return false;
                    }
                    writeInformationToFileWithCurrentTime("CALC2:MEAS5:MARK1:FUNC:EXEC MAX", "SCPI");



                    nRetStatus = viPrintf(networkAnalyzer, "CALCulate2:MEASure5:MARKer1:Y?\n", 0);
                    if(nRetStatus != VI_SUCCESS){
                        writeInformationToFileWithCurrentTime("CALCulate2:MEASure5:MARKer1:Y? FAIL", "SCPI");
                        return false;
                    }
                    writeInformationToFileWithCurrentTime("CALCulate2:MEASure5:MARKer1:Y?", "SCPI");





                    ViByte rdBuff5_MAX[255] = {};
                    QString qstr5_MAX = "";
                    qDebug()<<QDateTime::currentDateTime();

                    mySleep(500);


                    nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff5_MAX);
                    qDebug()<<QDateTime::currentDateTime();
                    //memset(rdBuff1, '\0', sizeof(rdBuff1));

                    string str5_MAX = (char *)rdBuff5_MAX;
                    qstr5_MAX = QString::fromStdString(str5_MAX);

                //    //qDebug()<<qstr2;//"-6.68486099243E+001,+0.00000000000E+000"
                    double MaxValue_5 = qstr5_MAX.split(',').at(0).toDouble();
                //    //qDebug()<<"MAX"<<qstr2;
                    writeInformationToFileWithCurrentTime(qstr5_MAX, "RESPONSE");
                    qDebug()<<MaxValue_5;

                  //  qDebug()<<qstr1;2



                //    //MIN
                    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS5:MARK1:FUNC:EXEC MIN\n", 0);
                    if(nRetStatus != VI_SUCCESS){
                        writeInformationToFileWithCurrentTime("CALC2:MEAS5:MARK1:FUNC:EXEC MIN FAIL", "SCPI");
                        return false;
                    }
                    writeInformationToFileWithCurrentTime("CALC2:MEAS5:MARK1:FUNC:EXEC MIN", "SCPI");



                    nRetStatus = viPrintf(networkAnalyzer, "CALCulate2:MEASure5:MARKer1:Y?\n", 0);
                    if(nRetStatus != VI_SUCCESS){
                        writeInformationToFileWithCurrentTime("CALCulate2:MEASure5:MARKer1:Y? FAIL", "SCPI");
                        return false;
                    }
                    writeInformationToFileWithCurrentTime("CALCulate2:MEASure5:MARKer1:Y?", "SCPI");




                    ViByte rdBuff5_MIN[255] = {};
                    QString qstr5_MIN = "";
                    qDebug()<<QDateTime::currentDateTime();

                    mySleep(500);


                    nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff5_MIN);
                    qDebug()<<QDateTime::currentDateTime();
                    //memset(rdBuff1, '\0', sizeof(rdBuff1));

                    string str5_MIN = (char *)rdBuff5_MIN;
                    qstr5_MIN = QString::fromStdString(str5_MIN);

                    double MinValue_5 = qstr5_MIN.split(',').at(0).toDouble();

                    writeInformationToFileWithCurrentTime(qstr5_MIN, "RESPONSE");
                    qDebug()<<MinValue_5;

                    //---------------------6------------------------------------------------
                    nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS6:MARK1:FUNC:EXEC MAX\n", 0);
                        if(nRetStatus != VI_SUCCESS){
                            writeInformationToFileWithCurrentTime("CALC2:MEAS6:MARK1:FUNC:EXEC MAX FAIL", "SCPI");
                            return false;
                        }
                        writeInformationToFileWithCurrentTime("CALC2:MEAS6:MARK1:FUNC:EXEC MAX", "SCPI");



                        nRetStatus = viPrintf(networkAnalyzer, "CALCulate2:MEASure6:MARKer1:Y?\n", 0);
                        if(nRetStatus != VI_SUCCESS){
                            writeInformationToFileWithCurrentTime("CALCulate2:MEASure6:MARKer1:Y? FAIL", "SCPI");
                            return false;
                        }
                        writeInformationToFileWithCurrentTime("CALCulate2:MEASure6:MARKer1:Y?", "SCPI");





                        ViByte rdBuff6_MAX[255] = {};
                        QString qstr6_MAX = "";
                        qDebug()<<QDateTime::currentDateTime();

                        mySleep(500);


                        nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff6_MAX);
                        qDebug()<<QDateTime::currentDateTime();
                        //memset(rdBuff1, '\0', sizeof(rdBuff1));

                        string str6_MAX = (char *)rdBuff6_MAX;
                        qstr6_MAX = QString::fromStdString(str6_MAX);

                    //    //qDebug()<<qstr2;//"-6.68486099243E+001,+0.00000000000E+000"
                        double MaxValue_6 = qstr6_MAX.split(',').at(0).toDouble();
                    //    //qDebug()<<"MAX"<<qstr2;
                        writeInformationToFileWithCurrentTime(qstr6_MAX, "RESPONSE");
                        qDebug()<<MaxValue_6;

                      //  qDebug()<<qstr1;2



                    //    //MIN
                        nRetStatus = viPrintf(networkAnalyzer, "CALC2:MEAS6:MARK1:FUNC:EXEC MIN\n", 0);
                        if(nRetStatus != VI_SUCCESS){
                            writeInformationToFileWithCurrentTime("CALC2:MEAS6:MARK1:FUNC:EXEC MIN FAIL", "SCPI");
                            return false;
                        }
                        writeInformationToFileWithCurrentTime("CALC2:MEAS6:MARK1:FUNC:EXEC MIN", "SCPI");



                        nRetStatus = viPrintf(networkAnalyzer, "CALCulate2:MEASure6:MARKer1:Y?\n", 0);
                        if(nRetStatus != VI_SUCCESS){
                            writeInformationToFileWithCurrentTime("CALCulate2:MEASure6:MARKer1:Y? FAIL", "SCPI");
                            return false;
                        }
                        writeInformationToFileWithCurrentTime("CALCulate2:MEASure6:MARKer1:Y?", "SCPI");





                        ViByte rdBuff6_MIN[255] = {};
                        QString qstr6_MIN = "";
                        qDebug()<<QDateTime::currentDateTime();

                        mySleep(500);


                        nRetStatus = viScanf(networkAnalyzer, "%s", rdBuff6_MIN);
                        qDebug()<<QDateTime::currentDateTime();
                        //memset(rdBuff1, '\0', sizeof(rdBuff1));

                        string str6_MIN = (char *)rdBuff6_MIN;
                        qstr6_MIN = QString::fromStdString(str6_MIN);

                        double MinValue_6 = qstr6_MIN.split(',').at(0).toDouble();

                        writeInformationToFileWithCurrentTime(qstr6_MIN, "RESPONSE");
                        qDebug()<<MinValue_6;





    return true;


}

bool MainWindow::setAttribute(ViSession ptr)
{
    ViStatus retStatus1 = viSetAttribute(ptr, VI_ATTR_TMO_VALUE, DEFAULT_TMO);
    ViStatus retStatus2 = viSetAttribute(ptr, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
    ViStatus retStatus3 = viSetAttribute(ptr, VI_ATTR_SEND_END_EN, VI_TRUE);
    if((retStatus1 == VI_SUCCESS) && (retStatus2 == VI_SUCCESS) && (retStatus3 == VI_SUCCESS)){
        return true;
    }
    return false;
}

void MainWindow::on_btn_start_clicked()
{


    ViStatus nRetStatus = viOpenDefaultRM(&rmSession);
    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("viOpenDefaultRM FAIL", "SCPI");
        return;
    }
    writeInformationToFileWithCurrentTime("viOpenDefaultRM SUCCESS", "SCPI");

    nRetStatus = viOpen(rmSession, this->ui->le_address->text().toStdString().c_str(), VI_NULL, VI_NULL, &networkAnalyzer);

    if(nRetStatus != VI_SUCCESS){
        writeInformationToFileWithCurrentTime("viOpen networkAnalyzer fail", "SCPI");
        return;
    }

    writeInformationToFileWithCurrentTime("viOpen networkAnalyzer success", "SCPI");


    nRetStatus = setAttribute(networkAnalyzer);

    if(!nRetStatus){
        writeInformationToFileWithCurrentTime("viSetAttribute networkAnalyzer FAIL", "SCPI");


        return;
    }
    writeInformationToFileWithCurrentTime("viSetAttribute networkAnalyzer SUCCESS", "SCPI");


    runFlag = true;



    if(setUp()){


        while(runFlag){

            measure();
            mySleep(1000);
        }

    }else{

        return;
    }


    viClose(networkAnalyzer);

    viClose(rmSession);

}

void MainWindow::on_btn_stop_clicked()
{
    runFlag = false;
}
