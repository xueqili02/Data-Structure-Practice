#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();


private slots:
    void on_show_clicked();

private:
    Ui::History *ui;
};



#endif // HISTORY_H
