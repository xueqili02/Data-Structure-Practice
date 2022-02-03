#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "history.h"
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
    void on_num_9_clicked();

    void on_num_0_clicked();

    void on_num_1_clicked();

    void on_num_2_clicked();

    void on_num_3_clicked();

    void on_num_4_clicked();

    void on_num_5_clicked();

    void on_num_6_clicked();

    void on_num_7_clicked();

    void on_num_8_clicked();

    void on_plus_clicked();

    void on_subtract_clicked();

    void on_multiply_clicked();

    void on_devide_clicked();

    void on_leftParenthesis_clicked();

    void on_rightParenthesis_clicked();

    void on_clear_clicked();

    void on_exp_clicked();

    void on_A_clicked();

    void on_B_clicked();

    void on_C_clicked();

    void on_D_clicked();

    void on_E_clicked();

    void on_F_clicked();

    void on_dot_clicked();

    void on_delete_2_clicked();

    void on_equal_clicked();

    void on_rcp_clicked();

    void on_sqrt_clicked();

    void on_sin_clicked();

    void on_cos_clicked();

    void on_bin_clicked();

    void on_oct_clicked();

    void on_hex_clicked();

    void on_dec_clicked();

private:
    Ui::MainWindow *ui;

public slots:
    void openHistory();
};

#endif // MAINWINDOW_H
