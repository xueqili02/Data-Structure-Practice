#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "huffmanTree.h"
#include <QFileDialog>
#include <QMessageBox>
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


void MainWindow::on_pushButton_clicked()
{
    QString fileName = ui -> filename -> text();
    QString path = ui -> path -> text();
    if(fileName == "" || path == "") {
        QMessageBox::about(NULL, "NOTICE", "Please choose file and path!");
        return;
    }

    QFileInfo fileInfo(fileName);
    QString suffix = fileInfo.suffix();

    if(QString::compare(suffix, "txt") == 0) {
        flag = 1;
    } else if(QString::compare(suffix, "hole") == 0) {
        flag = 2;
    } else if(QString::compare(suffix, "bmp") == 0) {
        flag = 3;
    }

    // original new compressed
    string ch1, ch2, ch3;
    ch1 = fileName.toStdString();

    QString unzippedName = ui -> unzipped -> text();
    if(flag == 1) {
        unzippedName += ".txt";
    } else if(flag == 2) {
        unzippedName += ".hole";
    } else if(flag == 3) {
        unzippedName += ".bmp";
    }
    path += '/';
    path += unzippedName;
    ch2 = path.toStdString();

    string temp = fileName.toStdString();
    if(temp[temp.size() - 1] == 't' || temp[temp.size() - 1] == 'p') {
        temp.erase(temp.size() - 3, 3);
    } else {
        temp.erase(temp.size() - 4, 4);
    }
    temp += "dat";
    ch3 = temp;

    cout << ch1 << endl << ch2 << endl << ch3 << endl;

    huffmanTree ht;
    ht.encodeFile(ch1);
    ht.printCode(ht.dataSize, ch1, ch3);
    ht.decodeFile(ch3, ch2);
    QFileInfo f1(QString::fromStdString(ch1));
    QFileInfo f3(QString::fromStdString(ch3));
    ui -> before -> setText(QString::number(f1.size() / 1024 + 1));
    ui -> after -> setText(QString::number(f3.size() / 1024 + 1));
}


void MainWindow::on_chooseFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("Choose File"),
                                                    "C:",
                                          QStringLiteral("文本文件(*txt);;""图片文件(*bmp);;""二进制文件(*hole);;""压缩文件(*dat)"));
    ui -> filename -> setText(fileName);

}


void MainWindow::on_choosePath_clicked()
{
    QString pathName = QFileDialog::getExistingDirectory(this, tr("Choose Directory"),
                                                     "C:",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    if(pathName == "") return;
    ui -> path -> setText(pathName);
    QString fileName = ui -> filename -> text();
    QStringList list = fileName.split("/");
    QString name = list[list.size() - 1];
    list = name.split(".");
    name = list[0];
    name += "(unzipped)";
    ui -> unzipped -> setText(name);
}


void MainWindow::on_multiple_clicked()
{
    QStringList strList = QFileDialog::getOpenFileNames(this,QStringLiteral("Choose File"),
                                                       "C:",
                                            QStringLiteral("文本文件(*txt);;""图片文件(*bmp);;""二进制文件(*hole);;""压缩文件(*dat);;""所有文件(*)"));

    ui -> show -> setText("");
    for(int i = 0; i < strList.size(); i++) {
        QString fileName = strList[i];
        QString path = ui -> path -> text();
        if(path == "") {
            QMessageBox::about(NULL, "NOTICE", "Please choose path!");
            return;
        }

        QFileInfo fileInfo(fileName);
        QString suffix = fileInfo.suffix();

        if(QString::compare(suffix, "txt") == 0) {
            flag = 1;
        } else if(QString::compare(suffix, "hole") == 0) {
            flag = 2;
        } else if(QString::compare(suffix, "bmp") == 0) {
            flag = 3;
        }

        // original new compressed
        string ch1, ch2, ch3;
        ch1 = fileName.toStdString();

        string temp = fileName.toStdString();
        if(temp[temp.size() - 1] == 't') {
            temp.erase(temp.size() - 4, 4);
            temp += "(unzipped).txt";
        } else if(temp[temp.size() - 1] == 'p') {
            temp.erase(temp.size() - 4, 4);
            temp += "(unzipped).bmp";
        }
        else {
            temp.erase(temp.size() - 5, 5);
            temp += "(unzipped).hole";
        }
        ch2 = temp;

        temp = fileName.toStdString();
        if(temp[temp.size() - 1] == 't' || temp[temp.size() - 1] == 'p') {
            temp.erase(temp.size() - 3, 3);
        } else {
            temp.erase(temp.size() - 4, 4);
        }
        temp += "dat";
        ch3 = temp;

        cout << ch1 << endl << ch2 << endl << ch3 << endl;

        huffmanTree ht;
        ht.encodeFile(ch1);
        ht.printCode(ht.dataSize, ch1, ch3);
        ht.decodeFile(ch3, ch2);
        QFileInfo f1(QString::fromStdString(ch1));
        QFileInfo f3(QString::fromStdString(ch3));
        ui->show->append(QString::fromStdString(ch1) + " " + QString::number(f1.size() / 1024 + 1) + " bytes");
        ui->show->append(QString::fromStdString(ch3) + " " + QString::number(f3.size() / 1024 + 1) + " bytes");
    }
}

