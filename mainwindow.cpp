#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>
#include <stack>        // Provides stack type

#include "files.h"

/*******************************************************************
 * void loadStadiumTable1();
 *
 *   Accessor; This method will load all stadiums into the modify
 *             stadiums table
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::loadStadiumTable1(){
    // page 8 modify stadium
    ui->modificationTable->setRowCount(0);
    for(int i = 0; i < g.stadiums.size(); i++){
        ui->modificationTable->insertRow(i);
        ui->modificationTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getStadiumName())));
        ui->modificationTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getTeamName())));
        ui->modificationTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getAddress())));
        ui->modificationTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getPhone())));
        ui->modificationTable->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getOpenDate())));
        ui->modificationTable->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getCapacity())));
        ui->modificationTable->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getFieldSurface())));
        ui->modificationTable->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getType())));
    }
}

/*******************************************************************
 * void loadStadiumTable2();
 *
 *   Accessor; This method will load all stadiums into the all stadium
 *             table on the welcome page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::loadStadiumTable2(){
    // stadiums list on page 1
    ui->allStadiums->setRowCount(0);
    for(int i = 0; i < g.stadiums.size(); i++){
        ui->allStadiums->insertRow(i);
        ui->allStadiums->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(g.stadiums[i].getStadiumName())));
    }
}

/*******************************************************************
 * void loadStadiumTable3();
 *
 *   Accessor; This method will load all stadiums into the stadium
 *             info table.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::loadStadiumTable3(){
    // page 7 - stadium info table
    List<stadium> temp = g.stadiums;
    temp.sort(TeamName);

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
        ui->tableWidget_2->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(temp[i].getType())));
    }
}

/*******************************************************************
 * void loadSouvenirTable1();
 *
 *   Accessor; This method will load all souenirs into the purchase
 *             souvenirs table
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::loadSouvenirTable1(){
    // page 10 - purchase souvenir
    ui->souvenirListForAdd->setRowCount(0);
    for(int i = 0; i < s.getSize(); i++){
        ui->souvenirListForAdd->insertRow(i);
        ui->souvenirListForAdd->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
        ui->souvenirListForAdd->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));
        ui->souvenirListForAdd->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(s[i].getDescription())));
    }
}

/*******************************************************************
 * void loadSouvenirTable2();
 *
 *   Accessor; This method will load all souenirs into the edit
 *             souvenirs table
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::loadSouvenirTable2(){
    // page 9 create new souvenir
    ui->modSouvenir_table->setRowCount(0);
    for(int i = 0; i < s.getSize(); i++){
        ui->modSouvenir_table->insertRow(i);
        ui->modSouvenir_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s[i].getName())));
        ui->modSouvenir_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(s[i].getPrice())));
        ui->modSouvenir_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(s[i].getDescription())));
    }
}

/****************************************************************
 * MainWindow(QWidget *parent = nullptr);
 *   Constructor; Create a new instance of the window
 *   Parameters: parent (QWidget*) // IN - pointer to widget
 *   Return: none
 ***************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int i, j;
    stack<string> keyList;

    ui->setupUi(this);

    // load state
    try{
        readSouvenirs(s, "textFiles/SouvenirList.txt");
        readSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");
        // set up graph
        readStadiums(g, "textFiles/stadiums.txt");
        readEdges(g, "textFiles/stadiumDistances.txt");
        readDreamStadiums(newStadiumaAddedbyUser, "textFiles/dreamStadiums.txt");
        img.load("textFiles/map.png");
        paint.begin(&img);
        paint.save();
    } catch(const char* msg){
        std::cout << msg << std::endl;
    }

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->allStadiums->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->souvenirListForAdd->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->dijkstrasTable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    // Add pages to map
    for(i = 0, j = 0; i < ui->stackedWidget->children().length(); i++)
    {
        if(!ui->stackedWidget->children()[i]->inherits("QWidget"))
            continue;
        pageMap[ui->stackedWidget->children()[i]->objectName().toStdString()] = (QWidget*) ui->stackedWidget->children()[i];
    }

    gotoPage("mainMenu");

    ui->Xcord->hide();
    ui->Xcord->clear();
    ui->xLabel->hide();
    ui->Ycord->hide();
    ui->Ycord->clear();
    ui->yLabel->hide();
    ui->submit->hide();

    ui->mapLegend->hide();
}

/*******************************************************************
 * void loadMap(graph g, List<stadium>* custom = nullptr);
 *
 *   Accessor; This method will load the map onto the screen
 *             with all edges and stadiums from the graph on it.
 *------------------------------------------------------------------
 *   Parameter: g (graph) // IN – graph to print onto map
 *              custom(List<stadium*>) // IN - custom stadiums to
 *                                             print
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::loadMap(graph g, List<stadium>* custom){
    int ii;

    std::cout << "loading images" << std::endl;
    paint.end();
    paint.eraseRect(0,0, 640, 416);

    img.load("textFiles/map.png");
    img = img.scaled(ui->map2->geometry().width(), ui->map2->geometry().height());
    paint.begin(&img);

    yellow.setColor(QColor(0, 255, 255));
    yellow.setWidth(10);

    red.setColor(QColor(255, 0, 0));
    red.setWidth(10);

    line.setColor(QColor(0, 0, 0));
    line.setWidth(1);

    // print a custom stadium map
    if(custom && !custom->isEmpty()){
        QPen green;
        green.setColor(QColor(0,255,0));

        int total_path[g.stadiums.size()*g.stadiums.size()];
        int total_path_used;
        int total_distance;
        g.getShortestTripPath(total_path, total_path_used, *custom, total_distance);

        QPen trace;
        trace.setWidth(5);
        trace.setColor(Qt::darkGreen);
        ui->stadiumsVisited->clear();
        for(ii = 1; ii < total_path_used; ii++)
        {
            ui->stadiumsVisited->addItem(QString::fromStdString(g.stadiums[total_path[ii-1]].getStadiumName()));
            stadium src = g.stadiums[total_path[ii-1]];
            stadium des = g.stadiums[total_path[ii]];

            int distance = g.getedge(src, des)->_distance;

            int midX = (src.getXCoor() + des.getXCoor())/2;
            int midY = (src.getYCoor() + des.getYCoor())/2;

            paint.setPen(trace);
            paint.drawLine(src.getXCoor(), src.getYCoor(), des.getXCoor(), des.getYCoor());

            paint.setPen(line);
            paint.drawText(midX, midY, QString::fromStdString("(") + QString::number(ii) + QString::fromStdString(") " + std::to_string(distance)));
        }
        ui->stadiumsVisited->addItem(QString::fromStdString(g.stadiums[total_path[ii-1]].getStadiumName()));
        QString visited = "Visited: ";
        visited += QString::fromStdString(to_string(total_path_used));
        ui->numbVisited->setText(visited);
        QString dis = "Distance: ";
        dis += QString::fromStdString(to_string(total_distance));
        ui->distance->setText(dis);

        paint.setPen(nullptr);
        paint.setBrush(Qt::green);
        for(ii = 0; ii < custom->size(); ii++)
        {
            paint.drawEllipse((*custom)[ii].getXCoor()-10, (*custom)[ii].getYCoor()-10, 20, 20);
        }

        for(int i = 0; i < total_path_used; i++){
            if(g.stadiums[total_path[i]].getType() == "American League"){
                paint.setPen(red);
            } else{
                paint.setPen(yellow);
            }

            int x = g.stadiums[total_path[i]].getXCoor();
            int y = g.stadiums[total_path[i]].getYCoor();
            paint.drawPoint(x, y);
        }
    }
    // print all stadiums
    else{
        // draw all stadiums onto map
        for(int i = 0; i < g.stadiums.size(); i++){
            if(g.stadiums[i].getType() == "American League"){
                paint.setPen(red);
            } else{
                paint.setPen(yellow);
            }
            paint.drawPoint(g.stadiums[i].getXCoor(), g.stadiums[i].getYCoor());
            paint.setPen(line);
            paint.drawText(g.stadiums[i].getXCoor(), g.stadiums[i].getYCoor(), QString::fromStdString(g.stadiums[i].getStadiumName()));
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
    }

    ui->map2->setPixmap(img);
    ui->map2->show();
}

/*******************************************************************
 * void update_path_view()
 *
 *   Accessor; This method update the path view page with correct
 *             information
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::update_path_view()
{
    if(ui->pathViewCombo_1->currentText().isEmpty() || ui->pathViewCombo_2->currentText().isEmpty())
        return;
    if(ui->pathViewCombo_1->currentText() == ui->pathViewCombo_2->currentText())
    {
        ui->pathViewLabel->setText("Please select different stadiums.");
        return;
    }

    List<stadium> path;
    for(int i = 0; i < g.stadiums.size(); i++)
    {
        if(g.stadiums[i].getStadiumName() == ui->pathViewCombo_1->currentText().toStdString())
        {
            path.append(g.stadiums[i]);
            break;
        }
    }
    for(int i = 0; i < g.stadiums.size(); i++)
    {
        if(g.stadiums[i].getStadiumName() == ui->pathViewCombo_2->currentText().toStdString())
        {
            path.append(g.stadiums[i]);
            break;
        }
    }

    int total_path[g.stadiums.size()*g.stadiums.size()];
    int pathUsed;
    int totalDistance;
    g.getShortestTripPath(total_path, pathUsed, path, totalDistance);

    paint2.end();
    paint2.eraseRect(0,0, 640, 416);

    img2.load("textFiles/map.png");
    img2 = img2.scaled(ui->pathMap->geometry().width(), ui->pathMap->geometry().height());
    paint2.begin(&img2);

    QPen trace;
    trace.setWidth(5);
    trace.setColor(Qt::darkGreen);
    int i = 1;
    for(; i < pathUsed; i++)
    {
        stadium src = g.stadiums[total_path[i-1]];
        stadium des = g.stadiums[total_path[i]];

        int distance = g.getedge(src, des)->_distance;

        int midX = (src.getXCoor() + des.getXCoor())/2;
        int midY = (src.getYCoor() + des.getYCoor())/2;

        paint2.setPen(trace);
        paint2.drawLine(src.getXCoor(), src.getYCoor(), des.getXCoor(), des.getYCoor());

        paint2.setPen(line);
        paint2.drawText(midX, midY, QString::fromStdString("(") + QString::number(i) + QString::fromStdString(") " + std::to_string(distance)));
    }
    paint2.setPen(nullptr);
    paint2.setBrush(Qt::green);
    paint2.drawEllipse(path[0].getXCoor()-10, path[0].getYCoor()-10, 20, 20);
    paint2.drawEllipse(path[1].getXCoor()-10, path[1].getYCoor()-10, 20, 20);
    ui->pathViewLabel->setText(QString::fromStdString("Total Airports Visited: ") + QString::number(pathUsed) + QString::fromStdString(", Total Distance: ") + QString::number(totalDistance));

    ui->pathMap->setPixmap(img2);
}

/****************************************************************
 * ~MainWindow();
 *   Destructor; Frees any dynamically allocated memory
 *   Parameters: none
 *   Return: none
 ***************************************************************/
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

/*******************************************************************
 * void gotoPage(string pg);
 *
 *   Accessor; This method will switch the screen to the indicated
 *             page
 *------------------------------------------------------------------
 *   Parameter: pg (string) // IN – page to switch to
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::gotoPage(string pg)
{
    ui->stackedWidget->setCurrentWidget(pageMap[pg]);
}

/*******************************************************************
 * void on_customerPushButtonMenu_clicked();
 *
 *   Accessor; This method will switch the window to the main menu
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_customerPushButtonMenu_clicked()
{
    loadStadiumTable2();

    if(!newStadiumaAddedbyUser.isEmpty()){
        QString stadiums;
        for(int i = 0; i < newStadiumaAddedbyUser.size(); i++){
            stadiums += QString::fromStdString(newStadiumaAddedbyUser[i].getStadiumName());
            stadiums += "\n";
        }
        ui->plannedTripStadiumBrowser->setText(stadiums);
    }

    gotoPage("custWelcomePage");
}

/*******************************************************************
 * void on_adminPushButtonMain_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the admin console
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_adminPushButtonMain_clicked()
{
    gotoPage("adminWelcomePg");
}

/*******************************************************************
 * void on_customerDoneButton_clicked();
 *
 *   Accessor; This method will switch the window to the previous
 *             screen.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_customerDoneButton_clicked()
{
    gotoPage("mainMenu");
}

/*******************************************************************
 * void on_mapPgDoneButton_clicked();
 *
 *   Accessor; This method will switch the window from the map
 *             page to the main menu page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_mapPgDoneButton_clicked()
{
    gotoPage("planYourTripPage");

    ui->mapLegend->hide();
}

/*******************************************************************
 * void on_adminPgDoneButton_clicked();
 *
 *   Accessor; This method will switch the window to the previous
 *             screen from the admin console.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_adminPgDoneButton_clicked()
{
    ui->textBrowser_2->clear();

    gotoPage("mainMenu");
}

/*******************************************************************
 * void on_souvenirsDoneButton_clicked();
 *
 *   Accessor; This method will switch the window to the previous
 *             screen from the souvenirs page.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_souvenirsDoneButton_clicked()
{
    gotoPage("planYourTripPage");
}

/*******************************************************************
 * void setStadiumTextBrowser(string stadiumTemp);
 *
 *   Accessor; This method will set text browser with information
 *             from the given stadium.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

/*******************************************************************
 * void on_stadiumInfoDoneButton_clicked();
 *
 *   Accessor; This method will switch the window to the previous
 *             screen from the staium info page.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_stadiumInfoDoneButton_clicked()
{
    loadStadiumTable2();
    gotoPage("custWelcomePage");
}

/*******************************************************************
 * void on_exitMainButton_clicked();
 *
 *   Accessor; This method will save the state of the program
 *             before closing the window.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_exitMainButton_clicked()
{
    saveSouvenirs(s, "textFiles/SouvenirList.txt");
    saveSouvenirs(purchases, "textFiles/SouvenirPurchases.txt");

    close();
}

/*******************************************************************
 * void on_stadiumsByName_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the stadium info page.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_stadiumsByNameButton_clicked()
{
    gotoPage("stadiumInfoPage");
}

/*******************************************************************
 * bool TeamName(node<stadium>& s1, node<stadium>& s2);
 *
 *   Accessor; This method will sort the stadiums by team name.
 *------------------------------------------------------------------
 *   Parameter: s1 (node<stadium>&) // IN - stadium node to compare
 *              s2 (node<stadium>&) // IN - stadium node to compare
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
bool MainWindow::TeamName(node<stadium>& s1, node<stadium>& s2){
    return s1._data.getTeamName() < s2._data.getTeamName();
}

/*******************************************************************
 * bool StadiumName(node<stadium>& s1, node<stadium>& s2);
 *
 *   Accessor; This method will sort the stadiums by stadium name.
 *------------------------------------------------------------------
 *   Parameter: s1 (node<stadium>&) // IN - stadium node to compare
 *              s2 (node<stadium>&) // IN - stadium node to compare
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
bool MainWindow::StadiumName(node<stadium>& s1, node<stadium>& s2){
    return s1._data.getStadiumName() < s2._data.getStadiumName();
}

/*******************************************************************
 * bool date(node<stadium>& s1, node<stadium>& s2);
 *
 *   Accessor; This method will sort the stadiums by opening date.
 *------------------------------------------------------------------
 *   Parameter: s1 (node<stadium>&) // IN - stadium node to compare
 *              s2 (node<stadium>&) // IN - stadium node to compare
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
bool MainWindow::date(node<stadium>& s1, node<stadium>& s2){
    Date d1(s1._data.getOpenDate());
    Date d2(s2._data.getOpenDate());

    return d1 < d2;
}

/*******************************************************************
 * void on_stadiumTableInfo_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the page with all stadium info
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_stadiumTableInfo_clicked()
{
    loadStadiumTable3();
    gotoPage("stadiuminfotable");
}

/*******************************************************************
 * void on_gobacktomainpage_clicked();
 *
 *   Accessor; This method will switch the window to the main window
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_gobacktomainpage_clicked()
{
    gotoPage("mainMenu");
}

/*******************************************************************
 * void on_planTripButton_clicked();
 *
 *   Accessor; This method will switch the window to the plan trip
 *             page.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_planTripButton_clicked()
{
    ui->dijkstrasTable->setRowCount(0);
//    ui->dijkstrasTable->clear();
    ui->totalDistanceBrowser->setText("N/A");
    ui->totalStadiumsVisitedBrowser->setText("N/A");

    if(!newStadiumaAddedbyUser.isEmpty()){
        // load custom graph
        int total_path[g.stadiums.size()*g.stadiums.size()];
        int total_used;
        int total_distance;
        g.getShortestTripPath(total_path, total_used, newStadiumaAddedbyUser, total_distance);
        // print total distance traveled
        QString distance = "Total Distance Traveled: ";
        distance += QString::fromStdString(to_string(total_distance));

        ui->totalDistanceBrowser->setText(distance);

        // print total number of stadiums visited
        distance = "Total Stadiums visited: ";
        distance += QString::fromStdString(to_string(total_used));

        ui->totalStadiumsVisitedBrowser->setText(distance);

        // print all stadiums visited
        ui->dijkstrasTable->setRowCount(0);
        for(int i = 0; i < total_used; i++){
            ui->dijkstrasTable->insertRow(i);
            QString stadium;
            stadium = QString::fromStdString(g.stadiums[total_path[i]].getStadiumName());
            ui->dijkstrasTable->setItem(i, 0, new QTableWidgetItem(stadium));
        }
    }

    gotoPage("planYourTripPage");
}

/*******************************************************************
 * void on_pushButton_31_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the welcome page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_31_clicked()
{
    loadStadiumTable2();
    gotoPage("custWelcomePage");
}

/*******************************************************************
 * void on_pushButton_38_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the souvenirs bought page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_38_clicked()
{
    ui->textBrowser_trackS->clear();
    ui->textBrowser_trackS->setText(QString::fromStdString(purchases.printReport()));

    QString total = "Total Spent: ";
    total += QString::fromStdString(purchases.totalPrice());
    ui->currentTotal->setText(total);

    gotoPage("custSouvenirsPg");
}

/*******************************************************************
 * void on_pushButton_39_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the map page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_39_clicked()
{
    gotoPage("mapPlanPg");
}

/*******************************************************************
 * void on_pushButton_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the mod stadium page, allowing the user
 *             to edit stadium info as an admin.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_clicked()
{
    loadStadiumTable1();
    gotoPage("modStadiumPg");
    err = true;
}

/*******************************************************************
 * void on_modAddNewButton_clicked();
 *
 *   Accessor; This method will allow the user to add a new stadium
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_modAddNewButton_clicked()
{
    ui->Xcord->show();
    ui->xLabel->show();
    ui->Ycord->show();
    ui->yLabel->show();
    ui->submit->show();
}

/*******************************************************************
 * void on_modStadium_doneButton_clicked();
 *
 *   Accessor; This method will allow the user to save changes
 *             for any stadium edits.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_modStadium_doneButton_clicked()
{
    gotoPage("adminWelcomePg");
    err = false;
}

/*******************************************************************
 * void on_adminPg_goto_modSouvenirPg_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the mod souvenir page, allowing the user to
 *             edit souvenir info as an admin
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_adminPg_goto_modSouvenirPg_clicked()
{
    loadSouvenirTable2();
    gotoPage("modSouvenirPg");
    err = true;
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

/*******************************************************************
 * void on_stadiumTable_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the stadium info page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_stadiumTable_clicked()
{
    loadStadiumTable3();
    gotoPage("stadiuminfotable");
}

/*******************************************************************
 * void on_stadiumInfoCheckBox_stateChanged(int arg1);
 *
 *   Accessor; This method will allow the user to toggle between
 *             adding stadiums and viewing stadium info.
 *------------------------------------------------------------------
 *   Parameter: arg1 (int) // IN - state of check box
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

/*******************************************************************
 * void planTeamButtons(string stadiumName);
 *
 *   Accessor; This method will add the following stadium to the
 *             custom trip.
 *------------------------------------------------------------------
 *   Parameter: stadiumName (string) // IN - stadium to add
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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
            if(search.getAddress2().find("CA") == std::string::npos){
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

/*******************************************************************
 * void on_restartDreamList_clicked();
 *
 *   Accessor; This method will clear all custom teams added by the
 *             user
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_restartDreamList_clicked()
{
    newStadiumaAddedbyUser.clear();
    ui->plannedTripStadiumBrowser->clear();
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
    for(int i = 0; i < dreamList.size(); i++)
    {

        if(dreamList[i] == stadiumName)
        {
            dreamList.Delete(stadiumName);
            return;
        }
    }
}

/*******************************************************************
 * void on_backtoMain_clicked();
 *
 *   Accessor; This method will switch the window to the main
 *             window
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_backtoMain_clicked()
{
    gotoPage("mainMenu");
}

/*******************************************************************
 * void on_showMapButton_clicked();
 *
 *   Accessor; This method will switch the window to the map page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_showMapButton_clicked()
{
    loadMap(g, &newStadiumaAddedbyUser);

    ui->mapLegend->show();
    gotoPage("GeneralMap");
}

/*******************************************************************
 * void on_showPathViewerBtn_clicked();
 *
 *   Accessor; This method will switch the window to the single
 *     path viewer page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_showPathViewerBtn_clicked()
{
    int i = 0;

    ui->pathViewCombo_1->clear();
    ui->pathViewCombo_2->clear();

    for(int i = 0; i < g.stadiums.size(); i++)
    {
        ui->pathViewCombo_1->insertItem(i, QString::fromStdString(g.stadiums[i].getStadiumName()));
        ui->pathViewCombo_2->insertItem(i, QString::fromStdString(g.stadiums[i].getStadiumName()));
    }

    paint2.end();
    paint2.eraseRect(0,0, 640, 416);

    img2.load("textFiles/map.png");
    img2 = img2.scaled(ui->pathMap->geometry().width(), ui->pathMap->geometry().height());
    paint2.begin(&img2);

    ui->pathMap->setPixmap(img2);

    gotoPage("PathViewer");
}

/*******************************************************************
 * void on_pushButton_5_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to track souvenirs page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_5_clicked()
{
    // load table of souvenirs - s
    ui->souvenirListForAdd->setRowCount(0);
    loadSouvenirTable1();

    gotoPage("TrackSouvenirAdd");
}

/*******************************************************************
 * void on_back_clicked();
 *
 *   Accessor; This method will switch the window to the main window
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

/*******************************************************************
 * void on_showMapButtonMainPage_clicked();
 *
 *   Accessor; This method will switch the window from the main
 *             window to the general map page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_showMapButtonMainPage_clicked()
{
    loadMap(g);

    ui->mapLegend->show();
    gotoPage("GeneralMap");
}

/*******************************************************************
 * void on_DoneButton2_clicked();
 *
 *   Accessor; This method will switch the window to the welcome
 *             page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_DoneButton2_clicked()
{
    loadStadiumTable2();

    ui->mapLegend->hide();
    gotoPage("custWelcomePage");
}

/*******************************************************************
 * void on_pathView_DoneButton_clicked();
 *
 *   Accessor; This method will switch the window to the welcome
 *             page
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pathView_DoneButton_clicked()
{
    loadStadiumTable2();
    gotoPage("custWelcomePage");
}

/*******************************************************************
 * void on_pathViewCombo_1_currentIndexChanged(int);
 *
 *   Accessor; This method will handle when the index of the
 *             path view combobox changes, updating the map
 *------------------------------------------------------------------
 *   Parameter: new index of the combobox (int)
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pathViewCombo_1_currentIndexChanged(int index)
{
    update_path_view();
}

/*******************************************************************
 * void on_pathViewCombo_2_currentIndexChanged(int);
 *
 *   Accessor; This method will handle when the index of the
 *             path view combobox changes, updating the map
 *------------------------------------------------------------------
 *   Parameter: new index of the combobox (int)
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pathViewCombo_2_currentIndexChanged(int index)
{
    update_path_view();
}

/*******************************************************************
 * void on_modSouvenir_doneButton_clicked();
 *
 *   Accessor; This method will save any changes made to souvenirs.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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
    err = false;
}

/*******************************************************************
 * void on_modSouvenir_addButton_clicked();
 *
 *   Accessor; This method will allow the user to add a new souvenir.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_modSouvenir_addButton_clicked()
{
    souvenir _s;

    s.addSouvenir(_s);
    ui->modSouvenir_table->insertRow(ui->modSouvenir_table->rowCount());
    ui->modSouvenir_table->scrollToBottom();
}

/*******************************************************************
 * void on_modSouvenir_table_itemChanged(QTableWidgetItem*);
 *
 *   Accessor; This method will update the souvenir if it is edited
 *------------------------------------------------------------------
 *   Parameter: QTableWidgetItem* // IN - table item that is edited
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

        if(err && s.getIndex(item->text().toStdString()) != -1){
            QMessageBox::warning(this, "Warning", "Souvenir already exists");
            item->setText("");
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

/*******************************************************************
 * void on_souvenirListForAdd_itemDoubleClicked(QTableWidgetItem* item);
 *
 *   Accessor; This method will allow the user to purchase a new
 *             souvenir from a table of souvenirs.
 *------------------------------------------------------------------
 *   Parameter: item (QTableWidgetItem*) // IN - item that was clicked
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

/*******************************************************************
 * void on_allStadiums_itemDoubleClicked(QTableWidgetItem *item);
 *
 *   Accessor; This method will allow the user to see all stadium
 *             info from a table of stadiums
 *------------------------------------------------------------------
 *   Parameter: item (QTableWidgetItem*) // IN - cell that was clicked
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_allStadiums_itemDoubleClicked(QTableWidgetItem *item)
{
    std::string name = item->text().toStdString();
    planTeamButtons(name);
}

/*******************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will set the x and y coordinates for a
 *             new stadium
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_submit_clicked()
{
    stadium s;
    s.setXCoor(ui->Xcord->value());
    s.setYCoor(ui->Ycord->value());
    g.addStadium(s);

    ui->Xcord->hide();
    ui->Xcord->clear();
    ui->xLabel->hide();
    ui->Ycord->hide();
    ui->Ycord->clear();
    ui->yLabel->hide();
    ui->submit->hide();

    ui->modificationTable->insertRow(ui->modificationTable->rowCount());
    ui->modificationTable->scrollToBottom();
}

/*******************************************************************
 * void on_modificationTable_itemChanged(QTableWidgetItem *item);
 *
 *   Accessor; This method will allow the user to edit a souvenir.
 *------------------------------------------------------------------
 *   Parameter: item (QTableWidgetItemm*) // IN - item that was edited
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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
        for(int i = 0; i < g.stadiums.size(); i++){
            if(err && g.stadiums[i].getStadiumName() == item->text().toStdString()){
                QMessageBox::warning(this, "Warning", "Stadium name already taken");
                item->setText("");
                return;
            }
        }
        g.stadiums[i].setName(item->text().toStdString());
    } else if(i == 1){ // edit team name
        i = item->row();
        for(int i = 0; i < g.stadiums.size(); i++){
            if(err && g.stadiums[i].getTeamName() == item->text().toStdString()){
                QMessageBox::warning(this, "Warning", "Team already has a stadium");
                item->setText("");
                return;
            }
        }
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
        i = item->row();
        g.stadiums[i].setType(item->text().toStdString());
    }
}

/*******************************************************************
 * void on_GrassSurface_currentIndexChanged(int index);
 *
 *   Accessor; This method will allow the user to toggle between
 *             sorting the stadiums by team name, stadium name,
 *             surface type, founding date, and team type
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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
        temp.sort(date);
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
        ui->tableWidget_2->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(temp[i].getType())));
    }
}

/*******************************************************************
 * void on_allALStadiumsButton_clicked();
 *
 *   Accessor; This method will load a map that visits all American
 *             League stadiums.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_allALStadiumsButton_clicked()
{
    List<stadium> al = g.getAmericanLeagueStadiums();

    loadMap(g, &al);
    ui->mapLegend->show();
    gotoPage("GeneralMap");
}

/*******************************************************************
 * void on_allNLStadiumsButton_clicked();
 *
 *   Accessor; This method will load a map that visits all National
 *             League stadiums.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_allNLStadiumsButton_clicked()
{
    List<stadium> nl = g.getNationalLeagueStadiums();

    loadMap(g, &nl);
    ui->mapLegend->show();
    gotoPage("GeneralMap");
}

/*******************************************************************
 * void on_allStadiumsButton_clicked();
 *
 *   Accessor; This method will load a map that visits all MLB
 *             stadiums.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_allStadiumsButton_clicked()
{
    loadMap(g, &g.stadiums);
    ui->mapLegend->show();
    gotoPage("GeneralMap");
}

/*******************************************************************
 * void on_pushButton_2_clicked();
 *
 *   Accessor; This method will load the information of a random
 *             stadium.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    srand(time(NULL));

    int random;
    random = rand()%g.stadiums.size();

    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getStadiumName()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getTeamName()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getAddress()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getAddress2()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getPhone()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getOpenDate()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getCapacity()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getType()));
    ui->listWidget->addItem(QString::fromStdString(g.stadiums[random].getFieldSurface()));
}

/*******************************************************************
 * void on_adminPg_goto_modSouvenirPg_2_clicked();
 *
 *   Accessor; This method will switch the page to the modify
 *             souvenirs page.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_adminPg_goto_modSouvenirPg_2_clicked()
{
    for(int i = 0; i < g.stadiums.size(); i++)
    {
        ui->stadium1->insertItem(i, QString::fromStdString(g.stadiums[i].getStadiumName()));
        ui->stadium2->insertItem(i, QString::fromStdString(g.stadiums[i].getStadiumName()));
    }

    ui->stadium1->hide();
    ui->stadium2->hide();
    ui->distance_2->hide();
    ui->xCo_label->hide();
    ui->yCo_label->hide();
    ui->xCo->hide();
    ui->yCo->hide();
    ui->distLabel->hide();
    ui->submit_2->hide();
    ui->editEdge->show();
    ui->editLoc->show();

    gotoPage("modifyLocation");
}

/*******************************************************************
 * void on_pushButton_3_clicked();
 *
 *   Accessor; This method will switch the page to the previous
 *             page, admin console.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_pushButton_3_clicked()
{
    gotoPage("adminWelcomePg");
}

/*******************************************************************
 * void on_editLoc_clicked();
 *
 *   Accessor; This method will allow the user to change the location
 *             of a stadium.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_editLoc_clicked()
{
    ui->stadium1->show();
    ui->stadium2->hide();
    ui->distLabel->hide();
    ui->distance_2->hide();
    ui->xCo_label->show();
    ui->yCo_label->show();
    ui->xCo->show();
    ui->yCo->show();
    ui->submit_2->show();
}

/*******************************************************************
 * void on_editEdge_clicked();
 *
 *   Accessor; This method will allow the user to add new edges
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_editEdge_clicked()
{
    ui->stadium1->show();
    ui->stadium2->show();
    ui->distLabel->show();
    ui->distance_2->show();
    ui->submit_2->show();
}

/*******************************************************************
 * void on_submit_2_clicked();
 *
 *   Accessor; This method will finalize any changes made by the
 *             user to location or edges.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void MainWindow::on_submit_2_clicked()
{
    // editing location of 1 stadium
    if(ui->stadium2->isHidden()){
        QString sName = ui->stadium1->currentText();
        int xCo = ui->xCo->value();
        int yCo = ui->yCo->value();
        for(int i = 0; i < g.stadiums.size(); i++){
            if(g.stadiums[i].getStadiumName() == sName.toStdString()){

                g.stadiums[i].setXCoor(xCo);
                g.stadiums[i].setYCoor(yCo);
                break;
            }
        }
    }
    // adding edges
    else{
        QString sName = ui->stadium1->currentText();
        QString sName2 = ui->stadium2->currentText();
        int distance = ui->distance_2->value();
        stadium src;
        stadium des;
        for(int i = 0; i < g.stadiums.size(); i++){
            if(g.stadiums[i].getStadiumName() == sName.toStdString()){
                src = g.stadiums[i];
            }
            else if(g.stadiums[i].getStadiumName() == sName2.toStdString()){
                des = g.stadiums[i];
            }
        }
        if(g.getedge(src, des) != nullptr){
            QMessageBox::warning(this, "Warning", "Edge already exists");
            return;
        }

        g.addEdge(src, des, distance);
        g.addEdge(des, src, distance);
    }

    ui->stadium1->hide();
    ui->stadium2->hide();
    ui->distance_2->hide();
    ui->xCo_label->hide();
    ui->yCo_label->hide();
    ui->xCo->hide();
    ui->yCo->hide();
    ui->distLabel->hide();
    ui->submit_2->hide();
    ui->editEdge->show();
    ui->editLoc->show();
    ui->pushButton_3->show();
}
