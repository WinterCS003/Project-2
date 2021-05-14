
#ifndef GRAPH_H
#define GRAPH_H
#include <cassert>
#include <vector>
#include "list.h"
#include "stadium.h"

struct stadiumNode{

    stadiumNode(){}
    stadiumNode(stadium des, int dist, bool visited = false){
        _des = des;
        _distance = dist;
        _visited = visited;
    }

    bool operator==(const stadium& s){
        if(_des == s){
            return true;
        }

        return false;
    }

    stadium _des;
    int _distance; // ATT - the distance to the source
    bool _visited; // ATT - if this stadium has been visited
};

class graph
{
public:

    friend class MainWindow;
    graph();
    ~graph();


    stadium getStadiumInfo(string stadiumName); // IN -  stadium name

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

    void removeEdge(stadiumNode toRemove);        // IN - nm of stadium to rem

    void removeStadium(stadium toRemove);       // IN - nm of stadium to rem


private:


    List<stadium> sort(string LeagueType = "all",   // IN - sort by league
                       bool grassSurface = false,   // IN - sort by surface
                       bool byTeamName = false,     // IN - sort by team name
                       bool byDate = false);        // IN - sort by open date


    int getLength(List<stadiumNode>);

    List<stadium> stadiums;             // ATT - list of stadiums
    List<stadiumNode>* adjList;   // ATT - list of edges
    int _capacity;
    int _size;                          // ATT - total # of stadiums
};

#endif // GRAPH_H
