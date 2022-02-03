#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
int main(int argc, char *argv[])
{printf("111\n");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.dat");
     if (!db.open()) {
            QMessageBox::warning(0, QObject::tr("Database Error"),
                                 db.lastError().text());
            return false;
     }
    /*QSqlQuery query;
    query.exec("UPDATE  node  SET intro = '思源楼'  WHERE  id = 1 ");
    query.exec("UPDATE  node  SET intro = '思源西楼'  WHERE  id = 2 ");
    query.exec("UPDATE  node  SET intro = '思源东楼'  WHERE  id = 3 ");
    query.exec("UPDATE  node  SET intro = '逸夫楼'  WHERE  id = 4 ");
    query.exec("UPDATE  node  SET intro = '九教'  WHERE  id = 5 ");
    query.exec("UPDATE  node  SET intro = '图书馆'  WHERE  id = 6 ");
    query.exec("UPDATE  node  SET intro = '体育馆'  WHERE  id = 7 ");
    query.exec("UPDATE  node  SET intro = '学生活动中心'  WHERE  id = 8 ");
    query.exec("UPDATE  node  SET intro = '校史馆'  WHERE  id = 9 ");
    query.exec("UPDATE  node  SET intro = '校训碑'  WHERE  id = 10 ");
    query.exec("UPDATE  node  SET intro = '明湖'  WHERE  id = 11 ");
    query.exec("UPDATE  node  SET intro = '西门'  WHERE  id = 12 ");
    query.exec("UPDATE  node  SET intro = '南门'  WHERE  id = 13 ");*/
 /*   query.exec("CREATE TABLE edge ("
                    "first INTEGER NOT NULL, "
                    "second INTEGER NOT NULL, "
                    "weight INTEGER NOT NULL)");
    //query.exec("DELETE FROM edge");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (13, 21, 0)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (1, 2, 50)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (1, 3, 50)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (1, 5, 210)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (1, 10, 150)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (2, 7, 320)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (2, 8, 150)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (2, 9, 80)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (2, 10, 140)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (3, 11, 70)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (4, 5, 390)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (4, 6, 120)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (5, 6, 310)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (5, 8, 480)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (5, 9, 290)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (5, 11, 330)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (5, 13, 120)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (6, 11, 60)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (7, 19, 290)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (7, 8, 230)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (7, 12, 50)");
    query.exec("INSERT INTO edge (first, second, weight) "
                   "VALUES (8, 9, 200)");

    query.exec("CREATE TABLE node ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "name VARCHAR(40) NOT NULL, "
                "intro VARCHAR(40) NOT NULL)");
    query.exec("DELETE FROM node");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (1, 'siyuan', '111')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (2, 'sixi', '222')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (3, 'sidong', '333')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (4, 'yifu', '444')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (5, 'No.9Building', '555')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (6, 'library', '666')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (7, 'gym', '777')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (8, 'StudentCenter', '888')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (9, 'HistoryBuilding', '999')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (10, 'SchoolMotto', '101010')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (11, 'MingLake', '111111')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (12, 'WestGate', '121212')");
    query.exec("INSERT INTO node (id, name, intro) "
                   "VALUES (13, 'SouthGate', '131313')");
*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
