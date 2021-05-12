
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "files.h"
#include <sstream>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gotoPage(0);
    readSouvenirs(s, "textFiles/SouvenirList.txt");
    readSouvenirsPurchases(purchases, "textFiles/SouvenirPurchases.txt");

    ui->souvenirListForAdd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < s.getSize(); i++){
        ui->souvenirListForAdd->insertRow(i);
        ui->souvenirListForAdd->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
        ui->souvenirListForAdd->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));

        ui->modSouvenir_table->insertRow(i);
        ui->modSouvenir_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
        ui->modSouvenir_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));
    }

    //Setup Push buttons
    ui->dodgerButton->setFixedSize(80, 55);
    ui->angelsButton->setFixedSize(80, 55);
    ui->sanDiegoButton->setFixedSize(80, 55);
    ui->oaklandAButton->setFixedSize(80, 55);
}

MainWindow::~MainWindow()
{
    saveSouvenirs(s, "textFiles/SouvenirList.txt");
    saveSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");

    delete ui;
}
void MainWindow::gotoPage(int pg)
{
    ui->stackedWidget->setCurrentIndex(pg);
}

void MainWindow::on_customerPushButtonMenu_clicked()
{
    gotoPage(1);
}

void MainWindow::on_adminPushButtonMain_clicked()
{
    gotoPage(5);
}

void MainWindow::on_customerDoneButton_clicked()
{
    gotoPage(0);
}

void MainWindow::on_mapPgDoneButton_clicked()
{
    gotoPage(6);
}

void MainWindow::on_adminPgDoneButton_clicked()
{
    ui->textBrowser_2->clear();
    gotoPage(0);
}

void MainWindow::on_souvenirsDoneButton_clicked()
{
    gotoPage(6);
}

void MainWindow::setStadiumTextBrowser(string stadiumTemp)
{
    gotoPage(2);
    stadium temp;
    temp = g.getStadiumInfo(stadiumTemp);
    string info = temp.getAllInfo();
    QString a;
    a = QString::fromStdString(info);
    ui->stadiumInfoTextBrowser->setText(a);
}

void MainWindow::on_stadiumInfoDoneButton_clicked()
{
    gotoPage(1);
}

void MainWindow::on_exitMainButton_clicked()
{
    saveSouvenirs(s, "textFiles/SouvenirList.txt");
    saveSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");

    close();
}

void MainWindow::on_minnesotaButton_clicked()
{
    planTeamButtons("Target Field");
}

void MainWindow::on_texasRangersButton_clicked()
{
    planTeamButtons("Globe Life Park in Arlington");
}

void MainWindow::on_houstonButton_clicked()
{
    planTeamButtons("Minute Maid Park");
}

void MainWindow::on_milwaukeeButton_clicked()
{
    planTeamButtons("Miller Park");
}

void MainWindow::on_chicagoButton_clicked()
{
    planTeamButtons("Wrigley Field");
}

void MainWindow::on_chicagoWhiteSoxButton_clicked()
{
    planTeamButtons("US Cellular Field");
}

void MainWindow::on_cincinattiButton_clicked()
{
    planTeamButtons("Great America Ball Park");
}

void MainWindow::on_atlantaButton_clicked()
{
    planTeamButtons("Turner Field");
}

void MainWindow::on_clevelandButton_clicked()
{
    planTeamButtons("Progressive Field");
}

void MainWindow::on_tampaBayButton_clicked()
{
    planTeamButtons("Tropicana Field");
}

void MainWindow::on_floridaButton_clicked()
{
    planTeamButtons("Marlins Park");
}

void MainWindow::on_pittsburghButton_clicked()
{
    planTeamButtons("PNC Park");
}

void MainWindow::on_washingtonButton_clicked()
{
    planTeamButtons("Nationals Park");
}

void MainWindow::on_torontoButton_clicked()
{
    planTeamButtons("Rogers Centre");
}

void MainWindow::on_detroitButton_2_clicked()
{
    planTeamButtons("Comerica Park");
}

void MainWindow::on_bostonButton_clicked()
{
    planTeamButtons("Fenway Park");
}

void MainWindow::on_baltimoreButton_clicked()
{
    planTeamButtons("Oriole Park at Camden Yards");
}

void MainWindow::on_phillyButton_clicked()
{
    planTeamButtons("Citizens Bank Park");
}

void MainWindow::on_nyYankeesButton_clicked()
{
    planTeamButtons("Yankee Stadium");
}

void MainWindow::on_dodgerButton_clicked()
{
    planTeamButtons("Dodger Stadium");
}

void MainWindow::on_angelsButton_clicked()
{
    planTeamButtons("Angels Stadium of Anaheim");
}

void MainWindow::on_kansasCityButton_clicked()
{
    planTeamButtons("Kauffman Stadium");
}

void MainWindow::on_stLouisButton_clicked()
{
    planTeamButtons("Busch Stadium");
}

void MainWindow::on_nyMetsButton_clicked()
{
    planTeamButtons("Citi Field");
}

void MainWindow::on_stadiumsByNamButton_clicked()
{
    gotoPage(2);

}
void MainWindow::on_stadiumTableInfo_clicked()
{
    gotoPage(7);
}
void MainWindow::on_gobacktomainpage_clicked()

{
    gotoPage(0);
}
void MainWindow::on_GrassSurface_currentIndexChanged()
{
    on_stadiumTableInfo_clicked();
}
void MainWindow::on_planTripButton_clicked()
{
    gotoPage(6);
}
void MainWindow::plannedTripTable()
{

}
void MainWindow::on_pushButton_31_clicked()
{

    gotoPage(1);
}

void MainWindow::on_allStadiumsButton_clicked()
{
}

void MainWindow::on_pushButton_38_clicked()
{
    ui->textBrowser_trackS->clear();
    ui->textBrowser_trackS->setText(QString::fromStdString(purchases.printReport()));

    QString total = "Total Spent: ";
    total += QString::fromStdString(purchases.totalPrice());
    ui->currentTotal->setText(total);

    gotoPage(4);
}
void MainWindow::on_pushButton_39_clicked()
{
    gotoPage(3);
}

void MainWindow::on_pushButton_clicked()
{
    gotoPage(8);

}

void MainWindow::on_modAddNewButton_clicked()
{
    ui->modificationTable->insertRow(ui->modificationTable->rowCount());
    ui->modificationTable->scrollToBottom();
}

void MainWindow::on_modDoneButton_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    gotoPage(9);

}

void MainWindow::on_stadiumTable_clicked()
{
    gotoPage(7);

}
void MainWindow::on_stadiumInfoCheckBox_stateChanged(int arg1)
{
    if(ui->stadiumInfoCheckBox->isChecked())
    {
        ui->stadiumCheckBoxBrowser->setText("Select a stadium to see their info!");
    }
    else
    {
        ui->stadiumCheckBoxBrowser->setText("Check to select a stadiums' info.");
    }
}
void MainWindow::on_sanDiegoButton_clicked()
{
    planTeamButtons("Petco Park");
}

void MainWindow::on_sanFranciscoButton_clicked()
{
    planTeamButtons("AT&T Park");
}

void MainWindow::on_oaklandAButton_clicked()
{
    planTeamButtons("O.co Coliseum");
}

void MainWindow::on_seattleButton_clicked()
{
    planTeamButtons("SafeCo Field");
}

void MainWindow::on_coloradoButton_clicked()
{
    planTeamButtons("Coors Field");
}

void MainWindow::on_arizonaButton_clicked()
{
    planTeamButtons("Chase Field");
}

void MainWindow::planTeamButtons(string stadiumName)
{

}
void MainWindow::on_restartDreamList_clicked()
{


}

void MainWindow::clearDreamList()
{

}
bool MainWindow::alreadyInDreamList(string stadiumName)
{

}
void MainWindow::deleteDreamStadium(string stadiumName)
{
    for(unsigned int i = 0; i < dreamList.size(); i++)
    {

        if(dreamList[i] == stadiumName)
        {
            dreamList.erase(dreamList.begin()+i);
            return;
        }
    }
}
QString MainWindow::getDreamStrArray()
{

}

void MainWindow::on_allNLStadiumsButton_clicked()
{

}
void MainWindow::on_allALStadiumsButton_clicked()
{


}
void MainWindow::on_backtoMain_clicked()
{
    gotoPage(0);
}
void MainWindow::on_showMapButton_clicked()
{


}

List<stadium> MainWindow::modify_newStadiumAddedByUser(List<stadium> list){

}

List<stadium> MainWindow::getStadiumListALL(){

}

bool MainWindow::isNewStadium(stadium toCheck){

}

void MainWindow::on_pushButton_5_clicked()
{
    // load table of souvenirs - s
    if(ui->souvenirListForAdd->rowCount() < s.getSize()){
        for(int i = ui->souvenirListForAdd->rowCount(); i < s.getSize(); i++){
           ui->souvenirListForAdd->insertRow(i);
           ui->souvenirListForAdd->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
           ui->souvenirListForAdd->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));
        }
    }
    gotoPage(10);
}

void MainWindow::on_back_clicked()
{
    ui->msg->clear();
    ui->textBrowser_trackS->clear();
    ui->textBrowser_trackS->setText(QString::fromStdString(purchases.printReport()));

    QString total = "Total Spent: ";
    total += QString::fromStdString(purchases.totalPrice());
    ui->currentTotal->setText(total);
    gotoPage(4);
}

void MainWindow::on_showMapButtonMainPage_clicked()
{

}

void MainWindow::on_DoneButton2_clicked()
{
    gotoPage(1);
}



void MainWindow::on_modSouvenir_doneButton_clicked()
{
    size_t i;
    bool check;
    string message;

    ui->modSouvenir_message->setText("");
    message = "";

    for(i = 0; i < ui->modSouvenir_table->rowCount(); i++)
    {
        ui->modSouvenir_table->item(i, 1)->text().toDouble(&check);
        if(!check)
            message += "Invalid price for row: " + std::to_string(i + 1) + "   " + ui->modSouvenir_table->itemAt(i, 1)->text().toStdString() + "\n";
    }

    if(message.empty())
    {
        gotoPage(5);
        return;
    }

    ui->modSouvenir_message->setText(QString::fromStdString(message));
}

void MainWindow::on_modSouvenir_addButton_clicked()
{
    souvenir _s;

    s.addSouvenir(_s);
    ui->modSouvenir_table->insertRow(ui->modSouvenir_table->rowCount());
    ui->modSouvenir_table->scrollToBottom();
}
void MainWindow::on_modSouvenir_table_itemChanged(QTableWidgetItem *item)
{
    bool check;
    int i;

    i = item->column();
    // Handle Name
    if(i == 0)
    {
        i = item->row();
        // Remove
        if(item->text().isEmpty())
        {
            s.removeSouvenir(i);
            ui->modSouvenir_table->removeRow(i);
            ui->modSouvenir_message->setText(QString::fromStdString("Row ") + QString::number(i) + QString::fromStdString(" removed."));
            return;
        }

        s[i].setName(item->text().toStdString());
        ui->modSouvenir_message->setText(QString::fromStdString("Name updated."));

        return;
    }

    // Handle Price
    if(i == 1)
    {
        i = item->row();

        item->text().toDouble(&check);
        if(!check)
        {
            ui->modSouvenir_message->setText(QString::fromStdString("Invalid price for row: ") + QString::number(i+1));
            return;
        }

        s[i].setPrice(item->text().toStdString());
        ui->modSouvenir_message->setText(QString::fromStdString("Price updated."));
        return;
    }

    // ignore rest
}

void MainWindow::on_souvenirListForAdd_itemDoubleClicked(QTableWidgetItem *item)
{
    // add to purchases
    if(item->column() == 0){
        int index = purchases.getIndex(item->text().toStdString());
        if(index != -1){
            purchases[index].addQuantity();
        } else{
            index = s.getIndex(item->text().toStdString());
            purchases.addSouvenir(s[index]);
            purchases[purchases.getSize()-1].addQuantity();
        }
    }
    ui->msg->setText("Purchased!");
}

