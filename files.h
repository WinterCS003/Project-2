#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <sstream>

#include "graph.h"
#include "souvenir.h"

/**********************************************************
 *
 * FUNCTION readStadiums
 *_________________________________________________________
 * This function receives a graph and a file name and
 * reads all stadiums found in the given file name into the
 * graph
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to read
 *     g: graph              // IN - graph to initialize
 *
 * POST-CONDITIONS
 *     This function will initialize the graph to have all
 *     stadiums found in the file.
 ***********************************************************/
void readStadiums(graph &g,             // IN - graph to initialize
                  std::string fileName) // IN - file to read
{
    std::ifstream input(fileName);
    bool AL = false;

    if(input.is_open()){
        std::string line;
        int i = 0;
        stadium temp;
        while(std::getline(input, line)){
            if(line == "AMERICAN LEAGUE TEAMS:"){
                std::getline(input, line);
                AL = true;
                i -= 1;
            } else if(line == "NATIONAL LEAGUE TEAMS:"){
                std::getline(input, line);
                AL = false;
                i -= 1;
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
                    break;
                case 7:
                    line = line.substr(line.find('-')+2);
                    temp.setFieldSurface(line);
                    break;
                case 8:
                    int x = std::stoi(line.substr(line.find(':')+2, line.find(',') - line.find(':')-2));
                    int y = std::stoi(line.substr(line.find(',')+2));
                    temp.setXCoor(x);
                    temp.setYCoor(y);
                    g.addStadium(temp);
                    i = -2;
                }
            }
            i++;
        }
    }

    input.close();
}

/**********************************************************
 *
 * FUNCTION readDreamStadiums
 *_________________________________________________________
 * This function receives a List of stadiumsand a file name
 * and reads all stadiums found in the given file name into
 * the list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to read
 *     dream: List<stadium>  // IN - List to initialize
 *
 * POST-CONDITIONS
 *     This function will initialize the List to have all
 *     custom stadiums found in the file.
 ***********************************************************/
void readDreamStadiums(List<stadium>& dream, // IN - List of stadiums
                       std::string fileName) // IN - file to read
{
    std::ifstream input(fileName);
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
                case 7:
                    line = line.substr(line.find('-')+2);
                    temp.setFieldSurface(line);
                    break;
                case 8:
                    int x = std::stoi(line.substr(line.find(':')+2, line.find(',') - line.find(':')-2));
                    int y = std::stoi(line.substr(line.find(',')+2));
                    temp.setXCoor(x);
                    temp.setYCoor(y);
                    dream.append(temp);
                    i = -2;
                }
            }
            i++;
        }
    }

    input.close();
}

/**********************************************************
 *
 * FUNCTION readEdges
 *_________________________________________________________
 * This function receives a graph and a file name and
 * reads all edges found in the given file name into the
 * graph
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to read
 *     g: graph              // IN - graph to initialize
 *
 * POST-CONDITIONS
 *     This function will initialize the graph to have all
 *     edges found in the file.
 ***********************************************************/
void readEdges(graph &g,             // IN - graph object
               std::string fileName) // IN - name of stadium file
{
    std::cout << "Reading Edges" << std::endl;
    std::ifstream input(fileName);
    std::string line;
    if(input.is_open()){
        while(std::getline(input, line)){
            std::string s = line.substr(0, line.find(','));
            stadium temp;
            temp.setName(s);
            stadium source = g.getStadiumInfo(temp);

            s = line.substr(line.find(',')+2, line.find_last_of(',') - line.find(',') - 2);
            temp.setName(s);
            stadium des = g.getStadiumInfo(temp);

            s = line.substr(line.find_last_of(',')+2);
            int d = std::stoi(s);
            g.addEdge(source, des, d);
        }
    }
    input.close();
}

/**********************************************************
 *
 * FUNCTION readSouvenirs
 *_________________________________________________________
 * This function receives a souvenirs class and a file name.
 * It reads all souvenirs found in the given file name into
 * the souvenirs class
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to read
 *     s: souvenirs          // IN - souvenirs to initialize
 *
 * POST-CONDITIONS
 *     This function will initialize the souvenirs to have all
 *     souvenirs found in the file.
 ***********************************************************/
void readSouvenirs(souvenirs& s,          // IN & OUT - souvenir object
                   std::string fileName){ // IN - name of file
    std::string line;
    std::ifstream input(fileName);
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

/**********************************************************
 *
 * FUNCTION saveDreamStadiums
 *_________________________________________________________
 * This function receives a List of stadiums and a file name.
 * It saves all stadiums found in the given list into the
 * file
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to write
 *     dream: List<stadium>  // IN - stadiums to save
 *
 * POST-CONDITIONS
 *     This function will save all stadiums in the list to
 *     the file.
 ***********************************************************/
void saveDreamStadiums(List<stadium>& dream, // IN - stadiums to save
                       std::string fileName) // IN - file to write
{
    std::ofstream output(fileName);

    if(output.is_open()){
        List<stadium> al;
        for(int i = 0; i < dream.size(); i++){
            if(dream[i].getType() == "American League"){
                al.append(dream[i]);
            }
        }
        output << "AMERICAN LEAGUE TEAMS:\n";
        output << "-----------------------------\n";
        for(int i = 0; i < al.size(); i++){
            output << al[i].getStadiumName() << "\n";
            output << al[i].getTeamName() << "\n";
            output << al[i].getAddress() << "\n";
            output << al[i].getAddress2() << "\n";
            output << al[i].getPhone() << "\n";
            output << "Opened - " << al[i].getOpenDate() << "\n";
            output << "Capacity - " << al[i].getCapacity() << "\n";
            output << "Surface Type - " << al[i].getFieldSurface() << "\n";
            output << "Coordinates: " << al[i].getXCoor() << ", " << al[i].getYCoor() << "\n\n";
        }
        al.clear();
        for(int i = 0; i < dream.size(); i++){
            if(dream[i].getType() == "National League"){
                al.append(dream[i]);
            }
        }
        output << "NATIONAL LEAGUE TEAMS:\n";
        output << "-----------------------------\n";
        for(int i = 0; i < al.size(); i++){
            output << al[i].getStadiumName() << "\n";
            output << al[i].getTeamName() << "\n";
            output << al[i].getAddress() << "\n";
            output << al[i].getAddress2() << "\n";
            output << al[i].getPhone() << "\n";
            output << "Opened - " << al[i].getOpenDate() << "\n";
            output << "Capacity - " << al[i].getCapacity() << "\n";
            output << "Surface Type - " << al[i].getFieldSurface() << "\n";
            output << "Coordinates: " << al[i].getXCoor() << ", " << al[i].getYCoor() << "\n\n";
        }
    }
}

/**********************************************************
 *
 * FUNCTION saveStadiums
 *_________________________________________________________
 * This function receives a graph and a file name.
 * It saves all stadiums found in the given graph into the
 * file
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to write
 *     g: graph&             // IN - stadiums to save
 *
 * POST-CONDITIONS
 *     This function will save all stadiums found in g to
 *     the file
 ***********************************************************/
void saveStadiums(graph &g,             // IN - graph to save
                  std::string fileName) // IN - file to write
{
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
            output << al[i].getAddress2() << "\n";
            output << al[i].getPhone() << "\n";
            output << "Opened - " << al[i].getOpenDate() << "\n";
            output << "Capacity - " << al[i].getCapacity() << "\n";
            output << "Surface Type - " << al[i].getFieldSurface() << "\n";
            output << "Coordinates: " << al[i].getXCoor() << ", " << al[i].getYCoor() << "\n\n";
        }

        List<stadium>nl = g.getNationalLeagueStadiums();
        output << "NATIONAL LEAGUE TEAMS:\n";
        output << "-----------------------------\n";
        for(int i = 0; i < nl.size(); i++){
            output << nl[i].getStadiumName() << "\n";
            output << nl[i].getTeamName() << "\n";
            output << nl[i].getAddress() << "\n";
            output << nl[i].getAddress2() << "\n";
            output << nl[i].getPhone() << "\n";
            output << "Opened - " << nl[i].getOpenDate() << "\n";
            output << "Capacity - " << nl[i].getCapacity() << "\n";
            output << "Surface Type - " << nl[i].getFieldSurface() << "\n";
            output << "Coordinates: " << nl[i].getXCoor() << ", " << nl[i].getYCoor() << "\n\n";
        }
    }

    output.close();
}

/**********************************************************
 *
 * FUNCTION saveEdges
 *_________________________________________________________
 * This function receives a graph and a file name.
 * It saves all edges found in the graph into the
 * file
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to write
 *     g: graph&             // IN - edges to save
 *
 * POST-CONDITIONS
 *     This function will save all edges found in the graph
 *     to the file.
 ***********************************************************/
void saveEdges(graph& g,             // IN - graph to save
               std::string fileName) // IN - file to write
{
    std::ofstream output(fileName);

    if(output.is_open()){
        List<stadium> s;
        s = g.getAmericanLeagueStadiums();
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
        List<stadium> nl;
        nl = g.getNationalLeagueStadiums();
        List<stadiumNode> edges;
        for(int i = 0; i < nl.size(); i++){
            edges = g.getedges(nl[i]);
            source = nl[i].getStadiumName();
            for(int j = 0; j < edges.size(); j++){
                destination = edges[j]._des.getStadiumName();
                distance = edges[j]._distance;
                output << source << ", " << destination << ", " << distance << "\n";
            }
        }
    }
    output.close();
}

/**********************************************************
 *
 * FUNCTION saveSouvenirs
 *_________________________________________________________
 * This function receives a souvenirs object and a file name.
 * It saves all souvenirs found in the given object into the
 * file
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     fileName: std::string // IN - file to write
 *     s: souvenirs&         // IN - souvenirs to save
 *
 * POST-CONDITIONS
 *     This function will save all souvenirs into the file
 ***********************************************************/
void saveSouvenirs(souvenirs& s,        // IN - the souvenirs object to read
                   std::string fileName){    // IN - name of file
    std::ofstream output(fileName);
    for(int i = 0; i < s.getSize(); i++){
        output << s[i].getName() << ", $" << s[i].getPrice() << ", " << s[i].getQuantity();
        output << "\n" << s[i].getDescription();
        output << "\n";
    }

    output.close();
}

#endif // FILES_H
