#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "myQueue.h"
#include "parking.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void paintEvent(QPaintEvent *);
    int getPos();
    void upd();

private:
    Ui::MainWindow *ui;
    int x[11], y[11], xout[11], yout[11], posx[11] = {0, 212, 340, 458, 578, 700, 212, 340, 458, 578, 700};
    bool park[11], in[11], out[11];
    int n = 1, m;
    bool flag = false;
    Car* car;
    myQueue q;
    parking pk;
    clock_t start;
};
#endif // MAINWINDOW_H
