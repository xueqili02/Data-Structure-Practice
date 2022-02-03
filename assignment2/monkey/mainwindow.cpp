/*
Name: Li Xueqi
Number: 20301110
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedlist.h"
#include <cstdio>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// convert image path to html
void imgPathToHtml(QString &path) {
    path = QString("<img src=\"%1\"/>").arg(path);
}

void MainWindow::on_startButton_clicked()
{
    ui -> statusBrowser -> setText("");
    ui -> outcomeBrowser -> setText("");
    Linkedlist ll;
    int n = ui -> totalField -> text().toInt();
    int m = ui -> outField -> text().toInt();
    QString imgPath = QString("C:/Users/lenovo/Desktop/AlgoandDSPractice/assignment2/monkey/monkey.png"); // image path
    imgPathToHtml(imgPath);
    Node* head = new Node();
    ll.build(head); // build circular linked list
    Node* temp = head;
    Node* pre = temp;
    int cnt = 1, last = n;
    while(temp != NULL) {
        // count m monkeys
        if(cnt == m) {
            printf("%d ", temp -> val);
            ui -> outcomeBrowser -> insertPlainText(QString:: number(temp -> val));
            ui -> outcomeBrowser -> insertHtml(imgPath);
            ui -> outcomeBrowser -> insertPlainText("  ");
            fflush(stdout);
            pre -> next = temp -> next;
            temp = pre -> next;
            cnt = 1;
            last--;
            if(m == 1 && last != 1) continue;
        }
        // the last monkey is the king
        if(last == 1) {
            printf("\nWinner: %d\n", temp -> val);
            ui -> statusBrowser -> insertPlainText("                                                                                                                 ");
            ui -> statusBrowser -> insertPlainText("King: " + QString:: number(temp -> val) + "\n");
            ui -> statusBrowser -> insertPlainText("                                                                                                                 ");
            ui -> statusBrowser -> insertHtml(imgPath);
            ui -> statusBrowser -> insertPlainText("\n");
            fflush(stdout);
            break;
        }
        pre = temp;
        temp = temp -> next;
        cnt++;
    }
}

