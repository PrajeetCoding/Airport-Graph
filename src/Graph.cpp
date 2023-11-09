#include "Graph.h"
#include "Utility.h"
using namespace std;
using namespace CSVParser;
using namespace Utility;



Graph::Graph(string nodes_path, string edges_path) {
    
    // retrive data from routes.csv and airports.csv

    vector<vector<string>> nodes = parse_data(nodes_path);
    vector<vector<string>> edges = parse_data(edges_path);
    
    int count_nodes = 0;

    for (auto line : nodes) {
        adj_list[line[4]] = list<Edge>();
        coord_list[line[4]] = pair<double, double>(stod(line[6]), stod(line[7]));
        id_to_name[line[4]] = line[1];
        name_to_id[line[1]] = line[4];
        count_nodes++;
    }

    int count_edges = 0;

    for (auto line : edges) {
        Edge add;

        // retrieve the source and dest ids
        add.source = line[2];
        add.dest = line[4];

        /* sometimes we run into an issue with "NULL" edges, in that case
            we skip over them
        */

        if (coord_list.find(add.source) == coord_list.end() || coord_list.find(add.dest) == coord_list.end()) continue;
        
        add.weight = distance(coord_list.at(add.source), coord_list.at(add.dest));
        
        adj_list[add.source].push_back(add);
        
        count_edges++;

    }
    num_edges = count_edges;
    num_vertices = count_nodes;
}

string Graph::getName(Vertex v) {
    if (id_to_name.find(v) == id_to_name.end()) return "ID NOT FOUND";
    return id_to_name.at(v);
}

Vertex Graph::getID(string name) {
    if (name_to_id.find(name) == name_to_id.end()) return "NAME NOT FOUND";
    return name_to_id.at(name);
}

bool Graph::vertexExists(Vertex v) {
    return adj_list.find(v) != adj_list.end();
}

list<Edge> Graph::getAdjacent(Vertex v) {
    return adj_list.at(v);
}
unsigned Graph::getNumVertices() {
    return num_vertices;
}
unsigned Graph::getNumEdges() {
    return num_edges;
}

vector<Vertex> Graph::getVertices() {
    vector<Vertex> vertices_;
    for (auto pair : adj_list) {
        vertices_.push_back(pair.first);
    }
    return vertices_;
}


