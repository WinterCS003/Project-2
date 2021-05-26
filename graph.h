
#ifndef GRAPH_H
#define GRAPH_H
#include <cassert>
#include <vector>
#include "list.h"
#include "stadium.h"

struct stadiumNode{

    stadiumNode(){}
    stadiumNode(stadium src, stadium des, int dist, bool visited = false){
        _src = src;
        _des = des;
        _distance = dist;
        _visited = visited;
    }

    bool operator==(const stadiumNode& s){
        if(_src == s._src && _des == s._des && _distance == s._distance){
            return true;
        }

        return false;
    }

    stadium _des;
    stadium _src;
    int _distance; // ATT - the distance to the source
    bool _visited; // ATT - if this stadium has been visited
};

class graph
{
public:

    friend class MainWindow;
    graph();
    ~graph();


    stadium getStadiumInfo(stadium s); // IN -  stadium name

    stadiumNode getedge(stadium stadiumSrc, // IN -  stadium source name
                        stadium stadiumDes);// IN -  stadium destination name

    List<stadiumNode> getedges(stadium stadiumSrc); // IN -  stadium source name


    void addStadium(stadium s); // IN -  stadium to add to list

    void addEdge(stadium src,        // IN -  stadium source to add
                 stadium des,        // IN -  stadium desintaton to add
                 int distance);     // IN -  distance between


    List<stadium> getAmericanLeagueStadiums();

    List<stadium> getNationalLeagueStadiums();

    List<stadium> getStadiumWithGrassField();

    List<stadium> getStadiumListForDijkstras();

    int getSize();

    stadium * getStadiumByName(string name);

    List<stadiumNode> shortestPath(string src,  // IN -  stadium source name
                                   string des,  // IN -  stadium destin name
        const List<stadium>& = List<stadium>());// IN -  list to visit

    List<stadiumNode> shortestPath(const List<stadium>&,// IN -  list to visit
                                   string src);         // IN -  stadium to strt




    stadiumNode getDistance(string des,     // IN - destination
                const List<stadiumNode>&);  // IN - list of nodes visited

    void checkSingleVertex(List<stadiumNode>& getsReturned, // IN -  list to chk
                           string src);                     // IN -  source std

    void dijkstras(List<stadiumNode>& getsReturned,  // IN -  stadium connection
                   List<stadiumNode> edges);         // IN - used to cal path

    bool allVisited(const List<stadiumNode>&);  // IN -  list to check

    bool allVisited(const List<stadiumNode>&,   // IN -  list to check against
                    const List<stadium>&);      // IN -  list to check

    bool checkVisited(const List<stadiumNode>& me,// IN -  list to check
                      string des);                // IN -  stadium name to check

    stadiumNode shortestTotalDistance
            (const List<stadiumNode>&);// IN - list with distances

    stadiumNode shortestTotalDistance
        (const List<stadiumNode>& result_dijkstras, // IN -  previous alg result
                    const List<stadium>& toVisit,   // IN - stadiums to visit
                const List<stadiumNode>& visited);  // IN - stadiums visited

    void initForShortestPath(const List<stadium>&, // IN - stadiums to visit
                             List<stadiumNode>&,   // IN - init this
                             string src);          // IN - start here

    bool checkExist(const List<stadiumNode>&, // IN - check this list
                    string toCheck);          // IN - if this exits

    void removeEdge(stadium src, stadium des);        // IN - nm of stadium to rem

    void removeStadium(stadium toRemove);       // IN - nm of stadium to rem
    void printGraph(){
        for(node<stadium>* curr = stadiums.Begin(); curr != nullptr; curr = curr->_next){
            std::cout << curr->_data.getAllInfo() << std::endl;
        }
    }

    void getShortestTripPath(int *total_path, int& total_path_used, List<stadium>& targets);

    int getIndex(stadium& target);  // get target index in master list

    void dijkstras(int *path,           // IN/OUT - array to write to
                   int& nodes_visited,  // OUT - how many nodes visited
                   int& distance,       // OUT - total distance
                   int src,             // IN - starting index
                   int *unused_targets, int unused_targets_size);           // IN - ending index


private:


    List<stadium> sort(string LeagueType = "all",   // IN - sort by league
                       bool grassSurface = false,   // IN - sort by surface
                       bool byTeamName = false,     // IN - sort by team name
                       bool byDate = false);        // IN - sort by open date


    int getLength(List<stadiumNode>);

    List<stadium> stadiums;             // ATT - list of stadiums
    List<List<stadiumNode>> adjList;   // ATT - list of edges
    int _size;                          // ATT - total # of stadiums
};

#endif // GRAPH_H
