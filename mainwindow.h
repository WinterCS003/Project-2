#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include "souvenir.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <vector>
#include <string>
#include <map>

#include <QPixmap>
#include <QPainter>
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct userInfo
{
    List<stadiumNode> plannedTrips;     //ATT - all trips
    souvenirs souvenirList;             //ATT - assoc. souvenirs
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void gotoPage(string pg);      //IN - page to switch to

private slots:
    void loadMap(graph g);

    void on_exitMainButton_clicked();

    void on_customerPushButtonMenu_clicked();

    void on_customerDoneButton_clicked();

    void on_mapPgDoneButton_clicked();

    void on_adminPgDoneButton_clicked();

    void on_adminPushButtonMain_clicked();

    void on_souvenirsDoneButton_clicked();

    void on_stadiumInfoDoneButton_clicked();


    void setStadiumTextBrowser(string stadiumTemp); //IN - stadium to add

    void on_stadiumsByNameButton_clicked();

    void on_stadiumTableInfo_clicked();


    void on_GrassSurface_currentIndexChanged();



    void on_planTripButton_clicked();


    void on_pushButton_31_clicked();

    void on_allStadiumsButton_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_clicked();

    void on_adminPg_goto_modSouvenirPg_clicked();

    void on_modAddNewButton_clicked();

    void on_modStadium_doneButton_clicked();

    void on_gobacktomainpage_clicked();


    void on_stadiumTable_clicked();

    void planTeamButtons(string stadiumName);

    void on_stadiumInfoCheckBox_stateChanged(int arg1); //IN - *placehold*

    void on_restartDreamList_clicked();

    void on_allNLStadiumsButton_clicked();


    void on_allALStadiumsButton_clicked();


    void on_backtoMain_clicked();


    void on_showMapButton_clicked();


    void plannedTripTable();

    List<stadium> modify_newStadiumAddedByUser(List<stadium> list);

    bool isNewStadium(stadium);

    void on_pushButton_5_clicked();

    void on_showMapButtonMainPage_clicked();

    void on_DoneButton2_clicked();

    // modSouvenirTable
    void on_modSouvenir_doneButton_clicked();

    void on_modSouvenir_addButton_clicked();

    void on_modSouvenir_table_itemChanged(QTableWidgetItem*);

    void on_souvenirListForAdd_itemDoubleClicked(QTableWidgetItem *item);

    void on_back_clicked();

    void on_allStadiums_itemDoubleClicked(QTableWidgetItem *item);

    void on_modificationTable_itemChanged(QTableWidgetItem *item);

    void on_GrassSurface_currentIndexChanged(int index);

    static bool TeamName(node<stadium>& s1, node<stadium>& s2);

    static bool StadiumName(node<stadium>& s1, node<stadium>& s2);

    static bool Date(node<stadium>& s1, node<stadium>& s2);


private:
    Ui::MainWindow *ui;     // ATT - main ui window

    QPixmap img;
    QPainter paint;
    QPen red;
    QPen yellow;
    QPen line;

    QString getDreamStrArray();
    QString stadiumPathText = "";   // ATT - text to display path
    QString arrow = " --> \n";      // ATT - arrow for output
    string strArrow = " --> \n";    // ATT - arrow for output

    List<string> dreamList;       // ATT - list of stadiums in trip

    void clearDreamList();
    bool alreadyInDreamList(string stadiumName);    //IN - stadium name to chck

    void deleteDreamStadium(string stadiumName);    //IN - stadium to del

    map<string, QWidget*> pageMap;       // ATT - map of page numbers by QWidget name

    graph g;

    souvenirs s;
    souvenirs purchases;

    userInfo client;

    List<stadium> newStadiumaAddedbyUser;
    List<stadium> getStadiumListALL();
};
#endif // MAINWINDOW_H
