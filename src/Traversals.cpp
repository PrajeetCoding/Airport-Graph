#include "Traversals.h"
#include <algorithm>
#include <float.h>
#include <limits>
#include <unordered_set>



using namespace std;
using namespace Utility;
using namespace CSVParser;


Vertex Traversals::convertNameToID(string name) {
    return g_.getID(name);
}

Traversals::Traversals(string nodes_path, string edges_path) {
    g_ = Graph(nodes_path, edges_path);
}

string Traversals::convertIDToName(Vertex v) {
    return g_.getName(v);
}

Vertex Traversals::moreImportant(Vertex first, Vertex second) {

    if (!g_.vertexExists(first) || !g_.vertexExists(second)) {
        cout << endl;
        cout << "INVALID AIRPORT(S) GIVEN" << endl;
        cout << endl;
        return "";
    }

    int sample = 100;
    if (g_.getNumVertices() < 100) sample = g_.getNumVertices() - 1;

    int first_centrality = centralityApproximation(first, sample);
    int second_centrality = centralityApproximation(second, sample);

    return first_centrality > second_centrality ? first : second;
}


vector<Vertex> Traversals::BFS(Vertex start, Vertex end) {
    
    vector<Vertex> path;
    
    // hashset for O(1) determining if node has been visited or not

    unordered_set<Vertex> visited;
    
    queue<Vertex> next;

    unordered_map<Vertex, Vertex> prev;

    if (!g_.vertexExists(start) || !g_.vertexExists(end)) {
        cout << endl;
        cout << "INVALID START OR ENDING AIRPORT" << endl;
        cout << endl;
        return path;
    }
    

    next.push(start);
    visited.insert(start);
    
    bool found_end = 0;

    while(!next.empty()) {
        Vertex current = next.front();
        next.pop();
        
        if (current == end) {
            found_end = 1;
            break;
        }

        for (Edge e : g_.getAdjacent(current)) {
            if (visited.find(e.dest) == visited.end()) {
                next.push(e.dest);
                visited.insert(e.dest);
                prev[e.dest] = current;
            }
        }
    }

    // THIS statement is for the case in which there is NO route from start to end, thus we return an empty vector
    if (!found_end) {
        return path;
    }

    // backtracking to create our list of airports/the path we need to take to get to end

    Vertex v = end;
    while (prev.find(v) != prev.end()) {
        path.insert(path.begin(), v);
        v = prev.at(v);
    }
    path.insert(path.begin(), start);



    return path;
}
// Djikstras's algorithm
vector<Vertex> Traversals::shortestPath(Vertex start, Vertex end) {
    
    vector<Vertex> path;
    
    unordered_map<Vertex, double> distance;

    unordered_map<Vertex, Vertex> previous;

    // hashset for O(1) determining if node has been visited or not

    unordered_set<Vertex> visited;

    //priority_queue setup:

    //lambda function that determines how two vertex-distance pairs should be compared, this comparator creates a minheap
    auto comparator = [](pair<Vertex, double> x, pair<Vertex, double> y) { return x.second > y.second; };

    // this priority_queue is implemented using a heap, and it uses the comparator lamda function to determine priority of the
    // values in the heap

    priority_queue<pair<Vertex, double>, vector<pair<Vertex, double>>, decltype(comparator)> next(comparator);

    vector<Vertex> all_vertices = g_.getVertices();

    for (Vertex v : all_vertices) {
        distance[v] = numeric_limits<double>::max();
    }

    if (!g_.vertexExists(start) || !g_.vertexExists(end)) {
        cout << endl;
        cout << "INVALID START OR ENDING AIRPORT" << endl;
        cout << endl;
        return path;
    }

    distance[start] = 0;
    next.push(pair<Vertex, double>(start, 0));
    visited.insert(start);
    bool found_end = 0;

    while (!next.empty()) {
        pair<Vertex, double> current = next.top();
        next.pop();
        if (current.first == end) {
            found_end = 1;
            break;
        }
        for (Edge e : g_.getAdjacent(current.first)) {
            if (visited.find(e.dest) == visited.end() && (distance.at(current.first) + e.weight) < distance.at(e.dest)) {
                next.push(pair<Vertex, double>(e.dest, distance.at(current.first) + e.weight));
                previous[e.dest] = current.first;
                distance[e.dest] = distance.at(current.first) + e.weight;
            }
        }
        visited.insert(current.first);
    }


    // THIS statement is for the case in which there is NO route from start to end, thus we return an empty vector

    if (!found_end) return path;
    
     // backtracking to create our list of airports/the path we need to take to get to end
    Vertex v = end;
    while (previous.find(v) != previous.end()) {
        path.insert(path.begin(), v);
        v = previous.at(v);
    }
    path.insert(path.begin(), start);
    return path;

}






vector<Vertex> Traversals::topAirports(int n, bool approx, size_t subset_size) {

    
    
    vector<pair<Vertex, int>> airport_to_centrality;
    
    vector<Vertex> airports;

    vector<Vertex> vertices = g_.getVertices();

    if (n < 0) n = 0;
    if (n > (int) vertices.size()) n = (int) vertices.size();

    // this comparator creates a maxHeap

    auto comparator = [](pair<Vertex, int> x, pair<Vertex, int> y) { return x.second < y.second; };

    priority_queue<pair<Vertex, int>, vector<pair<Vertex, int>>, decltype(comparator)> sorter(comparator);

    if (approx) {
        int current = 1;
        for (Vertex v : vertices) {
            pair<Vertex, int> add;
            add.first = v;

            cout << "CURRENTLY CALCULATING CENTRALITY FOR AIRPORT NUMBER " << current << "..." << endl;

            add.second = centralityApproximation(v, subset_size);

            current++;

            sorter.push(add);
        }

        for (int i = 0; i < n; i++) {
            airports.push_back(sorter.top().first);
            sorter.pop();
        }


    } else {
        int current = 1;

        for (Vertex v : vertices) {
            pair<Vertex, int> add;
            add.first = v;

            cout << "CURRENTLY CALCULATING CENTRALITY FOR AIRPORT NUMBER " << current << "..." << endl;

            add.second = centrality(v);

            current++;

            sorter.push(add);
        }
        for (int i = 0; i < n; i++) {
            airports.push_back(sorter.top().first);
            sorter.pop();
        }

    }
    return airports;
}


int Traversals::centrality(Vertex v) {

    if (!g_.vertexExists(v)) {
        cout << endl;
        cout << "INVALID AIRPORT, TRY AGAIN" << endl;
        cout << endl;
        return -1; 
    }
    
    vector<Vertex> vertices = g_.getVertices();

    int centrality = 0;

    unordered_set<string> paths_seen;

    for (Vertex vert : vertices) {
        centrality += djikstraAccumulation(vert, v, paths_seen);
    }
    return centrality;


}



int Traversals::centralityApproximation(Vertex v, size_t sample_size) {

    if (!g_.vertexExists(v)) {
        
        cout << endl;
        cout << "INVALID AIRPORT, TRY AGAIN" << endl;
        cout << endl;

        return -1;
    }

    vector<Vertex> vertices = g_.getVertices();

    if (sample_size >= vertices.size()) sample_size = vertices.size() - 1;

    // we use an unordered_set here to avoid adding duplicate vertices

    unordered_set<Vertex> subset;

    unordered_set<string> paths_seen;

    // populating the subset

    while (subset.size() < sample_size) {
        int random_index = rand() % (int) vertices.size();
        Vertex random_vertex = vertices[random_index];
        if (random_vertex == v) continue;
        subset.insert(random_vertex);
    }
    
    
    int centrality = 0;
    for (Vertex vert : subset) {
        centrality += djikstraAccumulation(vert, v, paths_seen);
    }


    return centrality;
}


int Traversals::printPath(vector<Vertex> path) {

    if (path.empty()) {
        cout << endl;
        cout << "NO ROUTE EXISTS" << endl;
        cout << endl;
        return -1;
    }

    
    cout << endl;

    double total_distance = 0;
    
    // This calculates the total distance traveled over the path

    for (size_t i = 0; i < path.size() - 1; i++) {
        Vertex current = path[i];
        Vertex next = path[i + 1];
        for (Edge e : g_.getAdjacent(current)) {
            if (e.dest == next) {
                total_distance += e.weight;
                break;
            }
        }
    }
    cout << "TOTAL DISTANCE TRAVELED: " << total_distance << " KM" << endl;
    
    cout << endl;

    // this prints out the path in a readable fashion

    unsigned index = 0;
    for (Vertex v : path) {
        if (index == path.size() - 1) {
            cout << g_.getName(v) << endl;
        } else {
            cout << g_.getName(v) << " ---> ";
        }
        index++;
    }
    
    cout << endl;

    return total_distance;
}





/* HELPER FUNCTIONS */


int Traversals::djikstraAccumulation(Vertex start, Vertex search, unordered_set<string>& seen) {

    if (g_.getAdjacent(start).empty()) return 0;
    
    unordered_map<Vertex, double> distance;

    unordered_map<Vertex, Vertex> previous;

    // hashset for O(1) determining if node has been visited or not

    unordered_set<Vertex> visited;

    //priority_queue setup:

    //lambda function that determines how two vertex-distance pairs should be compared
    auto comparator = [](pair<Vertex, double> x, pair<Vertex, double> y) { return x.second > y.second; };

    // this priority_queue is implemented using a heap, and it uses the comparator lamda function to determine priority of the
    // values in the heap

    priority_queue<pair<Vertex, double>, vector<pair<Vertex, double>>, decltype(comparator)> next(comparator);

    vector<Vertex> all_vertices = g_.getVertices();

    for (Vertex v : all_vertices) {
        distance[v] = numeric_limits<double>::max();
    }

    distance[start] = 0;
    next.push(pair<Vertex, double>(start, 0));
    visited.insert(start);
    bool found_end = 0;

    while (!next.empty()) {
        pair<Vertex, double> current = next.top();
        next.pop();
        for (Edge e : g_.getAdjacent(current.first)) {
            if (visited.find(e.dest) == visited.end() && (distance.at(current.first) + e.weight) < distance.at(e.dest)) {
                next.push(pair<Vertex, double>(e.dest, distance.at(current.first) + e.weight));
                previous[e.dest] = current.first;
                distance[e.dest] = distance.at(current.first) + e.weight;
            }
        }
        visited.insert(current.first);
    }
    
    
    int acculmulate = 0;

    // go through every shortest path that starts at vertex start and see if that path contains search
    // if it does, then we update accumulate by 1, acculumate is the total number of shortest paths that contain search

    for (pair<Vertex, Vertex> p : previous) {
        if (p.first == search) continue;
        Vertex v = p.first;
        

        string encoded_path = start + "$" + v;

        if (seen.find(encoded_path) != seen.end()) continue;
        
        seen.insert(encoded_path);

        while (previous.find(v) != previous.end()) {
            if (v == search) {
                acculmulate++;
                break;
            }
            v = previous.at(v);
        }
    }
    return acculmulate;
}



