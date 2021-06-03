/******************************************************************
 * AUTHORS   : Nathan Cheung, Xinming Fu, Jaemok C. Lee
 * PROJECT 2 : I Love Baseball
 * CLASS     : CS 008 Data Structures
 * SECTION   : 6:30-8:35pm
 * DUE DATE  : 06/02/2021
 ******************************************************************/
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;
/************************************************************
*
* Baseball Planner
*___________________________________________________________
* This program allows the user to keep track of their trip
* visiting baseball stadiums.
*___________________________________________________________
* INPUTS:
*   Stadiums
*   Edges between stadiums
*   Souvenirs
*
* OUTPUTS:
*   Map and other data involving the baseball planner.
*************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
