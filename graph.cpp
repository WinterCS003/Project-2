#include "graph.h"
#include <vector>

graph::graph(){}

graph::~graph(){}

stadium graph::getStadiumInfo(string stadiumName){
}

stadiumNode graph::getedge(string stadiumSrc, string stadiumDes){

}

List<stadiumNode> graph::getedges(string stadiumSrc){
}

void graph::addStadium(stadium s){

}

void graph::addEdge(string src, string des, int distance){


}

int graph::getSize(){
    return _size;
}

List<stadium> graph::getStadiumWithGrassField(){

}

List<stadium> graph::getStadiumListForDijkstras(){

}

List<stadium> graph::getAmericanLeagueStadiums(){

}

List<stadium> graph::getNationalLeagueStadiums(){

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

void graph::removeStadium(List<stadiumNode>& list, string toRemove){

}

void graph::removeStadium(List<stadium>& list, string toRemove){

}
