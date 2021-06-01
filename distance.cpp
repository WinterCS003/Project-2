#include "distance.h"
#include "ui_distance.h"
#include <fstream>

Distance::Distance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Distance)
{
    ui->setupUi(this);
}

Distance::~Distance()
{
    delete ui;
}

void Distance::on_pushButton_clicked()
{
    list<stadium> a;
    fstream file("textFiles/stadiums.txt");
    string x;
    while(file.eof())
    {
        getline(file,x);
    }
}

