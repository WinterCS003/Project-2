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
<<<<<<< HEAD
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
                temp = output[0];
                output[0] = output[output.size() - 1];
                output[output.size() - 1] = temp;
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
                temp = output[0];
                output[0] = output[output.size() - 1];
                output[output.size() - 1] = temp;
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
void graph::getShortestTripPath(int *total_path, int& total_path_used, List<stadium> targets, int& total_distance)
{
    int unused_targets[targets.size() - 1]; // Unused targets
    int unused_targets_size;
    int same_positions[targets.size()][2]; // Nodes that have same position on map
    int same_positions_used;
    int i, j, k, l;

    if(targets.size() == 0)
        return;

    total_path[0] = getIndex(targets[0]);
    total_path_used = 1;
    total_distance = 0;

    if(targets.size() == 1)
        return;

    // Populate unused targets
    unused_targets_size = targets.size();
    for(i = 0; i < targets.size(); i++)
        unused_targets[i] = getIndex(targets[i]);

    // Remove second node that has distance=0 with another node, will add back in after
    same_positions_used = 0;
    for(i = unused_targets_size - 1; i > 0; i--)
    {
        for(j = i - 1; j >= 0; j--)
        {
            stadiumNode *edge = getedge(stadiums[unused_targets[i]], stadiums[unused_targets[j]]);
            if(edge == nullptr)
                continue;

            // Handle hold merged data
            if(edge->_distance == 0)
            {
                same_positions[same_positions_used][0] = unused_targets[j];
                same_positions[same_positions_used][1] = unused_targets[i];
                same_positions_used++;
                if(i < unused_targets_size - 1)
                {
                    std::copy(unused_targets+i+1, unused_targets+unused_targets_size, unused_targets+i);
                }
                unused_targets_size--;
                break;
            }
        }
    }

    // Use first node
    std::copy(unused_targets+1, unused_targets+unused_targets_size, unused_targets);
    unused_targets_size--;

    // Dijkstras each target
    while(unused_targets_size > 0)
        dijkstras(total_path, total_path_used, total_distance, total_path[total_path_used-1], unused_targets, unused_targets_size);

    // Split Dijkstras
    // Count how many times src appears
    for(i = 1, j = 1; i < total_path_used; i++)
        if(total_path[0] == total_path[i])
            j++;

    int split_count = j;
    int splits[split_count][total_path_used];
    int splits_count[split_count];

    splits[0][0] = total_path[0];
    splits_count[0] = 1;
    for(i = 1, j = 0; i < total_path_used; i++)
    {
        // Handle new split
        if(total_path[i] == total_path[0])
        {
            j++;
            splits_count[j] = 1;
            splits[j][0] = total_path[0];
            continue;
        }

        splits[j][splits_count[j]] = total_path[i];
        splits_count[j]++;
    }

    // Remove tail, find last looping section of every split except last, remove all after
    for(i = 0; i < split_count - 1; i++)
    {
        for(j = splits_count[i] - 2; j >= 0; j--)
        {
            k = j - 1;
            l = j + 1;
            if(splits[i][k] == splits[i][l])
                break;
        }

        splits_count[i] -= splits_count[i] - l;
    }

    // Calculate distances
    int split_distances[split_count];
    for(i = 0; i < split_count; i++)
    {
        split_distances[i] = 0;
        for(j = 1; j < splits_count[i]; j++)
        {
            split_distances[i] += getedge(stadiums[splits[i][j-1]], stadiums[splits[i][j]])->_distance;
        }
    }

    // Calculate return cost and paths of nodes
    int return_paths[split_count][stadiums.size()];
    int return_paths_used[split_count];
    int return_distances[split_count];
    for(i = 0; i < split_count; i++)
    {
        unused_targets[0] = splits[i][0];
        unused_targets_size = 1;
        return_paths_used[i] = 0;
        return_distances[i] = 0;
        dijkstras(return_paths[i], return_paths_used[i], return_distances[i], splits[i][splits_count[i] - 1], unused_targets, unused_targets_size);
    }

    // Virtual map
    int split_map[split_count];
    for(i = 0; i < split_count; i++)
        split_map[i] = i;
    // Bubble sort map
    for(i = 0; i < split_count - 1; i++)
    {
        for(j = 0; j < split_count - i - 1; j++)
        {
            if((split_distances[split_map[j]] + return_distances[split_map[j]]) > (split_distances[split_map[j+1]] + return_distances[split_map[j+1]]))
            {
                k = split_map[j];
                split_map[j] = split_map[j+1];
                split_map[j+1] = k;
            }
        }
    }

    total_path_used = 0;
    total_distance = 0;
    // Recreate path
    for(i = 0; i < split_count - 1; i++)
    {
        // Go forward
        for(j = 0; j < splits_count[split_map[i]]; j++)
        {
            total_path[total_path_used++] = splits[split_map[i]][j];
        }
        total_distance += split_distances[split_map[i]];
        // Return to origin
        for(j = 0; j < return_paths_used[split_map[i]]-1; j++)
        {
            total_path[total_path_used++] = return_paths[split_map[i]][j];
        }
        total_distance += return_distances[split_map[i]];
    }
    // Go forward on final
    for(j = 0; j < splits_count[split_map[i]]; j++)
    {
        total_path[total_path_used++] = splits[split_map[i]][j];
    }
    total_distance += split_distances[split_map[i]];

    // Reinsert duplicate nodes, only once each
    for(i = 0; i < same_positions_used; i++)
    {
        for(j = 0; j < total_path_used; j++)
            if(same_positions[i][0] == total_path[j])
                break;

        if(j == total_path_used)
            continue;

        std::copy(total_path + j, total_path + total_path_used, total_path + j + 1);
        total_path[j+1] = same_positions[i][1];
        total_path_used++;
    }
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
 *                      int& path_used,
 *                      int& distance,
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
 *               int& path_used          // OUT - how many nodes
 *                                                visited
 *               int& distance           // OUT - total distance
 *               int src                 // IN - starting index
 *               int *unused_targets     // IN - index of unused
 *                                               targets
 *               int &unused_targets_size // IN - number of unused
 *                                               targets
 * --------------------------------------------------------------
 *   Return: none - parameters are updated after function is
 *                  executed
 ***************************************************************/
void graph::dijkstras(int *path,                    // IN/OUT - array to write to
                      int& path_used,               // OUT - how many nodes visited
                      int& distance,                // OUT - total distance
                      int src,                      // IN - starting index
                      int *unused_targets,          // IN - index of unused targets
                      int &unused_targets_size)     // IN - number of unused targets
{
    int max = stadiums.size();

    int i, j, k, l, u;
    int indices[max], distances[max];
    int costs[max][max];
    int paths[max][max];
    int paths_used[max];
    int min_index, min_distance;
    int prev_index;

    // Init Values
    for(i = 0; i < max; i++)
    {
        for(j = 0; j < max; j++)
            costs[i][j] = 0;
        for(j = 0; j < adjList[i].size(); j++)
        {
            int i1 = getIndex(adjList[i][j]._src);
            int i2 = getIndex(adjList[i][j]._des);
            costs[i1][i2] = adjList[i][j]._distance;
        }
    }

    // Get base index
    indices[0] = src;
    distances[0] = 0;

    for(i = 0; i < max; i++)
    {
      paths[i][0] = indices[0];
      paths_used[i] = 1;
    }

    // Main loop until full
    for(u = 1; u < max; u++)
    {
      min_distance = 0;
      // Loop through existing paths
      for(i = 0; i < u; i++)
      {
        // Loop through main indices
        for(j = 0; j < max; j++)
        {
          // Check if visited
          for(k = 0; k < u && j != indices[i] && j != indices[k]; k++);
          if(k < u)
            continue;

          // Get distance of previous index to current
          k = costs[indices[i]][j];
          if(k == 0)
            continue;

          // Check if min_distance set yet or new min distance exists
          if(k < min_distance || min_distance == 0)
          {
            prev_index = i;
            min_index = j;
            min_distance = k;
          }
          // Check node same distance, replace if node is target
          else if(k == min_distance)
          {
              for(l = 0; l < unused_targets_size; l++)
              {
                  if(unused_targets[l] == j && costs[unused_targets[l]][min_index] == 0)
                  {
                      min_index = j;
                      break;
                  }
              }
          }
        }
      }

      indices[u] = min_index;
      distances[u] = min_distance + distances[prev_index];

      paths_used[u] = paths_used[prev_index];
      std::copy(paths[prev_index], paths[prev_index]+paths_used[u], paths[u]);
      paths[u][paths_used[u]] = min_index;
      paths_used[u] += 1;
    }

    int min_i = -1;
    int min_j;
    for(i = 0; i < max; i++)
    {
        for(j = 0; j < unused_targets_size; j++)
          if(paths[i][paths_used[i]-1] == unused_targets[j])
              break;

        // Not in unused, continue
        if(j == unused_targets_size)
          continue;

        if(min_i == -1 || distances[i] < distances[min_i])
        {
            min_i = i;
            min_j = j;
        }
    }

    if(min_j < unused_targets_size - 1)
    {
        std::copy(unused_targets+min_j+1, unused_targets+unused_targets_size, unused_targets+min_j);
    }
    unused_targets_size--;

    for(i = 1; i < paths_used[min_i]; i++)
    {
        path[path_used++] = paths[min_i][i];
    }
    distance += distances[min_i];
}
