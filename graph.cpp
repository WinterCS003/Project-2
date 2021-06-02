#include "graph.h"

/****************************************************************
 * graph();
 *   Constructor; Initializes an empty class
 *   Parameters: none
 *   Return: none
 ***************************************************************/
graph::graph(){
    _size = 0;
}

/****************************************************************
 * ~graph();
 *   Destructor; Frees all memory used by the stadiums and
 *               adjacency list.
 *   Parameters: none
 *   Return: none
 ***************************************************************/
graph::~graph(){
    for(int i = 0; i < _size; i++){
        adjList[i].clear();
    }
    adjList.clear();
}

/****************************************************************
 * stadium getStadiumInfo(stadium s) const;
 *
 *   Accessor; This method will search the attribute stadiums
 *             to see if the stadium exists. If it does, then
 *             the stadium is returned.
 * --------------------------------------------------------------
 *   Parameters: s (stadium) // IN - stadium to search for
 * --------------------------------------------------------------
 *   Return: age (int)
 ***************************************************************/
stadium graph::getStadiumInfo(stadium s) const{
    return stadiums.Search(s)->_data;
}

/****************************************************************
 * stadiumNode * getedge(stadium stadiumSrc,
 *                     stadium stadiumDes);
 *
 *   Accessor; This method will return the edge that connects
 *             the two given stadiums
 * --------------------------------------------------------------
 *   Parameters: stadiumSrc (stadium) // IN - source stadium
 *               stadiumDes (stadium) // IN - destination stadium
 * --------------------------------------------------------------
 *   Return: stadiumNode - returns pointer to edge,
 *     nullptr if not found
 ***************************************************************/
stadiumNode * graph::getedge(stadium stadiumSrc, stadium stadiumDes){
    int index = stadiums.find(stadiumSrc);
    for(int i = 0; i < adjList[index].size(); i++){
        if(adjList[index][i]._des == stadiumDes){
            return &adjList[index][i];
        }
    }
    return nullptr;
}

/****************************************************************
 * List<stadiumNode> getedges(stadium stadiumSrc);
 *
 *   Accessor; This method will return a list of all stadiums
 *             connected to the given source stadium.
 * --------------------------------------------------------------
 *   Parameters: stadiumSrc (stadium) // IN - source stadium
 * --------------------------------------------------------------
 *   Return: List<stadiumNode> - all edge connected to the given
 *                               stadium.
 ***************************************************************/
List<stadiumNode> graph::getedges(stadium stadiumSrc){
    int index = stadiums.find(stadiumSrc);
    if(index == -1){
        throw "Does not exist";
    }

    return adjList[index];
}

/*******************************************************************
 * void addStadium(stadium s);
 *
 *   Mutator; This method will add the given stadium into the graph
 *------------------------------------------------------------------
 *   Parameter: s (stadium) // IN – new stadium to add
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void graph::addStadium(stadium s){
    List<stadiumNode> l;
    adjList.append(l);
    stadiums.append(s);
    _size++;
}

/*******************************************************************
 * void addEdge(stadium src
 *              stadium des,
 *              int distance);
 *
 *   Mutator; This method will add a new edge that connects the
 *            src stadium to the des stadium with the given distance.
 *------------------------------------------------------------------
 *   Parameter: src (stadium)  // IN – source stadium
 *              des (stadium)  // IN - destination stadium
 *              distance (int) // IN - distance between stadiums
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void graph::addEdge(stadium src, stadium des, int distance){
    int i;
    int index = stadiums.find(src);
    stadiumNode temp(src, des, distance);

    // Skip already exiting
    for(i = 0; i < adjList[index].size(); i++)
        if(adjList[index][i]._des == des)
            break;
    if(i == adjList[index].size())
        adjList[index].append(temp);

    // Add reverse of edge, skip already exiting
    stadiumNode temp2(des, src, distance);
    for(i = 0; i < adjList[index].size(); i++)
        if(adjList[index][i]._des == src)
            break;
    if(i == adjList[index].size())
        adjList[index].append(temp2);
}

/****************************************************************
 * stadium* getStadiumByName(string name);
 *
 *   Accessor; This method will return a stadium with the given
 *             stadium name.
 * --------------------------------------------------------------
 *   Parameters: name (string) // IN - stadium name to search for
 * --------------------------------------------------------------
 *   Return: stadium* - pointer to stadium with the given name
 ***************************************************************/
stadium* graph::getStadiumByName(string name)
{
    size_t i;

    for(i = 0; i < stadiums.size(); i++)
        if(stadiums[i].getStadiumName() == name)
            return &stadiums[i];

    return nullptr;
}

/****************************************************************
 * List<stadium> getStadiumWithGrassField();
 *
 *   Accessor; This method will return a List of all stadiums
 *             with a grass field.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: List<stadium> - list of all grass surface stadiums
 ***************************************************************/
List<stadium> graph::getStadiumWithGrassField(){
    List<stadium> output;
    for(int i = 0; i < _size; i++){
        if(stadiums[i].getFieldSurface() == "Grass"){
            output.append(stadiums[i]);
        }
    }

    return output;
}

/****************************************************************
 * List<stadium> getAmericanLeagueStadiums();
 *
 *   Accessor; This method will return a List of all american
 *             league stadiums.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: List<stadium> - list of all american league stadiums
 ***************************************************************/
List<stadium> graph::getAmericanLeagueStadiums(){
    stadium temp;

    List<stadium> output;
    for(int i = 0; i < _size; i++){
        if(stadiums[i].getType() == "American League"){
            output.append(stadiums[i]);
            if(i > 0 && stadiums[i].getStadiumName() == "Angels Stadium of Anaheim")
            {
                temp = stadiums[0];
                stadiums[0] = stadiums[i];
                stadiums[i] = temp;
            }
        }
    }

    return output;
}

/****************************************************************
 * List<stadium> getNationalLeagueStadiums();
 *
 *   Accessor; This method will return a List of all national
 *             league stadiums.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: List<stadium> - list of all national league stadiums
 ***************************************************************/
List<stadium> graph::getNationalLeagueStadiums(){
    stadium temp;

    List<stadium> output;
    for(int i = 0; i < _size; i++){
        if(stadiums[i].getType() == "National League"){
            output.append(stadiums[i]);
            if(i > 0 && stadiums[i].getStadiumName() == "AT&T Park")
            {
                temp = stadiums[0];
                stadiums[0] = stadiums[i];
                stadiums[i] = temp;
            }
        }
    }

    return output;
}

/*******************************************************************
 * void removeEdge(stadium src,
 *                 stadium des);
 *
 *   Mutator; This method will remove the edge between the given
 *            src and des stadiums.
 *------------------------------------------------------------------
 *   Parameter: src (stadium) // IN – source stadium
 *              des (stadium) // IN - destination stadium
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

/*******************************************************************
 * void removeStadium(stadium toRemove);
 *
 *   Mutator; This method will remove the given stadium and all edges
 *            associated with it.
 *------------------------------------------------------------------
 *   Parameter: toRemove (stadium) // IN – stadium to remove
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
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

/****************************************************************
 * void getShortestTripPath(int *total_path,
 *                          int& total_path_used,
 *                          List<stadium>& targets,
 *                          int& total_distance);
 *
 *   Accessor; This method will return the shortest path
 *             connecting all nodes in the graph.
 * --------------------------------------------------------------
 *   Parameters: int *total_path        // IN - array of stadiums
 *                                              visited in order
 *               int& total_path_used   // IN - number of stadiums
 *                                              visited
 *               List<stadium>& targets // IN - stadiums to visit
 *               int& total_distance    // IN - total distance
 *                                              traveled
 * --------------------------------------------------------------
 *   Return: none - parameters are updated after running function
 ***************************************************************/
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
        std::cout << "total: " << total_distance << "\n";
    }

    for(i = 0; i < total_path_used; i++)
    {
        std::cout << "Visit: " << stadiums[total_path[i]] << "\n";
    }
    std::cout << "- Total Distance: " << total_distance << "\n";
}

/****************************************************************
 * int getIndex(stadium& target);
 *
 *   Accessor; This method will return the index of the
 *             target stadium if it exists in the graph.
 * --------------------------------------------------------------
 *   Parameters: target (stadium&) // IN - stadium to search for
 * --------------------------------------------------------------
 *   Return: int - index of stadium in list, -1 if it is not
 *                 found in list.
 ***************************************************************/
int graph::getIndex(stadium& target)
{
    int i;

    for(i = 0; i < stadiums.size(); i++)
        if(stadiums[i].getStadiumName() == target.getStadiumName())
            return i;

    return -1;
}

/****************************************************************
 * void graph::dijkstras(int *path,
 *                      int& nodes_visited,
 *                      int& dis,
 *                      int src,
 *                      int *unused_targets,
 *                      int unused_targets_size);
 *
 *   Accessor; This method will use dijkstra's algorithm to
 *             return the shortest path from the source node
 *             to all adjacent nodes
 * --------------------------------------------------------------
 *   Parameters: int *path               // IN/OUT - array to
 *                                                   write to
 *               int& nodes_visited      // OUT - how many nodes
 *                                                visited
 *               int& dis                // OUT - total distance
 *               int src                 // IN - starting index
 *               int *unused_targets     // IN - index of unused
 *                                               targets
 *               int unused_targets_size // IN - number of unused
 *                                               targets
 * --------------------------------------------------------------
 *   Return: none - parameters are updated after function is
 *                  executed
 ***************************************************************/
void graph::dijkstras(int *path,               // IN/OUT - array to write to
                      int& nodes_visited,      // OUT - how many nodes visited
                      int& dis,                // OUT - total distance
                      int src,                 // IN - starting index
                      int *unused_targets,     // IN - index of unused targets
                      int unused_targets_size) // IN - number of unused targets
{
    int max = stadiums.size();
    int infinity = 1000000000;

    int cost[max][max],distances[max],prev[max];
    int count = -1;
    int min = -1;
    int nextnode = -1;
    int i = -1;
    int j = -1;
    bool visited[max];

    for(i=0;i<max;i++)
    {
        for(j = 0; j < max; j++)
            cost[i][j] = infinity;
        for(j = 0; j < adjList[i].size(); j++)
        {
            int index = getIndex(adjList[i][j]._des);
            cost[i][index] = adjList[i][j]._distance;
        }
        distances[i] = cost[src][i];
        prev[i] = src;
        visited[i] = false;
    }

    distances[src] = 0;
    visited[src] = true;

    for(count = 0; count < max-1; count++)
    {
        min=infinity;
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
    }

    // Find minimum path to next trip node
    int min_i = -1;
    int min_j = -1;
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
