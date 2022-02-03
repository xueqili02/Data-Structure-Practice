#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand((unsigned int)time(NULL));
    start = clock();
    this -> setStyleSheet("#MainWindow{border-image:url(C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//parking.png)}");
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(upd()));
    timer -> start(10);

    memset(park, false, sizeof(park));
    memset(in, false, sizeof(in));
    memset(out, false, sizeof(out));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    n = ui -> getn -> text().toInt(), m = ui -> getm -> text().toInt();
    if(!flag) {
        flag = true;
        pk.setNum(n);
    }

    if(q.size() < m) {
        car = new Car();
        q.push(car);
    }
}

int MainWindow::getPos() {
    int pos;
    while(true) {
        pos = rand() % n + 1;
        if(!pk.p[pos].park) {
            break;
        }
    }
    return pos;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);

    for(int i = 1; i <= n; i++) {
        if(!pk.p[i].park) {
            park[i] = false;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(in[i]) {
            if(x[i] < posx[i]) {
                p.drawPixmap(x[i], 290, 200, 200, QPixmap("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//44.png"));
                x[i]++;
            }
            if(x[i] == posx[i] && !park[i] && pk.p[i].park) {
                p.drawPixmap(x[i], y[i], 200, 200, QPixmap("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//33.png"));
                if(y[i] < 450 && i <= 5) y[i]++;
                else if(y[i] > 150 && i > 5) y[i]--;
            }
            if((y[i] == 450 || y[i] == 150) && !out[i] && !park[i]) {
                park[i] = true;
                in[i] = false;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(park[i]) {
            int px = posx[i], py;
            if(i <= 5) {
                py = 450;
            }
            else {
                py = 150;
            }
            p.drawPixmap(px, py, 200, 200, QPixmap("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//33.png"));
            xout[i] = px;
            yout[i] = py;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(out[i]) {
            if(park[i]) {
                park[i] = false;
                x[i] = 0;
                y[i] = 290;
            }
            if(yout[i] > 290 && i <= 5) {
                p.drawPixmap(xout[i], yout[i], 200, 200, QPixmap("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//33.png"));
                yout[i]--;
            } else if(yout[i] < 290 && i > 5) {
                p.drawPixmap(xout[i], yout[i], 200, 200, QPixmap("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//33.png"));
                yout[i]++;
            }
            if(yout[i] == 290) {
                p.drawPixmap(xout[i], 290, 200, 200, QPixmap("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//44.png"));
                if(xout[i] < 1000) xout[i]++;
            }
            if(xout[i] == 1000) {
                out[i] = false;
            }
        }
    }
}

void store(Car* car) {
    QFile file("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//record.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << file.errorString();
    }
    QTextStream output(&file);
    output << QString::fromStdString(car -> plate) << " "
           << car -> parkingID << " "
           << car -> totalTime << " "
           << car -> charge << "\n";
    file.close();
}

double analyze() {
    QFile file("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//record.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Append)) {
        qDebug() << file.errorString();
    }
    file.seek(0);
    QTextStream in(&file);
    double income = 0;
    while(!in.atEnd()) {
        QString inLine = in.readLine();
        QStringList strlist = inLine.split(" ");
        income += strlist[3].toDouble();
    }
    file.close();
    return income;
}

int total() {
    QFile file("C://Users//lenovo//Desktop//AlgoandDSPractice//myParkingLot//record.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Append)) {
        qDebug() << file.errorString();
    }
    file.seek(0);
    QTextStream in(&file);
    int size = 0;
    while(!in.atEnd()) {
        QString inLine = in.readLine();
        size++;
    }
    file.close();
    return size;
}

void MainWindow::upd() {
    update();

    clock_t end = clock();
    int t = (double)(end - start) / CLOCKS_PER_SEC;

    ui -> emptyNum -> setText(QString::number(pk.getNum()));
    ui -> carQueue -> setText(QString::number(q.size()));

    for(int i = 1; i <= n; i++) {
        if(pk.p[i].park && pk.out(t, i)) {
            ui -> outPlate -> setText(QString::fromStdString(pk.p[i].car->plate));
            ui -> totalTime -> setText(QString::number(pk.p[i].car->totalTime));
            ui -> charge -> setText(QString::number(pk.p[i].car->charge));
            ui -> info -> append(QString::fromStdString(pk.p[i].car->plate) + " out. Charge " +
                                 QString::number(pk.p[i].car->charge));
            store(pk.p[i].car);
            out[pk.p[i].car->parkingID] = true;
        }
    }

    if(!pk.full() && !q.empty()) {
        q.pop();
        int id = getPos();
        printf("parking id: %d. ", id);fflush(stdout);
        in[id] = true;
        x[id] = 0;
        y[id] = 290;
        pk.park(t, id);
        printf("total time: %d\n", pk.p[id].car->totalTime);fflush(stdout);
        ui -> info -> append(QString::fromStdString(pk.p[id].car->plate) + " in");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    double income = analyze();
    int size = total();
    ui -> income -> setText(QString::number(income));
    ui -> totalNum -> setText(QString::number(size));
}

