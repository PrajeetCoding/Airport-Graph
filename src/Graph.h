//THIS IS THE GRAPH DS WE WILL USE TO STORE OUR AIRPORTS
#include "CSVParser.h"
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include "Edge.h"
#pragma once
using namespace std;
using namespace CSVParser;

class Graph {
    public:
        Graph() = default;

        Graph(string nodes_path, string edges_path);

        // returns every edge that directs out of the node v. It essentially returns the list associated with v in the unordered
        // map
        
        list<Edge> getAdjacent(Vertex v);
        
        // getter for num_vertices

        unsigned getNumVertices();
        
        // getter for num_edges

        unsigned getNumEdges();

        //converts an airports id to its corresponding name
        //this is mainly used in the printPath function
        
        string getName(Vertex v);

        // returns a vector of every vertex/airport in the graph
        
        vector<Vertex> getVertices();

        // returns true if and only if the vertex/aiport v exists in the graph

        bool vertexExists(Vertex v);

        // converts an airports name to its id
        // this is mainly used in the main method to convert a user's input into a readable vertex.
        
        Vertex getID(string name);

        

    private:
        
        // this is the adjacency list for our graph
        unordered_map<Vertex, list<Edge>> adj_list;

        
        // we map airport ID to its location in terms of latitude and longitude. This is used solely for edge creation.

        unordered_map<Vertex, pair<double, double>> coord_list;
        
        // these are used to go back and forth from name to id
        unordered_map<Vertex, string> id_to_name;

        unordered_map<string, Vertex> name_to_id;
        
        // we store the number of vertices and number of edges just in case we need to use them

        unsigned num_vertices = 0;

        unsigned num_edges = 0;
};