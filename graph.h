
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
    /**********************************
     ** CONSTRUCTORS AND DESTRUCTORS **
     **********************************/
    friend class MainWindow;
    graph();
    ~graph();

    /***************
     ** ACCESSORS **
     ***************/
    stadium getStadiumInfo(stadium s) const; // IN -  stadium name

    stadiumNode * getedge(stadium stadiumSrc,  // IN -  stadium source name
                        stadium stadiumDes); // IN -  stadium destination name

    List<stadiumNode> getedges(stadium stadiumSrc); // IN -  stadium source name

    void printGraph() const {
        for(node<stadium>* curr = stadiums.Begin(); curr != nullptr; curr = curr->_next){
            std::cout << curr->_data.getAllInfo() << std::endl;
        }
    }

    void getShortestTripPath(int *total_path,
                             int& total_path_used,
                             List<stadium>& targets,
                             int& total_distance);

    int getIndex(stadium& target); // get target index in master list

    void dijkstras(int *path,           // IN/OUT - array to write to
                   int& nodes_visited,  // OUT - how many nodes visited
                   int& distance,       // OUT - total distance
                   int src,             // IN - starting index
                   int *unused_targets,
                   int unused_targets_size); // IN - ending index

    List<stadium> getAmericanLeagueStadiums();

    List<stadium> getNationalLeagueStadiums();

    List<stadium> getStadiumWithGrassField();

    int getSize() const { return _size; };

    stadium * getStadiumByName(string name);

    /**************
     ** MUTATORS **
     **************/

    void addStadium(stadium s); // IN -  stadium to add to list

    void addEdge(stadium src,        // IN -  stadium source to add
                 stadium des,        // IN -  stadium desintaton to add
                 int distance);     // IN -  distance between


    void removeEdge(stadium src, stadium des);        // IN - nm of stadium to rem

    void removeStadium(stadium toRemove);       // IN - nm of stadium to rem


private:
    List<stadium> stadiums;             // ATT - list of stadiums
    List<List<stadiumNode>> adjList;   // ATT - list of edges
    int _size;                          // ATT - total # of stadiums
};

/****************************************************************
 * graph Class
 *   This class represents a graph object. It manages 3
 *   attributes: stadiums, _size and adjList (all edges
 *   connecting stadiums)
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * graph();
 *   Constructor; Initializes an empty class
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~graph();
 *   Destructor; Frees all memory used by the stadiums and
 *               adjacency list.
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

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

/****************************************************************
<<<<<<< HEAD
 * stadiumNode * getedge(stadium stadiumSrc,
=======
 * stadiumNode getedge(stadium stadiumSrc,
>>>>>>> 5ad8f4e07e00f49803f02109ead3266982c3caeb
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
=======
 *   Return: stadiumNode - returns edge connecting given stadiums.
>>>>>>> 5ad8f4e07e00f49803f02109ead3266982c3caeb
 ***************************************************************/

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

/****************************************************************
 * void printGraph() const;
 *
 *   Accessor; This method will return the information of all
 *             stadiums found in the graph.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - information is printed to screen
 ***************************************************************/

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

/****************************************************************
 * int getSize() const;
 *
 *   Accessor; This method will return the size of the graph,
 *             number of stadiums
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _size (int) - number of stadiums in graph
 ***************************************************************/

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


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void addStadium(stadium s);
 *
 *   Mutator; This method will add the given stadium into the graph
 *------------------------------------------------------------------
 *   Parameter: s (stadium) // IN – new stadium to add
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

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


#endif // GRAPH_H
