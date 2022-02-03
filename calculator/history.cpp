#include "history.h"
#include "ui_history.h"
#include <QFile>
History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_show_clicked()
{
    QFile file("C://Users//lenovo//Desktop//AlgoandDSPractice//calculator//history.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
    }
    QTextStream input(&file);
    QString line;
    ui -> historyDisplay -> setText("");
    while(!input.atEnd()) {
        line = input.readLine();
        ui -> historyDisplay -> append(line);
//        ui -> historyDisplay -> append("\n");
    }
    file.close();
}

