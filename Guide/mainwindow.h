#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include "graph.h"
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
    void on_inquire_clicked();
    void print(int u, int v);
    void on_multi_clicked();
    void paintLine(int u, int v);
    void on_info_clicked();
    void cl();
    void on_all_clicked();
private:
    Ui::MainWindow *ui;
    graph g;
    int line[20][20];
};
#endif // MAINWINDOW_H
