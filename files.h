
#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, std::string fileName){
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
                    temp.setAddress2(line);
                    break;
                case 4:
                    temp.setphone(line);
                    break;
                case 5:
                    line = line.substr(line.find('-')+2);
                    temp.setOpenDate(line);
                    break;
                case 6:
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

void saveStadiums(graph &g, std::string fileName){
    std::ofstream output(fileName);

    if(output.is_open()){
        List<stadium> al;
        al = g.getAmericanLeagueStadiums();
        output << "AMERICAN LEAGUE TEAMS:\n";
        output << "-----------------------------\n";
        for(int i = 0; i < al.size(); i++){
            output << al[i].getStadiumName() << "\n";
            output << al[i].getTeamName() << "\n";
            output << al[i].getAddress() << "\n";
            output << al[i].getPhone() << "\n";
            output << "Opened - " << al[i].getOpenDate() << "\n";
            output << "Capacity - " << al[i].getCapacity() << "\n";
        }

        al = g.getNationalLeagueStadiums();
        output << "NATIONAL LEAGUE TEAMS:\n";
        output << "-----------------------------\n";
        for(int i = 0; i < al.size(); i++){
            output << al[i].getStadiumName() << "\n";
            output << al[i].getTeamName() << "\n";
            output << al[i].getAddress() << "\n";
            output << al[i].getPhone() << "\n";
            output << "Opened - " << al[i].getOpenDate() << "\n";
            output << "Capacity - " << al[i].getCapacity() << "\n";
        }
    }

    output.close();
}

void saveEdges(graph& g, std::string fileName){
    std::ofstream output(fileName);

    if(output.is_open()){
        List<stadium> s = g.getAmericanLeagueStadiums();
        List<stadiumNode> edge;
        std::string source;
        std::string destination;
        int distance;
        for(int i = 0; i < s.size(); i++){
            edge = g.getedges(s[i]);
            source = s[i].getStadiumName();
            for(int j = 0; j < edge.size(); j++){
                destination = edge[j]._des.getStadiumName();
                distance = edge[j]._distance;
                output << source << ", " << destination << ", " << distance << "\n";
            }
        }

        s = g.getNationalLeagueStadiums();
        for(int i = 0; i < s.size(); i++){
            edge = g.getedges(s[i]);
            source = s[i].getStadiumName();
            for(int j = 0; j < edge.size(); j++){
                destination = edge[j]._des.getStadiumName();
                distance = edge[j]._distance;
                output << source << ", " << destination << ", " << distance << "\n";
            }
        }
    }
    output.close();
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
