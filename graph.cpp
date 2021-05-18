#include "graph.h"
#include <vector>

graph::graph(){
    adjList = new List<stadiumNode>[30];
    _capacity = 0;
    _size = 30;
}

graph::~graph(){}

stadium graph::getStadiumInfo(string stadiumName){
    for(node<stadium>* curr = stadiums.Begin(); curr != nullptr ;curr = curr->_next){
        if(curr->_data.getStadiumName() == stadiumName){
            return curr->_data;
        }
    }
        throw "NOT FOUND";
//    return stadiums.Search(stadiumName)->_data;
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
    return adjList[index];
}

void graph::addStadium(stadium s){
    if(_capacity == _size){
        List<stadiumNode>* temp = new List<stadiumNode>[2*_size];
        for(int i = 0; i < _size; i++){
            temp[i] = adjList[i];
        }

        for(int i = 0; i < _capacity; i++){
            adjList[i].~List();
        }
        delete [] adjList;

        adjList = temp;
        _size = 2*_size;
    }

    stadiums.append(s);
    _capacity++;
}

void graph::addEdge(stadium src, stadium des, int distance){
    int index = stadiums.find(src);
    stadiumNode temp(des, distance);
    adjList[index].append(temp);

    // make sure is non-directed
    index = stadiums.find(des);
    temp._des = src;
    adjList[index].append(temp);
}

int graph::getSize(){
    return _capacity;
}

List<stadium> graph::getStadiumWithGrassField(){
    List<stadium> output;
    for(int i = 0; i < _capacity; i++){
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
    for(int i = 0; i < _capacity; i++){
        if(stadiums[i].getType() == "American League"){
            output.append(stadiums[i]);
        }
    }

    return output;
}

List<stadium> graph::getNationalLeagueStadiums(){
    List<stadium> output;
    for(int i = 0; i < _capacity; i++){
        if(stadiums[i].getType() == "National League"){
            output.append(stadiums[i]);
        }
    }

    return output;
}

int graph::getLength(List<stadiumNode> l){

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

void graph::removeEdge(stadiumNode toRemove){

}

void graph::removeStadium(stadium toRemove){
    int index = stadiums.find(toRemove);
    stadiums.Delete(toRemove);
    _capacity--;

    for(int i = index; i < _capacity; i++){
        adjList[i] = adjList[i+1];
    }

    for(int i = 0; i < _capacity; i++){
        for(node<stadiumNode>* curr = adjList[i].Begin(); curr->_next != nullptr; curr = curr->_next){
            if(curr->_next->_data == toRemove){
                node<stadiumNode>* temp = curr->_next;
                curr = temp->_next;
                delete temp;
            }
        }
    }
}
