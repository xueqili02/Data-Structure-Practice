#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g.create();
    g.floyd();
    g.kruskal();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cl() {
    ui->line->setLineWidth(1);
    ui->line_2->setLineWidth(1);
    ui->line_3->setLineWidth(1);
    ui->line_4->setLineWidth(1);
    ui->line_5->setLineWidth(1);
    ui->line_6->setLineWidth(1);
    ui->line_7->setLineWidth(1);
    ui->line_8->setLineWidth(1);
    ui->line_9->setLineWidth(1);
    ui->line_10->setLineWidth(1);
    ui->line_11->setLineWidth(1);
    ui->line_12->setLineWidth(1);
    ui->line_13->setLineWidth(1);
    ui->line_14->setLineWidth(1);
    ui->line_15->setLineWidth(1);
    ui->line_16->setLineWidth(1);
    ui->line_17->setLineWidth(1);
    ui->line_18->setLineWidth(1);
    //ui->line_19->setLineWidth(1);
    ui->line_20->setLineWidth(1);
    ui->line_21->setLineWidth(1);
    ui->line_22->setLineWidth(1);
    ui->line_23->setLineWidth(1);
    ui->line_24->setLineWidth(1);
    ui->line_25->setLineWidth(1);
    ui->line_26->setLineWidth(1);
    ui->line_27->setLineWidth(1);
    ui->line_28->setLineWidth(1);
    ui->line_29->setLineWidth(1);
    ui->line_30->setLineWidth(1);
    ui->line_31->setLineWidth(1);
    ui->line_32->setLineWidth(1);
    ui->line_33->setLineWidth(1);
    ui->line_34->setLineWidth(1);
    ui->line_35->setLineWidth(1);
    ui->line_36->setLineWidth(1);
    ui->line_37->setLineWidth(1);
}

void MainWindow::paintLine(int u, int v) {
    if((u == 1 && v == 2) || (v == 1 && u == 2)) {
        ui->line_3->setLineWidth(3);
        QPalette pa = ui->line_3->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_3->setPalette(pa);
    }
    if((u == 1 && v == 3) || (v == 1 && u == 3)) {
        ui->line_5->setLineWidth(3);
        QPalette pa = ui->line_5->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_5->setPalette(pa);
    }
    if((u == 1 && v == 5) || (v == 1 && u == 5)) {
        ui->line_20->setLineWidth(3);
        ui->line_27->setLineWidth(3);
        ui->line_28->setLineWidth(3);
        QPalette pa = ui->line_20->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_20->setPalette(pa);

        QPalette pa2 = ui->line_27->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_27->setPalette(pa2);

        QPalette pa3 = ui->line_28->palette();
        pa3.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_28->setPalette(pa3);
    }
    if((u == 1 && v == 10) || (v == 1 && u == 10)) {
        ui->line_16->setLineWidth(3);
        QPalette pa = ui->line_16->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_16->setPalette(pa);
    }
    if((u == 2 && v == 7) || (v == 2 && u == 7)) {
        ui->line_17->setLineWidth(3);
        QPalette pa = ui->line_17->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_17->setPalette(pa);
    }
    if((u == 2 && v == 8) || (v == 2 && u == 8)) {
        ui->line_6->setLineWidth(3);
        ui->line_12->setLineWidth(3);
        QPalette pa = ui->line_6->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_6->setPalette(pa);
        QPalette pa2 = ui->line_12->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_12->setPalette(pa2);
    }
    if((u == 2 && v == 9) || (v == 2 && u == 9)) {
        ui->line_31->setLineWidth(3);
        QPalette pa = ui->line_31->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_31->setPalette(pa);
    }
    if((u == 2 && v == 10) || (v == 2 && u == 10)) {
        ui->line_33->setLineWidth(3);
        ui->line_34->setLineWidth(3);
        ui->line_35->setLineWidth(3);
        QPalette pa = ui->line_33->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_33->setPalette(pa);
        QPalette pa2 = ui->line_34->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_34->setPalette(pa2);
        QPalette pa3 = ui->line_35->palette();
        pa3.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_35->setPalette(pa3);
    }
    if((u == 3 && v == 11) || (v == 3 && u == 11)) {
        ui->line_4->setLineWidth(3);
        QPalette pa = ui->line_4->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_4->setPalette(pa);
    }
    if((u == 4 && v == 5) || (v == 4 && u == 5)) {
        ui->line_10->setLineWidth(3);
        ui->line_14->setLineWidth(3);
        QPalette pa = ui->line_10->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_10->setPalette(pa);
        QPalette pa2 = ui->line_14->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_14->setPalette(pa2);
    }
    if((u == 4 && v == 6) || (v == 4 && u == 6)) {
        ui->line_7->setLineWidth(3);
        ui->line_15->setLineWidth(3);
        QPalette pa = ui->line_7->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_7->setPalette(pa);
        QPalette pa2 = ui->line_15->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_15->setPalette(pa2);
    }
    if((u == 5 && v == 6) || (v == 5 && u == 6)) {
        ui->line_22->setLineWidth(3);
        ui->line_24->setLineWidth(3);
        ui->line_25->setLineWidth(3);
        QPalette pa = ui->line_22->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_22->setPalette(pa);
        QPalette pa2 = ui->line_24->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_24->setPalette(pa2);
        QPalette pa3 = ui->line_25->palette();
        pa3.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_25->setPalette(pa3);
    }
    if((u == 5 && v == 8) || (v == 5 && u == 8)) {
        ui->line_9->setLineWidth(3);
        ui->line_36->setLineWidth(3);
        ui->line_37->setLineWidth(3);
        ui->line_32->setLineWidth(3);
        QPalette pa = ui->line_9->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_9->setPalette(pa);
        QPalette pa2 = ui->line_36->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_36->setPalette(pa2);
        QPalette pa3 = ui->line_37->palette();
        pa3.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_37->setPalette(pa3);
        QPalette pa4 = ui->line_32->palette();
        pa4.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_32->setPalette(pa4);
    }
    if((u == 5 && v == 9) || (v == 5 && u == 9)) {
        ui->line_29->setLineWidth(3);
        ui->line_30->setLineWidth(3);
        QPalette pa = ui->line_29->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_29->setPalette(pa);
        QPalette pa2 = ui->line_30->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_30->setPalette(pa2);
    }
    if((u == 5 && v == 11) || (v == 5 && u == 11)) {
        ui->line_23->setLineWidth(3);
        ui->line_26->setLineWidth(3);
        ui->line_21->setLineWidth(3);
        QPalette pa = ui->line_23->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_23->setPalette(pa);
        QPalette pa2 = ui->line_21->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_21->setPalette(pa2);
        QPalette pa3 = ui->line_26->palette();
        pa3.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_26->setPalette(pa3);
    }
    if((u == 5 && v == 13) || (v == 5 && u == 13)) {
        ui->line_9->setLineWidth(3);
        ui->line_13->setLineWidth(3);
        QPalette pa = ui->line_13->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_13->setPalette(pa);
        QPalette pa2 = ui->line_9->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_9->setPalette(pa2);
    }
    if((u == 6 && v == 11) || (v == 6 && u == 11)) {
        ui->line_8->setLineWidth(3);
        QPalette pa = ui->line_8->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_8->setPalette(pa);
    }
    if((u == 7 && v == 10) || (v == 7 && u == 10)) {
        ui->line_2->setLineWidth(3);
        QPalette pa = ui->line_2->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_2->setPalette(pa);
    }
    if((u == 7 && v == 8) || (v == 7 && u == 8)) {
        ui->line_18->setLineWidth(3);
        ui->line_12->setLineWidth(3);
        QPalette pa = ui->line_18->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_18->setPalette(pa);
        QPalette pa2 = ui->line_12->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_12->setPalette(pa2);
    }
    if((u == 7 && v == 12) || (v == 7 && u == 12)) {
        ui->line->setLineWidth(3);
        QPalette pa = ui->line->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line->setPalette(pa);
    }
    if((u == 8 && v == 9) || (v == 8 && u == 9)) {
        ui->line_32->setLineWidth(3);
        ui->line_11->setLineWidth(3);
        QPalette pa = ui->line_32->palette();
        pa.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_32->setPalette(pa);
        QPalette pa2 = ui->line_11->palette();
        pa2.setColor(QPalette::Dark, QPalette::Dark);
        ui->line_11->setPalette(pa2);
    }
}

void MainWindow::print(int u, int v) {  
    if(u == v) return;
    if(g.path[u][v] == 0) {
        ui->display->append("From " + QString::number(u) + " to " + QString::number(v));
        paintLine(u, v);
    } else {
        print(u, g.path[u][v]);
        print(g.path[u][v], v);
    }
}

void MainWindow::on_inquire_clicked()
{
    cl();
    ui->display->setText("");
    int start = ui->start->text().toInt(), end = ui->end->text().toInt();
    ui->display->append("Distance " + QString::number(g.f[start][end])  + "m");
    print(start, end);
    //ui->line->setLineWidth(3);
}

void MainWindow::on_multi_clicked()
{
    cl();
    if(ui->start->text() == "") return;
    bool check[14];
    check[1] = ui->checkBox_1->checkState();
    check[2] = ui->checkBox_2->checkState();
    check[3] = ui->checkBox_3->checkState();
    check[4] = ui->checkBox_4->checkState();
    check[5] = ui->checkBox_5->checkState();
    check[6] = ui->checkBox_6->checkState();
    check[7] = ui->checkBox_7->checkState();
    check[8] = ui->checkBox_8->checkState();
    check[9] = ui->checkBox_9->checkState();
    check[10] = ui->checkBox_10->checkState();
    check[11] = ui->checkBox_11->checkState();
    check[12] = ui->checkBox_12->checkState();
    check[13] = ui->checkBox_13->checkState();
    vector<int> node;
    for(int i = 0; i < 100; i++) {
        g.adj_multi[i].clear();
    }
    int cnt = 1;
    for(int i = 1; i <= g.n; i++) {
        if(check[i]) {
            node.push_back(i);
        }
    }
    for(int i = 0; i < (int) node.size(); i++) {
        for(int j = i + 1; j < (int) node.size(); j++) {
            for(int k = 1; k <= g.m; k++) {
                if((g.e[k].u == node[i] && g.e[k].v == node[j]) || (g.e[k].v == node[i] && g.e[k].u == node[j])) {
                    g.addEdge_multi(node[i], node[j], g.e[k].w);
                    g.addEdge_multi(node[j], node[i], g.e[k].w);
                    printf("flag %d %d %d\n", g.e[k].u, g.e[k].v, g.e[k].w);
                    break;
                }
            }
            /*if(!flag) {
                printf("node %d %d %d %d\n", node[i], node[j], g.f[node[i]][node[j]], g.f[node[j]][node[i]]);
                g.addEdge_multi(node[i], node[j], g.f[node[i]][node[j]]);
                g.addEdge_multi(node[j], node[i], g.f[node[j]][node[i]]);
            }*/

            edge temp;
            temp.u = node[i];
            temp.v = node[j];
            temp.w = g.f[node[i]][node[j]];
            g.e_multi[cnt] = temp;
            cnt++;
        }
    }
    memset(g.vis, false, sizeof(g.vis));
    g.kruskal_multi(cnt - 1);
    int start = ui->start->text().toInt();
    g.traversal_multi(start);
    ui->display->setText("");
    int pre;
    if(!g.multiPath.empty()) {
        pre = g.multiPath.front();
    }
    while(!g.multiPath.empty()) {
        //printf("%d\n", g.multiPath.front());
        //ui->display->append(QString::number(g.multiPath.front()));
        print(pre, g.multiPath.front());
        pre = g.multiPath.front();
        g.multiPath.pop();
    }
}

void MainWindow::on_info_clicked()
{
    bool check[14];
    check[1] = ui->checkBox_1->checkState();
    check[2] = ui->checkBox_2->checkState();
    check[3] = ui->checkBox_3->checkState();
    check[4] = ui->checkBox_4->checkState();
    check[5] = ui->checkBox_5->checkState();
    check[6] = ui->checkBox_6->checkState();
    check[7] = ui->checkBox_7->checkState();
    check[8] = ui->checkBox_8->checkState();
    check[9] = ui->checkBox_9->checkState();
    check[10] = ui->checkBox_10->checkState();
    check[11] = ui->checkBox_11->checkState();
    check[12] = ui->checkBox_12->checkState();
    check[13] = ui->checkBox_13->checkState();
    ui->display->setText("");
    for(int i = 1; i <= g.n; i++) {
        if(check[i]) {
            ui->display->append(g.intro[i]);
        }
    }
}

void MainWindow::on_all_clicked()
{
    cl();
    if(ui->start->text() == "") return;
    ui->display->setText("");
    memset(g.vis, false, sizeof(g.vis));
    int start = ui->start->text().toInt();
    g.traversal_mst(start);
    int pre;
    if(!g.allPath.empty()) {
        pre = g.allPath.front();
    }
    while(!g.allPath.empty()) {
        //ui->display->append(QString::number(g.allPath.front()));
        //paintLine(pre, g.allPath.front());
        print(pre, g.allPath.front());
        pre = g.allPath.front();
        g.allPath.pop();
    }
}

