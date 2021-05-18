#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "files.h"
#include <sstream>
#include <QPainter>
#include <stack>        // Provides stack type


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int i, j, k;
    stack<string> keyList;

    ui->setupUi(this);
    gotoPage("mainMenu");

    // set up souvenirs
    readSouvenirs(s, "textFiles/SouvenirList.txt");
    readSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");
    // set up graph
    readStadiums(g, "textFiles/stadiums.txt");
    readEdges(g, "textFiles/stadiumDistances.txt");

    ui->allStadiums->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < g.stadiums.size(); i++){
        ui->allStadiums->insertRow(i);
        ui->allStadiums->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getStadiumName())));
    }

    ui->souvenirListForAdd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < s.getSize(); i++){
        ui->souvenirListForAdd->insertRow(i);
        ui->souvenirListForAdd->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
        ui->souvenirListForAdd->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));
        ui->souvenirListForAdd->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(s[i].getDescription())));

        ui->modSouvenir_table->insertRow(i);
        ui->modSouvenir_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
        ui->modSouvenir_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));
        ui->modSouvenir_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(s[i].getDescription())));
    }

    // Add pages to map
    for(i = 0, j = 0; i < ui->stackedWidget->children().length(); i++)
    {
        if(!ui->stackedWidget->children()[i]->inherits("QWidget"))
            continue;

        cout << "PREPAGE[" << j << "] = " << ui->stackedWidget->children()[i]->objectName().toStdString() << "\n";
        pageMap[ui->stackedWidget->children()[i]->objectName().toStdString()] = j++;
        keyList.push(ui->stackedWidget->children()[i]->objectName().toStdString());
    }
    // Reverse indexes for map pages
    for(i = 0; i < j; i++)
    {
        cout << "PAGE[" << (j - 1 - pageMap[keyList.top()]) << "] = " << keyList.top() << "\n";
        pageMap[keyList.top()] = j - 1 - pageMap[keyList.top()];
        keyList.pop();
    }
}

MainWindow::~MainWindow()
{
    saveSouvenirs(s, "textFiles/SouvenirList.txt");
    saveSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");

    delete ui;
}
void MainWindow::gotoPage(string pg)
{
    ui->stackedWidget->setCurrentIndex(pageMap[pg]);
}

void MainWindow::on_customerPushButtonMenu_clicked()
{
    gotoPage("custWelcomePage");
}

void MainWindow::on_adminPushButtonMain_clicked()
{
    gotoPage("adminWelcomePg");
}

void MainWindow::on_customerDoneButton_clicked()
{
    gotoPage("mainMenu");
}

void MainWindow::on_mapPgDoneButton_clicked()
{
    gotoPage("planYourTripPage");
}

void MainWindow::on_adminPgDoneButton_clicked()
{
    ui->textBrowser_2->clear();

    gotoPage("mainMenu");
}

void MainWindow::on_souvenirsDoneButton_clicked()
{
    gotoPage("planYourTripPage");
}

void MainWindow::setStadiumTextBrowser(string stadiumTemp)
{
    gotoPage("stadiumInfoPage");
    stadium temp;
    temp = g.getStadiumInfo(stadiumTemp);
    string info = temp.getAllInfo();
    QString a;
    a = QString::fromStdString(info);
    ui->stadiumInfoTextBrowser->setText(a);
}

void MainWindow::on_stadiumInfoDoneButton_clicked()
{
    gotoPage("custWelcomePage");
}

void MainWindow::on_exitMainButton_clicked()
{
    saveSouvenirs(s, "textFiles/SouvenirList.txt");
    saveSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");

    close();
}

void MainWindow::on_stadiumsByNameButton_clicked()
{
    gotoPage("stadiumInfoPage");

}
void MainWindow::on_stadiumTableInfo_clicked()
{
    gotoPage("stadiuminfotable");
}
void MainWindow::on_gobacktomainpage_clicked()

{
    gotoPage("mainMenu");
}
void MainWindow::on_GrassSurface_currentIndexChanged()
{
    on_stadiumTableInfo_clicked();
}
void MainWindow::on_planTripButton_clicked()
{
    gotoPage("planYourTripPage");
}
void MainWindow::plannedTripTable()
{

}
void MainWindow::on_pushButton_31_clicked()
{

    gotoPage("custWelcomePage");
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

    gotoPage("custSouvenirsPg");
}
void MainWindow::on_pushButton_39_clicked()
{
    gotoPage("mapPlanPg");
}

void MainWindow::on_pushButton_clicked()
{
    gotoPage("modStadiumPg");

}

void MainWindow::on_modAddNewButton_clicked()
{
    ui->modificationTable->insertRow(ui->modificationTable->rowCount());
    ui->modificationTable->scrollToBottom();
}

void MainWindow::on_modStadium_doneButton_clicked()
{
    gotoPage("adminWelcomePg");
}

void MainWindow::on_adminPg_goto_modSouvenirPg_clicked()
{
    gotoPage("modSouvenirPg");
    /*
    int index;
    QObjectList list;

    list = ui->centralwidget->children();
    for(index = 0; index < list.length(); index++)
        if(list[index] == ui->modSouvenirPg)
        {
            gotoPage(index);
            break;
        }*/
}

void MainWindow::on_stadiumTable_clicked()
{
    gotoPage("stadiuminfotable");
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

void MainWindow::planTeamButtons(string stadiumName)
{
    stadium search;
    for(int i = 0; i < g.stadiums.size(); i++){
        if(g.stadiums[i].getStadiumName() == stadiumName){
            search = g.stadiums[i];
            break;
        }
    }

    if(ui->stadiumInfoCheckBox->isChecked()){
        ui->stadiumCheckBoxBrowser->setText(QString::fromStdString(search.getAllInfo()));
    } else{
        if(newStadiumaAddedbyUser.find(search) != -1){
            ui->plannedTripStadiumBrowser->setText("Already Added");
            return;
        }
        if(newStadiumaAddedbyUser.size() == 0){
            // check that first stadium is in CA
            if(search.getAddress().find("CA") == std::string::npos){
                ui->plannedTripStadiumBrowser->setText("Please choose a stadium in California");
                return;
            }
        }
        newStadiumaAddedbyUser.append(search);
        QString trip;
        for(int i = 0; i < newStadiumaAddedbyUser.size(); i++){
            trip += QString::fromStdString(newStadiumaAddedbyUser[i].getStadiumName());
            trip += "\n";
        }
        ui->plannedTripStadiumBrowser->setText(trip);
    }
}

void MainWindow::on_restartDreamList_clicked()
{
    newStadiumaAddedbyUser.~List();
    ui->plannedTripStadiumBrowser->clear();
}

void MainWindow::clearDreamList()
{
    newStadiumaAddedbyUser.~List();
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
    gotoPage("mainMenu");
}
void MainWindow::on_showMapButton_clicked()
{

    gotoPage("GeneralMap");
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
           ui->souvenirListForAdd->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(s[i].getDescription())));
        }
    }

    gotoPage("TrackSouvenirAdd");
}

void MainWindow::on_back_clicked()
{
    ui->msg->clear();
    ui->textBrowser_trackS->clear();
    ui->textBrowser_trackS->setText(QString::fromStdString(purchases.printReport()));

    QString total = "Total Spent: ";
    total += QString::fromStdString(purchases.totalPrice());
    ui->currentTotal->setText(total);
    gotoPage("custSouvenirsPg");
}

void MainWindow::on_showMapButtonMainPage_clicked()
{
    gotoPage("GeneralMap");
}

void MainWindow::on_DoneButton2_clicked()
{
    gotoPage("custWelcomePage");
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
        gotoPage("adminWelcomePg");
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

//    ui->souvenirListForAdd->insertRow(ui->souvenirListForAdd->rowCount());
//    ui->souvenirListForAdd->scrollToBottom();
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
            ui->souvenirListForAdd->removeRow(i);
            ui->modSouvenir_message->setText(QString::fromStdString("Row ") + QString::number(i) + QString::fromStdString(" removed."));
            return;
        }

        s[i].setName(item->text().toStdString());
        ui->modSouvenir_message->setText(QString::fromStdString("Name updated."));

//        ui->souvenirListForAdd->item(i, 0)->setText(QString::fromStdString(s[i].getName()));

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

//        ui->souvenirListForAdd->item(i, 1)->setText(QString::fromStdString(s[i].getPrice()));

        return;
    }

    // Handle Descsription
    if(i == 2)
    {
        i = item->row();

        s[i].setDescription(item->text().toStdString());
        ui->modSouvenir_message->setText(QString::fromStdString("Description updated."));

//        ui->souvenirListForAdd->item(i, 2)->setText(QString::fromStdString(s[i].getDescription()));
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
        QString msg = item->text() + " Purchased!";
        ui->msg->setText(msg);
    }
}

void MainWindow::on_allStadiums_itemDoubleClicked(QTableWidgetItem *item)
{
    std::string name = item->text().toStdString();
    planTeamButtons(name);
}
