#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "files.h"
#include <sstream>
#include <stack>        // Provides stack type
#include <algorithm>    // sort


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int i, j, k;
    stack<string> keyList;

    ui->setupUi(this);

    // set up souvenirs
    try{
        readSouvenirs(s, "textFiles/SouvenirList.txt");
        readSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");
        // set up graph
        readStadiums(g, "textFiles/stadiums.txt");
        readEdges(g, "textFiles/stadiumDistances.txt");
        readDreamStadiums(newStadiumaAddedbyUser, "textFiles/dreamStadiums.txt");
    } catch(const char* msg){
        std::cout << msg << std::endl;
    }

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->allStadiums->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < g.stadiums.size(); i++){
        ui->allStadiums->insertRow(i);
        ui->allStadiums->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getStadiumName())));

        ui->modificationTable->insertRow(i);
        ui->modificationTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getStadiumName())));
        ui->modificationTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getTeamName())));
        ui->modificationTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getAddress())));
        ui->modificationTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getPhone())));
        ui->modificationTable->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getOpenDate())));
        ui->modificationTable->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getCapacity())));
        ui->modificationTable->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getFieldSurface())));
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
        pageMap[ui->stackedWidget->children()[i]->objectName().toStdString()] = (QWidget*) ui->stackedWidget->children()[i];
    }
    gotoPage("mainMenu");

    loadMap(g);
}

void MainWindow::loadMap(graph g){
    std::cout << "loading images" << std::endl;

    img.load("textFiles/map.png");
    paint.begin(&img);

    yellow.setColor(QColor(0, 255, 255));
    yellow.setWidth(10);

    line.setColor(QColor(0, 0, 0));
    line.setWidth(1);

    red.setColor(QColor(255, 0, 0));
    red.setWidth(10);

    // draw all stadiums onto map
    for(int i = 0; i < g.stadiums.size(); i++){
        if(g.stadiums[i].getType() == "American League"){
            paint.setPen(red);
        } else{
            paint.setPen(yellow);
        }
        paint.drawPoint(g.stadiums[i].getXCoor(), g.stadiums[i].getYCoor());
    }

    // draw all edges on map
    paint.setPen(line);
    for(int i = 0; i < g.adjList.size(); i++){

        stadium src = g.stadiums[i];
        for(int j = 0; j < g.adjList[i].size(); j++){
            stadium des = g.adjList[i][j]._des;
            int distance = g.adjList[i][j]._distance;
            int midX = (src.getXCoor() + des.getXCoor())/2;
            int midY = (src.getYCoor() + des.getYCoor())/2;

            paint.drawLine(src.getXCoor(), src.getYCoor(), des.getXCoor(), des.getYCoor());
            paint.drawText(midX, midY, QString::fromStdString(std::to_string(distance)));
        }
    }

    ui->map2->setPixmap(img);
    ui->map2->show();
}

MainWindow::~MainWindow()
{
    try{
    saveSouvenirs(s, "textFiles/SouvenirList.txt");
    saveSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");

    saveStadiums(g, "textFiles/stadiums.txt");
    saveEdges(g, "textFiles/stadiumDistances.txt");
    saveDreamStadiums(newStadiumaAddedbyUser, "textFiles/dreamStadiums.txt");
} catch(const char* msg){
        std::cout << msg << std::endl;
    }

    delete ui;
}

void MainWindow::gotoPage(string pg)
{
    ui->stackedWidget->setCurrentWidget(pageMap[pg]);
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
    stadium temp, s;
    s.setName(stadiumTemp);
    temp = g.getStadiumInfo(s);
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

bool MainWindow::TeamName(node<stadium>& s1, node<stadium>& s2){
    return s1._data.getTeamName() < s2._data.getTeamName();
}

bool MainWindow::StadiumName(node<stadium>& s1, node<stadium>& s2){
    return s1._data.getStadiumName() < s2._data.getStadiumName();
}

bool MainWindow::Date(node<stadium>& s1, node<stadium>& s2){
    return s1._data.getOpenDate() < s2._data.getOpenDate();
}

void MainWindow::on_stadiumTableInfo_clicked()
{
    List<stadium> temp = g.stadiums;

    temp.sort(TeamName);

    for(int i = 0; i < temp.size(); i++){
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(temp[i].getStadiumName())));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(temp[i].getTeamName())));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(temp[i].getAddress())));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(temp[i].getPhone())));
        ui->tableWidget_2->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(temp[i].getOpenDate())));
        ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(temp[i].getCapacity())));
        ui->tableWidget_2->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(temp[i].getFieldSurface())));
    }

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
    stadium s;
    g.addStadium(s);
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
    stadium temp;
    temp.setName(stadiumName);
    stadium search = g.getStadiumInfo(temp);

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
    newStadiumaAddedbyUser.clear();
    ui->plannedTripStadiumBrowser->clear();
}

void MainWindow::clearDreamList()
{
    newStadiumaAddedbyUser.clear();
}
bool MainWindow::alreadyInDreamList(string stadiumName)
{
    for(int i = 0; i < dreamList.size(); i++){
        if(dreamList[i] == stadiumName){
            return true;
        }
    }

    return false;
}
void MainWindow::deleteDreamStadium(string stadiumName)
{
    for(unsigned int i = 0; i < dreamList.size(); i++)
    {

        if(dreamList[i] == stadiumName)
        {
            dreamList.Delete(stadiumName);
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

// add/edit stadium
void MainWindow::on_modificationTable_itemChanged(QTableWidgetItem *item)
{
    int i = item->column();

    if(i == 0){ // edit stadium name
        i = item->row();

        if(item->text().isEmpty()){
            g.removeStadium(g.stadiums[i]);
            ui->modificationTable->removeRow(i);
            ui->allStadiums->removeRow(i);
            return;
        }

        g.stadiums[i].setName(item->text().toStdString());
    } else if(i == 1){ // edit team name
        i = item->row();
        g.stadiums[i].setTeamName(item->text().toStdString());
    } else if(i == 2){ // edit address
        i = item->row();
        g.stadiums[i].setAddress(item->text().toStdString());
    } else if(i == 3){ // edit phone
        i = item->row();
        g.stadiums[i].setphone(item->text().toStdString());
    } else if(i == 4){ // edit date
        i = item->row();
        g.stadiums[i].setOpenDate(item->text().toStdString());
    } else if(i == 5){ // edit capacity
        i = item->row();
        g.stadiums[i].setCapacity(item->text().toStdString());
    } else if(i == 6){ // edit surface type
        i = item->row();
        g.stadiums[i].setFieldSurface(item->text().toStdString());
    } else{

    }
}

void MainWindow::on_GrassSurface_currentIndexChanged(int index)
{
    List<stadium> temp = g.stadiums;

    if(index == 0){
        temp.sort(TeamName);
    } else if(index == 1){
        temp.sort(StadiumName);
    } else if(index == 2){
        temp = g.getStadiumWithGrassField();
        temp.sort(TeamName);
    } else if(index == 3){
        temp = g.getNationalLeagueStadiums();
        temp.sort(TeamName);
    } else if(index == 4){
        temp = g.getAmericanLeagueStadiums();
        temp.sort(TeamName);
    } else{
        temp = g.stadiums;
        temp.sort(Date);
    }

    ui->tableWidget_2->setRowCount(0);
    for(int i = 0; i < temp.size(); i++){
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(temp[i].getStadiumName())));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(temp[i].getTeamName())));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(temp[i].getAddress())));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(temp[i].getPhone())));
        ui->tableWidget_2->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(temp[i].getOpenDate())));
        ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(temp[i].getCapacity())));
        ui->tableWidget_2->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(temp[i].getFieldSurface())));
    }
}
