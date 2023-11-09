#include "Graph.h"
#include "Utility.h"
#include "CSVParser.h"
#include <string>
#include <unordered_set>

using namespace std;
using namespace Utility;
using namespace CSVParser;

class Traversals {
    public:

        // Constructor for Traversals class. It is solely used to populate the graph g_

        Traversals(string nodes_path, string edges_path);

        // BFS algorithm to find a path (not necessarily the shortest) between two airports

        vector<Vertex> BFS(Vertex start, Vertex end);

        // Djikstra's algorithm to find the shortest path between two airports

        vector<Vertex> shortestPath(Vertex start, Vertex end);

        // retrieves the top n most important / central airports in the world
        // if approx is true, then it returns a approximation of what the most important airports might be, subset size is the size of the
        // sample used
        // NOTE: FUNCTION IS EXTREMELY, EXTREMELY SLOW
        vector<Vertex> topAirports(int n, bool approx, size_t subset_size);

        // prints out the path of airports in a readable fashion
        // this function also returns the total distance traveled along the path

        int printPath(vector<Vertex> path);

        // calculates the centrality value for a node v. This is used in topAirports 
        // where the most important airports are the most "central" in the graph or have
        // been "crossed over" the most times over all shortest paths between two nodes

        int centrality(Vertex v);

        // calculates an approximation for the centrality of a node. This function exists because
        // an exact centrality calcualation is extremely slow. This algorithm uses a random subset of vertices to calulate
        // centrality. sample_size is the size of the random sample used. A higher sample size increases the accuracy of the approximation.

        int centralityApproximation(Vertex v, size_t sample_size);


        // function that just converts the name of the airport to its corresponding ID, this is just used to the main function
        // to convert the user's input to a format that the traversals class can use

        Vertex convertNameToID(string name);

        // function that just converts the id of the airport to its corresponding name, this is just used to the main function
        // to convert the output to a understandable format for the user 

        string convertIDToName(Vertex v);

        // this uses centrality values to return which of the two airports, first or second, are the most important
        // this uses a random sample of 100 points to calculate centrality, which enough for this particular dataset to determine which is the most important.
        Vertex moreImportant(Vertex first, Vertex second);

    private:
        
        
        
        // this function counts the total amount of shortest paths that cross the vertex search
        // used as an intermediate step in centrality calculations

        int djikstraAccumulation(Vertex start, Vertex search, unordered_set<string>& seen);



        Graph g_;

};

