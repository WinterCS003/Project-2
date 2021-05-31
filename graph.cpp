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


stadium * graph::getStadiumByName(string name)
{
    size_t i;

    for(i = 0; i < stadiums.size(); i++)
        if(stadiums[i].getStadiumName() == name)
            return &stadiums[i];

    return nullptr;
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

#include <list>

void graph::getShortestTripPath(int *total_path, int& total_path_used, List<stadium> &targets, int& total_distance)
{
    int unused_targets[targets.size() - 1];
    int unused_targets_size;
    int i, j;

    int path[stadiums.size()];
    int nodes_visited;
    int distance;

    if(targets.size() < 2)
        return;

    nodes_visited = 0;

    unused_targets_size = targets.size();
    for(i = 0; i < targets.size(); i++)
        unused_targets[i] = getIndex(targets[i]);
    unused_targets[0] = -1;

    total_distance = 0;
    total_path[0] = getIndex(targets[0]);
    total_path_used = 1;
    for(i = 1; i < targets.size(); i++)
    {
        dijkstras(path, nodes_visited, distance, total_path[total_path_used-1], unused_targets, unused_targets_size);
        for(j = nodes_visited-1; j >= 0; j--)
            total_path[total_path_used++] = path[j];
        total_distance += distance;
    }

    for(i = 0; i < total_path_used; i++)
    {
        std::cout << "Visit: " << stadiums[total_path[i]] << "\n";
    }
    std::cout << "- Total Distance: " << total_distance << "\n";

    /*
    int i, j, targetsUsed;
    int targetsMainIndex[targets.size()];           // cache of target index in main list
    bool targetVisited[targets.size()];          // cache of if target node was already visited
    int path[stadiums.size() * stadiums.size()];    // array of nodes to take, "worst case" size
    int sub_path[stadiums.size()];
    int distances[stadiums.size()];

    // Cache target indices
    for(i = 0; i < targets.size(); i++)
        for(j = 0; j < stadiums.size(); j++)
            if(stadiums[j].getStadiumName() == targets[i].getStadiumName())
            {
                targetsMainIndex[i] = j;
                break;
            }

    path[0] = targetsMainIndex[0];
    targetVisited[0] = true;
    targetsUsed = 1;
    // Loop until path found
    while(targetsUsed < targets.size())
    {
        // Loop through every target, other than main
        for(i = 1; i < targets.size(); i++)
        {
            // Skip if used
            if(targetVisited[i])
                continue;
        }
    }*/
}

int graph::getIndex(stadium& target)
{
    int i;

    for(i = 0; i < stadiums.size(); i++)
        if(stadiums[i].getStadiumName() == target.getStadiumName())
            return i;

    return -1;
}

void graph::dijkstras(int *path,            // IN/OUT - array to write to
                        int& nodes_visited,       // OUT - how many nodes visited
                        int& dis,      // OUT - total distance
                        int src,            // IN - starting index
                        int *unused_targets,
                        int unused_targets_size)
{
    int max = stadiums.size();
    int infinity = 1000000000;

    int cost[max][max],distances[max],prev[max];
    int count,min,nextnode,i,j;
    bool visited[max];

    for(i=0;i<max;i++)
    {
        for(j = 0; j < max; j++)
            cost[i][j] = infinity;
        for(j = 0; j < adjList[i].size(); j++)
        {
            int index = getIndex(adjList[i][j]._des);
            if(index == i)
                index = getIndex(adjList[i][j]._src);
            cost[i][index] = adjList[i][j]._distance;
        }
        distances[i] = cost[src][i];
        prev[i] = src;
        visited[i] = false;
    }

    distances[src] = 0;
    visited[src] = 1;
    count = 1;

    while(count<max-1)
    {
        min=-1;
        for(i=0;i<max;i++)
        {
            if(distances[i] != -1 && (min == -1 || distances[i] < min) && !visited[i])
            {
                min=distances[i];
                nextnode=i;
            }
        }
        visited[nextnode] = true;
        for(i=0;i<max;i++)
        {
            if(!visited[i] && distances[i] != -1 && cost[nextnode][i] != -1 && min + cost[nextnode][i] < distances[i]) {
                distances[i] = min + cost[nextnode][i];
                prev[i] = nextnode;
            }
        }
        count++;
    }

    // Find minimum path to next trip node
    int min_i = -1;
    int min_j;
    for(i = 0; i < max; i++)
    {
        for(j = 0; j < unused_targets_size; j++)
            if(unused_targets[j] == i)
                break;

        // Not found in unused, skip
        if(j == unused_targets_size)
            continue;

        if(min_i == -1 || min > distances[i])
        {
            min = distances[i];
            min_i = i;
            min_j = j;
        }
    }
    unused_targets[min_j] = -1;

    // Add path onto parent
    for(i = 0, j = min_i; i < max && j != src; i++, j=prev[j])
        path[i] = j;
    nodes_visited = i;
    dis = min;
}
