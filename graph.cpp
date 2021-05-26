#include "graph.h"
#include <vector>

graph::graph(){
    _size = 0;
}

graph::~graph(){
    for(int i = 0; i < _size; i++){
        adjList[i].clear();
    }
    adjList.clear();
}

stadium graph::getStadiumInfo(stadium s){
    return stadiums.Search(s)->_data;
}

stadiumNode graph::getedge(stadium stadiumSrc, stadium stadiumDes){
    int index = stadiums.find(stadiumSrc);
    for(int i = 0; i < adjList[index].size(); i++){
        if(adjList[index][i]._des == stadiumDes){
            return adjList[index][i];
        }
    }
}

List<stadiumNode> graph::getedges(stadium stadiumSrc){
    int index = stadiums.find(stadiumSrc);
    if(index == -1){
        throw "Does not exist";
    }

    return adjList[index];
}

void graph::addStadium(stadium s){
    List<stadiumNode> l;
    adjList.append(l);
    stadiums.append(s);
    _size++;
}

void graph::addEdge(stadium src, stadium des, int distance){
    int index = stadiums.find(src);
    stadiumNode temp(src, des, distance);
    adjList[index].append(temp);
}

int graph::getSize(){
    return _size;
}

List<stadium> graph::getStadiumWithGrassField(){
    List<stadium> output;
    for(int i = 0; i < _size; i++){
        if(stadiums[i].getFieldSurface() == "Grass"){
            output.append(stadiums[i]);
        }
    }

    return output;
}

List<stadium> graph::getStadiumListForDijkstras(){

}

List<stadium> graph::getAmericanLeagueStadiums(){
    List<stadium> output;
    for(int i = 0; i < _size; i++){
        if(stadiums[i].getType() == "American League"){
            output.append(stadiums[i]);
        }
    }

    return output;
}

List<stadium> graph::getNationalLeagueStadiums(){
    List<stadium> output;
    for(int i = 0; i < _size; i++){
        if(stadiums[i].getType() == "National League"){
            output.append(stadiums[i]);
        }
    }

    return output;
}

// returns number of nodes in given list
int graph::getLength(List<stadiumNode> l){
    return l.size();
}

List<stadiumNode> graph::shortestPath(const List<stadium>& stadiumList,
                                      string src){


}

List<stadiumNode> graph::shortestPath(string src,
                                      string des,
                                      const List<stadium>& s){

}

void graph::initForShortestPath(const List<stadium>& list,
                                List<stadiumNode>& result_dijkstras,
                                string src){

}

void graph::checkSingleVertex(List<stadiumNode>& returnMe, string src){

}

bool graph::allVisited(const List<stadiumNode>& me){

}

bool graph::allVisited(const List<stadiumNode>& toCheck,
                       const List<stadium>& stadiumList){


}

bool graph::checkVisited(const List<stadiumNode>& me, string des){

}

stadiumNode graph::getDistance(string des, const List<stadiumNode>& l){

}

void graph::dijkstras(List<stadiumNode>& getsReturned, List<stadiumNode> edges){


}

stadiumNode graph::shortestTotalDistance
                                    (const List<stadiumNode>& result_dijkstras){

}

stadiumNode graph::shortestTotalDistance(const List<stadiumNode>& result_dijkstras,
                                         const List<stadium>& toVisit,
                                         const List<stadiumNode>& visited){

}

bool graph::checkExist(const List<stadiumNode>& list, string toCheck){

}

void graph::removeEdge(stadium src, stadium des){
    int index = stadiums.find(src);
    if(index == -1){
        throw "Source does not exist";
    }
    std::cout << "Removing Edges" << std::endl;
    int i = 0;
    for(node<stadiumNode>* curr = adjList[index].Begin(); curr != nullptr;){
        if(curr->_data._des == des){
            node<stadiumNode>* temp = curr;
            curr->_previous->_next = curr->_next;
            curr->_next->_previous = curr->_previous;

            delete temp;
        }
        curr = curr->_next;
    }

    index = stadiums.find(des);
    if(index == -1){
        throw "Destination does not exist";
    }
    for(node<stadiumNode>* curr = adjList[index].Begin(); curr != nullptr;){
        if(curr->_data._des == src){
            node<stadiumNode>* temp = curr;
            curr->_previous->_next = curr->_next;
            curr->_next->_previous = curr->_previous;
            curr = curr->_next;

            delete temp;
        }
        curr = curr->_next;
    }
}

void graph::removeStadium(stadium toRemove){
    std::cout << "Removing" << std::endl;
    int index = stadiums.find(toRemove);
    if(index == -1){
        throw "Does not exist";
    }

    for(int i = 0; i < _size; i++){
        stadium src = stadiums[i];
        this->removeEdge(src, toRemove);
    }

    adjList.Delete(index);
    stadiums.Delete(toRemove);
    _size--;
}
