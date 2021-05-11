
#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, List<stadium>& list, std::string fileName){

}

void readEdges(graph &g,                        // IN - graph object
               std::string fileName){                // IN - name of stadium file

}


void readSouvenirs(souvenirs& s,            // IN & OUT - souvenir object
                   std::string fileName){        // IN - name of file
    std::string line;
    ifstream input(fileName);
    if(input.is_open()){
        while(std::getline(input, line)){
            souvenir temp;
            temp.setName(line.substr(0, line.find(',')));
            temp.setPrice(line.substr(line.find('$')+1));

            s.addSouvenir(temp);
        }
    }
}

void readSouvenirsPurchases(souvenirs& s,
                            std::string fileName){
    std::string line;
    ifstream input(fileName);
    if(input.is_open()){
        while(std::getline(input, line)){
            std::string name = line.substr(0, line.find(','));
            std::string price = line.substr(line.find('$')+1, ',');
            std::string quantity = line.substr(line.find_last_of(',')+2);

            souvenir temp;
            temp.setName(name);
            temp.setPrice(price);
            temp.setQuantity(std::stoi(quantity));

            s.addSouvenir(temp);
        }
    }
}

void saveStadiums(graph &g, List<stadium>& newS, std::string fileName){

}

void saveSouvenirs(souvenirs& s,        // IN - the souvenirs object to read
                   std::string fileName){    // IN - name of file
    ofstream output(fileName);
    for(int i = 0; i < s.getSize(); i++){
        output << s[i].getName() << ", $" << s[i].getPrice();
        if(s[i].getQuantity() != 0){
            output << ", " << s[i].getQuantity();
        }
        output << "\n";
    }
}

#endif // FILES_H
