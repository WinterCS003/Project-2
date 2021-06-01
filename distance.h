#ifndef DISTANCE_H
#define DISTANCE_H

#include <QDialog>
#include "list.h"
#include "stadium.h"

namespace Ui {
class Distance;
}

class Distance : public QDialog
{
    Q_OBJECT

public:
    explicit Distance(QWidget *parent = nullptr);
    ~Distance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Distance *ui;
};

#endif // DISTANCE_H
