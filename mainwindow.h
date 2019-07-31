#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "visa.h"
#include <string>
#include <vector>

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
    bool writToLog(QString fileName);

protected:
    void closeEvent(QCloseEvent *event) override;

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
    vector<vector<vector<double>>> result;
    vector<vector<double>> measurePara;
    vector<double> measureResult;
    quint64 totalTestCount = 0;
    quint64 failTestCount = 0;
    int errorFlag = 0;

};

#endif // MAINWINDOW_H
