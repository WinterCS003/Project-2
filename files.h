
#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, List<stadium>& list, std::string fileName){
    std::cout << "Stadium" << std::endl;
    ifstream input(fileName);
    bool AL = false;
    if(input.is_open()){
        std::string line;
        int i = 0;
        stadium temp;
        while(std::getline(input, line)){
            if(line == "AMERICAN LEAGUE TEAMS:"){
                AL = true;
                i -= 2;
            } else if(line == "NATIONAL LEAGUE TEAMS:"){
                AL = false;
                i -= 2;
            } else{
                switch(i){
                case 0:
                    temp.setName(line);
                    break;
                case 1:
                    temp.setTeamName(line);
                    break;
                case 2:
                    temp.setAddress(line);
                    break;
                case 3:
                    break;
                case 4:
                    temp.setphone(line);
                    break;
                case 5:
                    std::cout << line << std::endl;
                    line = line.substr(line.find('-')+2);
                    temp.setOpenDate(line);
                    break;
                case 6:
                    std::cout << line << std::endl;
                    line = line.substr(line.find('-')+2);
                    temp.setCapacity(line);
                    if(AL){
                        temp.setType("American League");
                    } else{
                        temp.setType("National League");
                    }
                    g.addStadium(temp);
                    i = -2;
                }
            }
            i++;
        }
    }
}

void readEdges(graph &g,                        // IN - graph object
               std::string fileName){                // IN - name of stadium file
    std::cout << "EDGES " << std::endl;
    std::ifstream input(fileName);
    std::string line;
    if(input.is_open()){
        while(std::getline(input, line)){
            std::string s = line.substr(0, line.find(','));
            stadium source = g.getStadiumInfo(s);

            s = line.substr(line.find(',')+2, line.find_last_of(',') - line.find(',') - 2);
            stadium des = g.getStadiumInfo(s);

            s = line.substr(line.find_last_of(',')+2);
            int d = std::stoi(s);
            g.addEdge(source, des, d);
        }
    }
    input.close();
}


void readSouvenirs(souvenirs& s,            // IN & OUT - souvenir object
                   std::string fileName){        // IN - name of file
    std::string line;
    ifstream input(fileName);
    if(input.is_open()){
        while(std::getline(input, line)){
            // line should be: "name, $xx.xx, quantity"
            //                 "description"
            souvenir temp;
            temp.setName(line.substr(0, line.find(',')));
            temp.setPrice(line.substr(line.find('$')+1, line.find_last_of(',')-line.find('$')-1));

             std::string quantity = line.substr(line.find_last_of(',')+2);
            temp.setQuantity(std::stoi(quantity));

            if(std::getline(input, line))
                temp.setDescription(line);

            s.addSouvenir(temp);
        }

        input.close();
    }
}

void saveStadiums(graph &g, List<stadium>& newS, std::string fileName){

}

void saveSouvenirs(souvenirs& s,        // IN - the souvenirs object to read
                   std::string fileName){    // IN - name of file
    ofstream output(fileName);
    for(int i = 0; i < s.getSize(); i++){
        output << s[i].getName() << ", $" << s[i].getPrice() << ", " << s[i].getQuantity();
        output << "\n" << s[i].getDescription();
        output << "\n";
    }
}

#endif // FILES_H
