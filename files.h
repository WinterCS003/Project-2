
#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, List<stadium>& list, string fileName){

}

void readEdges(graph &g,                        // IN - graph object
               string fileName){                // IN - name of stadium file

}


void readSouvenirs(souvenirs& s,            // IN & OUT - souvenir object
                   string fileName){        // IN - name of file

}

void saveStadiums(graph &g, List<stadium>& newS, string fileName){


}

void saveSouvenirs(souvenirs& s,        // IN - the souvenirs object to read
                   string fileName){    // IN - name of file


}
#endif // FILES_H
