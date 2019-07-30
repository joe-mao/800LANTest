#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "visa.h"
#include <string>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool setUp();
    bool measure();
    bool setAttribute(ViSession ptr);//返回true表示设置属性成功，返回false表示设置属性失败

private slots:
    void on_btn_start_clicked();

    void on_btn_stop_clicked();

private:
    Ui::MainWindow *ui;
    const unsigned long int DEFAULT_TMO = 50;
    const unsigned int MAX_SCPI_LEN = 255;
    ViSession rmSession;
    ViSession networkAnalyzer;
    bool runFlag = false;
};

#endif // MAINWINDOW_H
