#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <string>
#include <map>

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>

#include <QPixmap>
#include <QPainter>
#include <QPen>

#include "graph.h"
#include "souvenir.h"
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   /********************************
    ** CONSTRUCTOR AND DESTRUCTOR **
    ********************************/
   MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

   void gotoPage(string pg); //IN - page to switch to

private slots:

   void loadMap(graph g, List<stadium>* custom = nullptr);

   void update_path_view();

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

   void on_planTripButton_clicked();

   void on_pushButton_31_clicked();

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

   void on_backtoMain_clicked();

   void on_showMapButton_clicked();

   void on_showPathViewerBtn_clicked();

   void on_pushButton_5_clicked();

   void on_showMapButtonMainPage_clicked();

   void on_DoneButton2_clicked();

   void on_pathView_DoneButton_clicked();

   void on_pathViewCombo_1_currentIndexChanged(int);

   void on_pathViewCombo_2_currentIndexChanged(int);

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

   static bool date(node<stadium>& s1, node<stadium>& s2);

   void on_submit_clicked();

   void loadStadiumTable1();

   void loadStadiumTable2();

   void loadStadiumTable3();

   void loadSouvenirTable1();

   void loadSouvenirTable2();

   void on_allALStadiumsButton_clicked();

   void on_allNLStadiumsButton_clicked();

   void on_allStadiumsButton_clicked();

   void on_pushButton_2_clicked();

   void on_adminPg_goto_modSouvenirPg_2_clicked();

   void on_pushButton_3_clicked();

   void on_editLoc_clicked();

   void on_editEdge_clicked();

   void on_submit_2_clicked();
private:
   Ui::MainWindow *ui;     // ATT - main ui window

   QPixmap img;
   QPixmap img2;
   QPainter paint;
   QPainter paint2;
   QPen red;
   QPen yellow;
   QPen line;

   QString stadiumPathText = "";   // ATT - text to display path
   QString arrow = " --> \n";      // ATT - arrow for output
   string strArrow = " --> \n";    // ATT - arrow for output

   List<string> dreamList;       // ATT - list of stadiums in trip

   bool alreadyInDreamList(string stadiumName);    //IN - stadium name to chck

   void deleteDreamStadium(string stadiumName);    //IN - stadium to del

   map<string, QWidget*> pageMap;       // ATT - map of page numbers by QWidget name

   graph g;

   souvenirs s;
   souvenirs purchases;

   List<stadium> newStadiumaAddedbyUser;
   bool err = false;
};
/****************************************************************
* MainWindow Class
*   This class represents a MainWindow object. It is the
*   interface through which the user uses the software.
***************************************************************/


/******************************
** CONSTRUCTOR & DESTRUCTOR **
******************************/

/****************************************************************
* MainWindow(QWidget *parent = nullptr);
*   Constructor; Create a new instance of the window
*   Parameters: parent (QWidget*) // IN - pointer to widget
*   Return: none
***************************************************************/

/****************************************************************
* ~MainWindow();
*   Destructor; Frees any dynamically allocated memory
*   Parameters: none
*   Return: none
***************************************************************/


/***************
 ** ACCESSORS **
 ***************/

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

/*******************************************************************
* void on_customerPushButtonMenu_clicked();
*
*   Accessor; This method will switch the window to the main menu
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
* void on_modAddNewButton_clicked();
*
*   Accessor; This method will allow the user to add a new stadium
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
* void on_gobacktomainpage_clicked();
*
*   Accessor; This method will switch the window to the main window
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
* void on_showMapButton_clicked();
*
*   Accessor; This method will switch the window to the map page
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
* void on_pathViewCombo_1_currentIndexChanged(int);
*
*   Accessor; This method will handle when the index of the
*             path view combobox changes
*------------------------------------------------------------------
*   Parameter: new index of the combobox (int)
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

/*******************************************************************
* void on_pathViewCombo_2_currentIndexChanged(int);
*
*   Accessor; This method will handle when the index of the
*             path view combobox changes
*------------------------------------------------------------------
*   Parameter: new index of the combobox (int)
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

/*******************************************************************
* void on_modSouvenir_doneButton_clicked();
*
*   Accessor; This method will save any changes made to souvenirs.
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

/*******************************************************************
* void on_modSouvenir_addButton_clicked();
*
*   Accessor; This method will allow the user to add a new souvenir.
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

/*******************************************************************
* void on_modSouvenir_table_itemChanged(QTableWidgetItem*);
*
*   Accessor; This method will update the souvenir if it is edited
*------------------------------------------------------------------
*   Parameter: QTableWidgetItem* // IN - table item that is edited
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
* void on_back_clicked();
*
*   Accessor; This method will switch the window to the main window
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
* void on_modificationTable_itemChanged(QTableWidgetItem *item);
*
*   Accessor; This method will allow the user to edit a souvenir.
*------------------------------------------------------------------
*   Parameter: item (QTableWidgetItemm*) // IN - item that was edited
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

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

/*******************************************************************
 * void on_adminPg_goto_modSouvenirPg_2_clicked();
 *
 *   Accessor; This method will switch the page to the modify
 *             location page.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

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

/*******************************************************************
 * void on_editEdge_clicked();
 *
 *   Accessor; This method will allow the user to add new edges
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

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

#endif // MAINWINDOW_H
