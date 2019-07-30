#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "visa.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    const unsigned long int DEFAULT_TMO = 5000;
    const unsigned int MAX_SCPI_LEN = 255;
    ViSession rmSession;
    ViSession networkAnalyzer;
};

#endif // MAINWINDOW_H
